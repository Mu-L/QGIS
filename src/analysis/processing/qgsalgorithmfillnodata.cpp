/***************************************************************************
                         qgsalgorithmfillnodata.cpp
                         ---------------------
    begin                : January 2020
    copyright            : (C) 2020 by Clemens Raffler
    email                : clemens dot raffler at gmail dot com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "qgsalgorithmfillnodata.h"
#include "qgsrasterfilewriter.h"

///@cond PRIVATE

QString QgsFillNoDataAlgorithm::name() const
{
  return QStringLiteral( "fillnodata" );
}

QString QgsFillNoDataAlgorithm::displayName() const
{
  return QObject::tr( "Fill NoData cells" );
}

QStringList QgsFillNoDataAlgorithm::tags() const
{
  return QObject::tr( "data,cells,fill,set" ).split( ',' );
}

QString QgsFillNoDataAlgorithm::group() const
{
  return QObject::tr( "Raster tools" );
}

QString QgsFillNoDataAlgorithm::groupId() const
{
  return QStringLiteral( "rastertools" );
}

void QgsFillNoDataAlgorithm::initAlgorithm( const QVariantMap & )
{
  addParameter( new QgsProcessingParameterRasterLayer( QStringLiteral( "INPUT" ), QStringLiteral( "Raster input" ) ) );
  addParameter( new QgsProcessingParameterBand( QStringLiteral( "BAND" ), QObject::tr( "Band Number" ), 1, QStringLiteral( "INPUT" ) ) );
  addParameter( new QgsProcessingParameterNumber( QStringLiteral( "FILL_VALUE" ), QObject::tr( "Fill value" ), Qgis::ProcessingNumberParameterType::Double, 1, false ) );

  // backwards compatibility parameter
  // TODO QGIS 4: remove parameter and related logic
  auto createOptsParam = std::make_unique<QgsProcessingParameterString>( QStringLiteral( "CREATE_OPTIONS" ), QObject::tr( "Creation options" ), QVariant(), false, true );
  createOptsParam->setMetadata( QVariantMap( { { QStringLiteral( "widget_wrapper" ), QVariantMap( { { QStringLiteral( "widget_type" ), QStringLiteral( "rasteroptions" ) } } ) } } ) );
  createOptsParam->setFlags( createOptsParam->flags() | Qgis::ProcessingParameterFlag::Hidden );
  addParameter( createOptsParam.release() );

  auto creationOptsParam = std::make_unique<QgsProcessingParameterString>( QStringLiteral( "CREATION_OPTIONS" ), QObject::tr( "Creation options" ), QVariant(), false, true );
  creationOptsParam->setMetadata( QVariantMap( { { QStringLiteral( "widget_wrapper" ), QVariantMap( { { QStringLiteral( "widget_type" ), QStringLiteral( "rasteroptions" ) } } ) } } ) );
  creationOptsParam->setFlags( creationOptsParam->flags() | Qgis::ProcessingParameterFlag::Advanced );
  addParameter( creationOptsParam.release() );

  addParameter( new QgsProcessingParameterRasterDestination( QStringLiteral( "OUTPUT" ), QObject::tr( "Output raster" ) ) );
}

QString QgsFillNoDataAlgorithm::shortHelpString() const
{
  return QObject::tr( "This algorithm resets the NoData values in the input raster "
                      "to a chosen value, resulting in a raster dataset with no NoData pixels. "
                      "This value can be set by the user using the Fill value parameter. "
                      "The algorithm respects the input raster data type (eg. a floating point fill value will be truncated "
                      "when applied to an integer raster)." );
}

QString QgsFillNoDataAlgorithm::shortDescription() const
{
  return QObject::tr( "Generates a raster dataset with the NoData values in the input raster filled with a given value." );
}

QgsFillNoDataAlgorithm *QgsFillNoDataAlgorithm::createInstance() const
{
  return new QgsFillNoDataAlgorithm();
}

bool QgsFillNoDataAlgorithm::prepareAlgorithm( const QVariantMap &parameters, QgsProcessingContext &context, QgsProcessingFeedback *feedback )
{
  Q_UNUSED( feedback );
  mInputRaster = parameterAsRasterLayer( parameters, QStringLiteral( "INPUT" ), context );
  mFillValue = parameterAsDouble( parameters, QStringLiteral( "FILL_VALUE" ), context );

  if ( !mInputRaster )
    throw QgsProcessingException( invalidRasterError( parameters, QStringLiteral( "INPUT" ) ) );

  mBand = parameterAsInt( parameters, QStringLiteral( "BAND" ), context );
  if ( mBand < 1 || mBand > mInputRaster->bandCount() )
    throw QgsProcessingException( QObject::tr( "Invalid band number for BAND (%1): Valid values for input raster are 1 to %2" ).arg( mBand ).arg( mInputRaster->bandCount() ) );

  mInterface.reset( mInputRaster->dataProvider()->clone() );
  mInputNoDataValue = mInputRaster->dataProvider()->sourceNoDataValue( mBand );
  mExtent = mInputRaster->extent();
  mLayerWidth = mInputRaster->width();
  mLayerHeight = mInputRaster->height();
  mCrs = mInputRaster->crs();
  mNbCellsXProvider = mInterface->xSize();
  mNbCellsYProvider = mInterface->ySize();
  return true;
}

QVariantMap QgsFillNoDataAlgorithm::processAlgorithm( const QVariantMap &parameters, QgsProcessingContext &context, QgsProcessingFeedback *feedback )
{
  //test if input dataset has NoData
  if ( !mInputRaster->dataProvider()->sourceHasNoDataValue( mBand ) )
    feedback->reportError( QObject::tr( "Input raster has no NoData values. There exist no NoData cells to fill." ), false );

  //prepare output dataset
  QString creationOptions = parameterAsString( parameters, QStringLiteral( "CREATION_OPTIONS" ), context ).trimmed();
  // handle backwards compatibility parameter CREATE_OPTIONS
  const QString optionsString = parameterAsString( parameters, QStringLiteral( "CREATE_OPTIONS" ), context );
  if ( !optionsString.isEmpty() )
    creationOptions = optionsString;

  const QString outputFile = parameterAsOutputLayer( parameters, QStringLiteral( "OUTPUT" ), context );
  const QFileInfo fi( outputFile );
  const QString outputFormat = QgsRasterFileWriter::driverForExtension( fi.suffix() );
  auto writer = std::make_unique<QgsRasterFileWriter>( outputFile );
  writer->setOutputProviderKey( QStringLiteral( "gdal" ) );
  if ( !creationOptions.isEmpty() )
  {
    writer->setCreationOptions( creationOptions.split( '|' ) );
  }
  writer->setOutputFormat( outputFormat );
  std::unique_ptr<QgsRasterDataProvider> provider( writer->createOneBandRaster( mInterface->dataType( mBand ), mNbCellsXProvider, mNbCellsYProvider, mExtent, mCrs ) );
  if ( !provider )
    throw QgsProcessingException( QObject::tr( "Could not create raster output: %1" ).arg( outputFile ) );
  if ( !provider->isValid() )
    throw QgsProcessingException( QObject::tr( "Could not create raster output %1: %2" ).arg( outputFile, provider->error().message( QgsErrorMessage::Text ) ) );

  //prepare output provider
  QgsRasterDataProvider *destinationRasterProvider;
  destinationRasterProvider = provider.get();
  destinationRasterProvider->setEditable( true );

  const int maxWidth = QgsRasterIterator::DEFAULT_MAXIMUM_TILE_WIDTH;
  const int maxHeight = QgsRasterIterator::DEFAULT_MAXIMUM_TILE_HEIGHT;
  const int nbBlocksWidth = static_cast<int>( std::ceil( 1.0 * mLayerWidth / maxWidth ) );
  const int nbBlocksHeight = static_cast<int>( std::ceil( 1.0 * mLayerHeight / maxHeight ) );
  const int nbBlocks = nbBlocksWidth * nbBlocksHeight;

  QgsRasterIterator iter( mInterface.get() );
  iter.startRasterRead( mBand, mLayerWidth, mLayerHeight, mExtent );
  int iterLeft = 0;
  int iterTop = 0;
  int iterCols = 0;
  int iterRows = 0;
  std::unique_ptr<QgsRasterBlock> filledRasterBlock;
  while ( iter.readNextRasterPart( mBand, iterCols, iterRows, filledRasterBlock, iterLeft, iterTop ) )
  {
    if ( feedback )
      feedback->setProgress( 100 * ( ( iterTop / maxHeight * nbBlocksWidth ) + iterLeft / maxWidth ) / nbBlocks );

    if ( feedback && feedback->isCanceled() )
      break;

    if ( !filledRasterBlock->hasNoDataValue() )
    {
      if ( !destinationRasterProvider->writeBlock( filledRasterBlock.get(), mBand, iterLeft, iterTop ) )
      {
        throw QgsProcessingException( QObject::tr( "Could not write raster block: %1" ).arg( destinationRasterProvider->error().summary() ) );
      }
      continue;
    }

    for ( int row = 0; row < iterRows; row++ )
    {
      if ( feedback && feedback->isCanceled() )
        break;
      for ( int column = 0; column < iterCols; column++ )
      {
        if ( filledRasterBlock->isNoData( row, column ) )
          filledRasterBlock->setValue( row, column, mFillValue );
      }
    }
    if ( !destinationRasterProvider->writeBlock( filledRasterBlock.get(), mBand, iterLeft, iterTop ) )
    {
      throw QgsProcessingException( QObject::tr( "Could not write raster block: %1" ).arg( destinationRasterProvider->error().summary() ) );
    }
  }
  destinationRasterProvider->setEditable( false );

  QVariantMap outputs;
  outputs.insert( QStringLiteral( "OUTPUT" ), outputFile );
  return outputs;
}

///@endcond
