/***************************************************************************
                         qgsalgorithmpdalthinbyradius.h
                         ---------------------
    begin                : February 2023
    copyright            : (C) 2023 by Alexander Bruy
    email                : alexander dot bruy at gmail dot com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSALGORITHMPDALTHINBYDECIMATE_H
#define QGSALGORITHMPDALTHINBYDECIMATE_H

#define SIP_NO_FILE

#include "qgis_sip.h"
#include "qgspdalalgorithmbase.h"

///@cond PRIVATE

/**
 * Native point cloud thin by decimation (skipping points).
 */
class QgsPdalThinByDecimateAlgorithm : public QgsPdalAlgorithmBase
{
  public:
    QgsPdalThinByDecimateAlgorithm() = default;
    void initAlgorithm( const QVariantMap &configuration = QVariantMap() ) override;
    QString name() const override;
    QString displayName() const override;
    QString group() const override;
    QString groupId() const override;
    QStringList tags() const override;
    QString shortHelpString() const override;
    QgsPdalThinByDecimateAlgorithm *createInstance() const override SIP_FACTORY;

    QStringList createArgumentLists( const QVariantMap &parameters, QgsProcessingContext &context, QgsProcessingFeedback *feedback ) override;

    friend class TestQgsProcessingPdalAlgs;
};

///@endcond PRIVATE

#endif // QGSALGORITHMPDALTHINBYDECIMATE_H
