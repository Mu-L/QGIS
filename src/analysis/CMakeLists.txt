#############################################################
# sources

BISON_TARGET(QgsRasterCalcParser raster/qgsrastercalcparser.yy ${CMAKE_CURRENT_BINARY_DIR}/qgsrastercalcparser.cpp COMPILE_FLAGS "-p raster_")
FLEX_TARGET(QgsRasterCalcLexer raster/qgsrastercalclexer.ll ${CMAKE_CURRENT_BINARY_DIR}/qgsrastercalclexer.cpp)
ADD_FLEX_BISON_DEPENDENCY(QgsRasterCalcLexer QgsRasterCalcParser)

set(QGIS_ANALYSIS_SRCS
  qgsanalysis.cpp

  ${FLEX_QgsRasterCalcLexer_OUTPUTS}
  ${BISON_QgsRasterCalcParser_OUTPUTS}

  georeferencing/qgsgcpgeometrytransformer.cpp
  georeferencing/qgsgcppoint.cpp
  georeferencing/qgsgcptransformer.cpp
  georeferencing/qgsleastsquares.cpp
  georeferencing/qgsvectorwarper.cpp

  interpolation/qgsgridfilewriter.cpp
  interpolation/qgsidwinterpolator.cpp
  interpolation/qgsinterpolator.cpp
  interpolation/qgstininterpolator.cpp
  interpolation/Bezier3D.cpp
  interpolation/CloughTocherInterpolator.cpp
  interpolation/qgsdualedgetriangulation.cpp
  interpolation/HalfEdge.cpp
  interpolation/LinTriangleInterpolator.cpp
  interpolation/MathUtils.cpp
  interpolation/NormVecDecorator.cpp
  interpolation/ParametricLine.cpp
  interpolation/TriangleInterpolator.cpp
  interpolation/qgstriangulation.cpp
  interpolation/TriDecorator.cpp
  interpolation/Vector3D.cpp

  processing/qgsalgorithmaddincrementalfield.cpp
  processing/qgsalgorithmaddtablefield.cpp
  processing/qgsalgorithmaddxyfields.cpp
  processing/qgsalgorithmaffinetransform.cpp
  processing/qgsalgorithmaggregate.cpp
  processing/qgsalgorithmalignrasters.cpp
  processing/qgsalgorithmalignsingleraster.cpp
  processing/qgsalgorithmangletonearest.cpp
  processing/qgsalgorithmannotations.cpp
  processing/qgsalgorithmapplylayerstyle.cpp
  processing/qgsalgorithmarraytranslatedfeatures.cpp
  processing/qgsalgorithmaspect.cpp
  processing/qgsalgorithmassignprojection.cpp
  processing/qgsalgorithmattributeindex.cpp
  processing/qgsalgorithmb3dmtogltf.cpp
  processing/qgsalgorithmbasicstatistics.cpp
  processing/qgsalgorithmbatchgeocode.cpp
  processing/qgsalgorithmbatchnominatimgeocode.cpp
  processing/qgsalgorithmboundary.cpp
  processing/qgsalgorithmboundingbox.cpp
  processing/qgsalgorithmbuffer.cpp
  processing/qgsalgorithmcalculateexpression.cpp
  processing/qgsalgorithmcalculateoverlaps.cpp
  processing/qgsalgorithmcategorizeusingstyle.cpp
  processing/qgsalgorithmcellstatistics.cpp
  processing/qgsalgorithmcentroid.cpp
  processing/qgsalgorithmcheckgeometrysegmentlength.cpp
  processing/qgsalgorithmcheckgeometryangle.cpp
  processing/qgsalgorithmcheckvalidity.cpp
  processing/qgsalgorithmfixgeometryduplicatenodes.cpp
  processing/qgsalgorithmfixgeometrymultipart.cpp
  processing/qgsalgorithmfixgeometryoverlap.cpp
  processing/qgsalgorithmfixgeometrydeletefeatures.cpp
  processing/qgsalgorithmfixgeometryangle.cpp
  processing/qgsalgorithmfixgeometryselfintersection.cpp
  processing/qgsalgorithmfixgeometrygap.cpp
  processing/qgsalgorithmcheckgeometryhole.cpp
  processing/qgsalgorithmfixgeometryhole.cpp
  processing/qgsalgorithmcheckgeometrymissingvertex.cpp
  processing/qgsalgorithmfixgeometrymissingvertex.cpp
  processing/qgsalgorithmcheckgeometryarea.cpp
  processing/qgsalgorithmfixgeometryarea.cpp
  processing/qgsalgorithmcheckgeometrylineintersection.cpp
  processing/qgsalgorithmcheckgeometrylinelayerintersection.cpp
  processing/qgsalgorithmcheckgeometrypointcoveredbyline.cpp
  processing/qgsalgorithmcheckgeometrypointinpolygon.cpp
  processing/qgsalgorithmcheckgeometrygap.cpp
  processing/qgsalgorithmcheckgeometrysliverpolygon.cpp
  processing/qgsalgorithmcheckgeometryselfcontact.cpp
  processing/qgsalgorithmcheckgeometryoverlap.cpp
  processing/qgsalgorithmcheckgeometryfollowboundaries.cpp
  processing/qgsalgorithmcheckgeometryduplicatenodes.cpp
  processing/qgsalgorithmcheckgeometrydangle.cpp
  processing/qgsalgorithmcheckgeometryduplicate.cpp
  processing/qgsalgorithmcheckgeometryselfintersection.cpp
  processing/qgsalgorithmcheckgeometrymultipart.cpp
  processing/qgsalgorithmcheckgeometrydegeneratepolygon.cpp
  processing/qgsalgorithmcheckgeometrycontained.cpp
  processing/qgsalgorithmclimb.cpp
  processing/qgsalgorithmclip.cpp
  processing/qgsalgorithmconcavehull.cpp
  processing/qgsalgorithmconcavehullbyfeature.cpp
  processing/qgsalgorithmconditionalbranch.cpp
  processing/qgsalgorithmconstantraster.cpp
  processing/qgsalgorithmconverttocurves.cpp
  processing/qgsalgorithmconvertgeometrytype.cpp
  processing/qgsalgorithmconvexhull.cpp
  processing/qgsalgorithmcoveragesimplify.cpp
  processing/qgsalgorithmcoverageunion.cpp
  processing/qgsalgorithmcoveragevalidate.cpp
  processing/qgsalgorithmcreatedirectory.cpp
  processing/qgsalgorithmdbscanclustering.cpp
  processing/qgsalgorithmdefineprojection.cpp
  processing/qgsalgorithmdelaunaytriangulation.cpp
  processing/qgsalgorithmdeleteduplicategeometries.cpp
  processing/qgsalgorithmdensifygeometriesbycount.cpp
  processing/qgsalgorithmdensifygeometriesbyinterval.cpp
  processing/qgsalgorithmdetectdatasetchanges.cpp
  processing/qgsalgorithmdifference.cpp
  processing/qgsalgorithmdissolve.cpp
  processing/qgsalgorithmdistancewithin.cpp
  processing/qgsalgorithmdownloadvectortiles.cpp
  processing/qgsalgorithmdrape.cpp
  processing/qgsalgorithmdropfields.cpp
  processing/qgsalgorithmdropgeometry.cpp
  processing/qgsalgorithmdropmzvalues.cpp
  processing/qgsalgorithmdxfexport.cpp
  processing/qgsalgorithmexecutepostgisquery.cpp
  processing/qgsalgorithmexecutespatialitequery.cpp
  processing/qgsalgorithmexecutespatialitequeryregistered.cpp
  processing/qgsalgorithmexplode.cpp
  processing/qgsalgorithmexplodehstore.cpp
  processing/qgsalgorithmexportgeometryattributes.cpp
  processing/qgsalgorithmexportlayersinformation.cpp
  processing/qgsalgorithmexportmesh.cpp
  processing/qgsalgorithmexporttopostgresql.cpp
  processing/qgsalgorithmexporttospatialiteregistered.cpp
  processing/qgsalgorithmexporttospatialite.cpp
  processing/qgsalgorithmexporttospreadsheet.cpp
  processing/qgsalgorithmextendlines.cpp
  processing/qgsalgorithmextentfromlayer.cpp
  processing/qgsalgorithmextenttolayer.cpp
  processing/qgsalgorithmextractbinary.cpp
  processing/qgsalgorithmextractbyattribute.cpp
  processing/qgsalgorithmextractbyexpression.cpp
  processing/qgsalgorithmextractbyextent.cpp
  processing/qgsalgorithmextractbylocation.cpp
  processing/qgsalgorithmextractlabels.cpp
  processing/qgsalgorithmextractlayoutmapextent.cpp
  processing/qgsalgorithmextractzmvalues.cpp
  processing/qgsalgorithmextractvertices.cpp
  processing/qgsalgorithmextractspecificvertices.cpp
  processing/qgsalgorithmfieldcalculator.cpp
  processing/qgsalgorithmfiledownloader.cpp
  processing/qgsalgorithmfillnodata.cpp
  processing/qgsalgorithmfillsinkswangliu.cpp
  processing/qgsalgorithmfilter.cpp
  processing/qgsalgorithmfilterbygeometry.cpp
  processing/qgsalgorithmfiltervertices.cpp
  processing/qgsalgorithmfindprojection.cpp
  processing/qgsalgorithmfixgeometries.cpp
  processing/qgsalgorithmflattenrelationships.cpp
  processing/qgsalgorithmforcerhr.cpp
  processing/qgsalgorithmfuzzifyraster.cpp
  processing/qgsalgorithmgenerateelevationprofile.cpp
  processing/qgsalgorithmgeometrybyexpression.cpp
  processing/qgsalgorithmgltftovector.cpp
  processing/qgsalgorithmgpsbabeltools.cpp
  processing/qgsalgorithmgrid.cpp
  processing/qgsalgorithmhillshade.cpp
  processing/qgsalgorithmhubdistance.cpp
  processing/qgsalgorithmimportphotos.cpp
  processing/qgsalgorithminterpolatepoint.cpp
  processing/qgsalgorithmintersection.cpp
  processing/qgsalgorithmjoinbyattribute.cpp
  processing/qgsalgorithmjoinbylocation.cpp
  processing/qgsalgorithmjoinbylocationsummary.cpp
  processing/qgsalgorithmjoinbynearest.cpp
  processing/qgsalgorithmjoinwithlines.cpp
  processing/qgsalgorithmkeepnbiggestparts.cpp
  processing/qgsalgorithmkmeansclustering.cpp
  processing/qgsalgorithmlayoutatlastoimage.cpp
  processing/qgsalgorithmlayoutatlastopdf.cpp
  processing/qgsalgorithmlayouttoimage.cpp
  processing/qgsalgorithmlayouttopdf.cpp
  processing/qgsalgorithmlinedensity.cpp
  processing/qgsalgorithmlineintersection.cpp
  processing/qgsalgorithmlinesubstring.cpp
  processing/qgsalgorithmloadlayer.cpp
  processing/qgsalgorithmmeancoordinates.cpp
  processing/qgsalgorithmmergelines.cpp
  processing/qgsalgorithmmeshsurfacetopolygon.cpp
  processing/qgsalgorithmmergevector.cpp
  processing/qgsalgorithmminimumboundinggeometry.cpp
  processing/qgsalgorithmminimumenclosingcircle.cpp
  processing/qgsalgorithmmultidifference.cpp
  processing/qgsalgorithmmultiintersection.cpp
  processing/qgsalgorithmmultiparttosinglepart.cpp
  processing/qgsalgorithmmultiringconstantbuffer.cpp
  processing/qgsalgorithmmultiunion.cpp
  processing/qgsalgorithmnearestneighbouranalysis.cpp
  processing/qgsalgorithmoffsetlines.cpp
  processing/qgsalgorithmorderbyexpression.cpp
  processing/qgsalgorithmorientedminimumboundingbox.cpp
  processing/qgsalgorithmorthogonalize.cpp
  processing/qgsalgorithmpackage.cpp
  processing/qgsalgorithmpixelcentroidsfrompolygons.cpp
  processing/qgsalgorithmarrayoffsetlines.cpp
  processing/qgsalgorithmpolygonstolines.cpp
  processing/qgsalgorithmpointonsurface.cpp
  processing/qgsalgorithmpointsinpolygon.cpp
  processing/qgsalgorithmpointtolayer.cpp
  processing/qgsalgorithmpointsalonggeometry.cpp
  processing/qgsalgorithmpointslayerfromtable.cpp
  processing/qgsalgorithmpointstopaths.cpp
  processing/qgsalgorithmpoleofinaccessibility.cpp
  processing/qgsalgorithmpolygonize.cpp
  processing/qgsalgorithmprojectpointcartesian.cpp
  processing/qgsalgorithmpromotetomultipart.cpp
  processing/qgsalgorithmraiseexception.cpp
  processing/qgsalgorithmrandomextract.cpp
  processing/qgsalgorithmrandompointsextent.cpp
  processing/qgsalgorithmrandompointsinpolygons.cpp
  processing/qgsalgorithmrandompointsonlines.cpp
  processing/qgsalgorithmrandomraster.cpp
  processing/qgsalgorithmrastercalculator.cpp
  processing/qgsalgorithmrasterdtmslopebasedfilter.cpp
  processing/qgsalgorithmrasterfrequencybycomparisonoperator.cpp
  processing/qgsalgorithmrasterlayerproperties.cpp
  processing/qgsalgorithmrasterlayeruniquevalues.cpp
  processing/qgsalgorithmrasterlogicalop.cpp
  processing/qgsalgorithmrasterminmax.cpp
  processing/qgsalgorithmrasterize.cpp
  processing/qgsalgorithmrasterrank.cpp
  processing/qgsalgorithmrastersampling.cpp
  processing/qgsalgorithmrasterstackposition.cpp
  processing/qgsalgorithmrasterstatistics.cpp
  processing/qgsalgorithmrastersurfacevolume.cpp
  processing/qgsalgorithmrasterzonalstats.cpp
  processing/qgsalgorithmreclassifybylayer.cpp
  processing/qgsalgorithmrectanglesovalsdiamonds.cpp
  processing/qgsalgorithmrefactorfields.cpp
  processing/qgsalgorithmremoveduplicatesbyattribute.cpp
  processing/qgsalgorithmremoveduplicatevertices.cpp
  processing/qgsalgorithmremoveholes.cpp
  processing/qgsalgorithmremovenullgeometry.cpp
  processing/qgsalgorithmremovepartsbyarea.cpp
  processing/qgsalgorithmremovepartsbylength.cpp
  processing/qgsalgorithmrenamelayer.cpp
  processing/qgsalgorithmrenametablefield.cpp
  processing/qgsalgorithmrepairshapefile.cpp
  processing/qgsalgorithmrescaleraster.cpp
  processing/qgsalgorithmreverselinedirection.cpp
  processing/qgsalgorithmrotate.cpp
  processing/qgsalgorithmroundness.cpp
  processing/qgsalgorithmroundrastervalues.cpp
  processing/qgsalgorithmruggedness.cpp
  processing/qgsalgorithmsavefeatures.cpp
  processing/qgsalgorithmsavelog.cpp
  processing/qgsalgorithmsaveselectedfeatures.cpp
  processing/qgsalgorithmsegmentize.cpp
  processing/qgsalgorithmserviceareafromlayer.cpp
  processing/qgsalgorithmserviceareafrompoint.cpp
  processing/qgsalgorithmsetlayerencoding.cpp
  processing/qgsalgorithmsetmvalue.cpp
  processing/qgsalgorithmsetvariable.cpp
  processing/qgsalgorithmsetzvalue.cpp
  processing/qgsalgorithmshortestline.cpp
  processing/qgsalgorithmshortestpathlayertopoint.cpp
  processing/qgsalgorithmshortestpathpointtolayer.cpp
  processing/qgsalgorithmshortestpathpointtopoint.cpp
  processing/qgsalgorithmshpencodinginfo.cpp
  processing/qgsalgorithmsimplify.cpp
  processing/qgsalgorithmsinglesidedbuffer.cpp
  processing/qgsalgorithmslope.cpp
  processing/qgsalgorithmsmooth.cpp
  processing/qgsalgorithmsnapgeometries.cpp
  processing/qgsalgorithmsnaptogrid.cpp
  processing/qgsalgorithmspatialindex.cpp
  processing/qgsalgorithmsplitfeaturesbyattributecharacter.cpp
  processing/qgsalgorithmsplitlineantimeridian.cpp
  processing/qgsalgorithmsplitlinesbylength.cpp
  processing/qgsalgorithmsplitvectorlayer.cpp
  processing/qgsalgorithmsplitwithlines.cpp
  processing/qgsalgorithmstdbscanclustering.cpp
  processing/qgsalgorithmstringconcatenation.cpp
  processing/qgsalgorithmswapxy.cpp
  processing/qgsalgorithmsubdivide.cpp
  processing/qgsalgorithmsumlinelength.cpp
  processing/qgsalgorithmsymmetricaldifference.cpp
  processing/qgsalgorithmtaperedbuffer.cpp
  processing/qgsalgorithmtinmeshcreation.cpp
  processing/qgsalgorithmtransect.cpp
  processing/qgsalgorithmtransform.cpp
  processing/qgsalgorithmtranslate.cpp
  processing/qgsalgorithmtruncatetable.cpp
  processing/qgsalgorithmunion.cpp
  processing/qgsalgorithmuniquevalues.cpp
  processing/qgsalgorithmuniquevalueindex.cpp
  processing/qgsalgorithmurlopener.cpp
  processing/qgsalgorithmhttprequest.cpp
  processing/qgsalgorithmvectorize.cpp
  processing/qgsalgorithmvirtualrastercalculator.cpp
  processing/qgsalgorithmvoronoipolygons.cpp
  processing/qgsalgorithmwedgebuffers.cpp
  processing/qgsalgorithmwritevectortiles.cpp
  processing/qgsalgorithmxyztiles.cpp
  processing/qgsalgorithmzonalhistogram.cpp
  processing/qgsalgorithmzonalminmaxpoint.cpp
  processing/qgsalgorithmzonalstatistics.cpp
  processing/qgsalgorithmzonalstatisticsfeaturebased.cpp
  processing/qgsbookmarkalgorithms.cpp
  processing/qgsmetadataalgorithms.cpp
  processing/qgsprojectstylealgorithms.cpp
  processing/qgsstylealgorithms.cpp

  processing/qgsalgorithmnetworkanalysisbase.cpp

  processing/qgsnativealgorithms.cpp
  processing/qgsoverlayutils.cpp
  processing/qgsrasteranalysisutils.cpp
  processing/qgsreclassifyutils.cpp

  raster/qgsalignraster.cpp
  raster/qgsninecellfilter.cpp
  raster/qgsruggednessfilter.cpp
  raster/qgsderivativefilter.cpp
  raster/qgshillshadefilter.cpp
  raster/qgskde.cpp
  raster/qgsslopefilter.cpp
  raster/qgsaspectfilter.cpp
  raster/qgstotalcurvaturefilter.cpp
  raster/qgsrelief.cpp
  raster/qgsrastercalcnode.cpp
  raster/qgsrastercalculator.cpp
  raster/qgsrastermatrix.cpp
  vector/qgsgeometrysnapper.cpp
  vector/qgsgeometrysnappersinglesource.cpp
  vector/qgszonalstatistics.cpp

  mesh/qgsmeshcontours.cpp
  mesh/qgsmeshtriangulation.cpp

  network/qgsgraph.cpp
  network/qgsgraphbuilder.cpp
  network/qgsgraphbuilderinterface.cpp
  network/qgsnetworkspeedstrategy.cpp
  network/qgsnetworkdistancestrategy.cpp
  network/qgsvectorlayerdirector.cpp
  network/qgsgraphanalyzer.cpp

  vector/geometry_checker/qgsfeaturepool.cpp
  vector/geometry_checker/qgsgeometryanglecheck.cpp
  vector/geometry_checker/qgsgeometryareacheck.cpp
  vector/geometry_checker/qgsgeometrycheck.cpp
  vector/geometry_checker/qgsgeometrycheckresolutionmethod.cpp
  vector/geometry_checker/qgsgeometrycheckcontext.cpp
  vector/geometry_checker/qgsgeometrychecker.cpp
  vector/geometry_checker/qgsgeometrycheckerror.cpp
  vector/geometry_checker/qgsgeometrycheckerutils.cpp
  vector/geometry_checker/qgsgeometrycheckregistry.cpp
  vector/geometry_checker/qgsgeometrycontainedcheck.cpp
  vector/geometry_checker/qgsgeometrydanglecheck.cpp
  vector/geometry_checker/qgsgeometrydegeneratepolygoncheck.cpp
  vector/geometry_checker/qgsgeometryduplicatecheck.cpp
  vector/geometry_checker/qgsgeometryduplicatenodescheck.cpp
  vector/geometry_checker/qgsgeometryfollowboundariescheck.cpp
  vector/geometry_checker/qgsgeometrygapcheck.cpp
  vector/geometry_checker/qgsgeometrymissingvertexcheck.cpp
  vector/geometry_checker/qgsgeometryholecheck.cpp
  vector/geometry_checker/qgsgeometrylineintersectioncheck.cpp
  vector/geometry_checker/qgsgeometrylinelayerintersectioncheck.cpp
  vector/geometry_checker/qgsgeometrymultipartcheck.cpp
  vector/geometry_checker/qgsgeometryoverlapcheck.cpp
  vector/geometry_checker/qgsgeometrypointcoveredbylinecheck.cpp
  vector/geometry_checker/qgsgeometrypointinpolygoncheck.cpp
  vector/geometry_checker/qgsgeometrysegmentlengthcheck.cpp
  vector/geometry_checker/qgsgeometryselfcontactcheck.cpp
  vector/geometry_checker/qgsgeometryselfintersectioncheck.cpp
  vector/geometry_checker/qgsgeometrysliverpolygoncheck.cpp
  vector/geometry_checker/qgsgeometrytypecheck.cpp
  vector/geometry_checker/qgsgeometryisvalidcheck.cpp
  vector/geometry_checker/qgssinglegeometrycheck.cpp
  vector/geometry_checker/qgssinglegeometrycheck.cpp
  vector/geometry_checker/qgsvectordataproviderfeaturepool.cpp
  vector/geometry_checker/qgsvectorlayerfeaturepool.cpp
)

set(QGIS_ANALYSIS_HDRS
  qgsanalysis.h

  georeferencing/qgsgcpgeometrytransformer.h
  georeferencing/qgsgcppoint.h
  georeferencing/qgsgcptransformer.h
  georeferencing/qgsvectorwarper.h

  interpolation/Bezier3D.h
  interpolation/CloughTocherInterpolator.h
  interpolation/qgsdualedgetriangulation.h
  interpolation/HalfEdge.h
  interpolation/LinTriangleInterpolator.h
  interpolation/MathUtils.h
  interpolation/NormVecDecorator.h
  interpolation/ParametricLine.h
  interpolation/TriDecorator.h
  interpolation/TriangleInterpolator.h
  interpolation/qgstriangulation.h
  interpolation/Vector3D.h
  interpolation/qgsgridfilewriter.h
  interpolation/qgsidwinterpolator.h
  interpolation/qgsinterpolator.h
  interpolation/qgstininterpolator.h

  mesh/qgsmeshcontours.h
  mesh/qgsmeshtriangulation.h

  network/qgsgraph.h
  network/qgsgraphanalyzer.h
  network/qgsgraphbuilder.h
  network/qgsgraphbuilderinterface.h
  network/qgsgraphdirector.h
  network/qgsnetworkdistancestrategy.h
  network/qgsnetworkspeedstrategy.h
  network/qgsnetworkstrategy.h
  network/qgsvectorlayerdirector.h

  processing/qgsalgorithmbatchgeocode.h
  processing/qgsalgorithmbatchnominatimgeocode.h
  processing/qgsalgorithmfiledownloader.h
  processing/qgsalgorithmimportphotos.h
  processing/qgsnativealgorithms.h
  processing/qgsprojectstylealgorithms.h
  processing/qgsreclassifyutils.h
  processing/qgsalgorithmurlopener.h
  processing/qgsalgorithmhttprequest.h

  raster/qgsalignraster.h
  raster/qgsaspectfilter.h
  raster/qgsderivativefilter.h
  raster/qgshillshadefilter.h
  raster/qgskde.h
  raster/qgsninecellfilter.h
  raster/qgsrastercalcnode.h
  raster/qgsrastercalculator.h
  raster/qgsrastermatrix.h
  raster/qgsrelief.h
  raster/qgsruggednessfilter.h
  raster/qgsslopefilter.h
  raster/qgstotalcurvaturefilter.h

  vector/geometry_checker/qgsfeaturepool.h
  vector/geometry_checker/qgsgeometryanglecheck.h
  vector/geometry_checker/qgsgeometryareacheck.h
  vector/geometry_checker/qgsgeometrycheck.h
  vector/geometry_checker/qgsgeometrycheckresolutionmethod.h
  vector/geometry_checker/qgsgeometrycheckcontext.h
  vector/geometry_checker/qgsgeometrychecker.h
  vector/geometry_checker/qgsgeometrycheckerror.h
  vector/geometry_checker/qgsgeometrycheckerutils.h
  vector/geometry_checker/qgsgeometrycheckfactory.h
  vector/geometry_checker/qgsgeometrycheckregistry.h
  vector/geometry_checker/qgsgeometrycontainedcheck.h
  vector/geometry_checker/qgsgeometrydanglecheck.h
  vector/geometry_checker/qgsgeometrydegeneratepolygoncheck.h
  vector/geometry_checker/qgsgeometryduplicatecheck.h
  vector/geometry_checker/qgsgeometryduplicatenodescheck.h
  vector/geometry_checker/qgsgeometryfollowboundariescheck.h
  vector/geometry_checker/qgsgeometrygapcheck.h
  vector/geometry_checker/qgsgeometryholecheck.h
  vector/geometry_checker/qgsgeometryisvalidcheck.h
  vector/geometry_checker/qgsgeometrylineintersectioncheck.h
  vector/geometry_checker/qgsgeometrylinelayerintersectioncheck.h
  vector/geometry_checker/qgsgeometrymissingvertexcheck.h
  vector/geometry_checker/qgsgeometrymultipartcheck.h
  vector/geometry_checker/qgsgeometryoverlapcheck.h
  vector/geometry_checker/qgsgeometrypointcoveredbylinecheck.h
  vector/geometry_checker/qgsgeometrypointinpolygoncheck.h
  vector/geometry_checker/qgsgeometrysegmentlengthcheck.h
  vector/geometry_checker/qgsgeometryselfcontactcheck.h
  vector/geometry_checker/qgsgeometryselfintersectioncheck.h
  vector/geometry_checker/qgsgeometrysliverpolygoncheck.h
  vector/geometry_checker/qgsgeometrytypecheck.h
  vector/geometry_checker/qgssinglegeometrycheck.h
  vector/geometry_checker/qgsvectordataproviderfeaturepool.h
  vector/geometry_checker/qgsvectorlayerfeaturepool.h

  vector/qgsgeometrysnapper.h
  vector/qgsgeometrysnappersinglesource.h
  vector/qgszonalstatistics.h
)

if (WITH_PDAL AND PDAL_2_5_OR_HIGHER)
  set(QGIS_ANALYSIS_SRCS ${QGIS_ANALYSIS_SRCS}
    ${CMAKE_SOURCE_DIR}/external/untwine/api/QgisUntwine.cpp

    processing/pdal/qgspdalalgorithms.cpp

    processing/pdal/qgspdalalgorithmbase.cpp

    processing/pdal/qgsalgorithmpdalassignprojection.cpp
    processing/pdal/qgsalgorithmpdalboundary.cpp
    processing/pdal/qgsalgorithmpdalbuildvpc.cpp
    processing/pdal/qgsalgorithmpdalclip.cpp
    processing/pdal/qgsalgorithmpdalconvertformat.cpp
    processing/pdal/qgsalgorithmpdalcreatecopc.cpp
    processing/pdal/qgsalgorithmpdaldensity.cpp
    processing/pdal/qgsalgorithmpdalexportraster.cpp
    processing/pdal/qgsalgorithmpdalexportrastertin.cpp
    processing/pdal/qgsalgorithmpdalexportvector.cpp
    processing/pdal/qgsalgorithmpdalfilter.cpp
    processing/pdal/qgsalgorithmpdalinformation.cpp
    processing/pdal/qgsalgorithmpdalmerge.cpp
    processing/pdal/qgsalgorithmpdalreproject.cpp
    processing/pdal/qgsalgorithmpdalthinbydecimate.cpp
    processing/pdal/qgsalgorithmpdalthinbyradius.cpp
    processing/pdal/qgsalgorithmpdaltile.cpp
  )

  set(QGIS_ANALYSIS_HDRS ${QGIS_ANALYSIS_HDRS}
    ${CMAKE_SOURCE_DIR}/external/untwine/api/QgisUntwine.hpp

    processing/pdal/qgspdalalgorithms.h
  )

  include_directories(
    ${CMAKE_SOURCE_DIR}/external/untwine/api
  )

  IF(WIN32)
    set_source_files_properties(
      ${CMAKE_SOURCE_DIR}/external/untwine/api/QgisUntwine.cpp
      PROPERTIES COMPILE_DEFINITIONS "UNICODE"
    )
  endif()
endif()

include_directories(SYSTEM ${SPATIALINDEX_INCLUDE_DIR})
include_directories(BEFORE raster)
include_directories(BEFORE mesh)

if(NOT MSVC)
  set_source_files_properties(
    ${BISON_QgsRasterCalcParser_OUTPUTS}
    ${FLEX_QgsRasterCalcLexer_OUTPUTS}
    PROPERTIES COMPILE_FLAGS "-w"
  )
else()
  if(PEDANTIC)
    # 4127 expression is constant
    # 4702 unreachable code
    set_source_files_properties(
      ${BISON_QgsRasterCalcParser_OUTPUTS}
      ${FLEX_QgsRasterCalcLexer_OUTPUTS}
      PROPERTIES COMPILE_FLAGS "-wd4127 -wd4702 /W0"
    )
  endif()
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  set_source_files_properties(
    interpolation/qgstininterpolator.cpp
    interpolation/NormVecDecorator.cpp
    interpolation/CloughTocherInterpolator.cpp
    PROPERTIES COMPILE_FLAGS "-Wno-overloaded-virtual"
  )
endif()


#############################################################
# qgis_analysis library

add_library(qgis_analysis ${LIBRARY_TYPE} ${QGIS_ANALYSIS_SRCS} ${QGIS_ANALYSIS_HDRS})
if(QGISPOSTFIX)
  set_target_properties(qgis_analysis PROPERTIES
    RUNTIME_OUTPUT_NAME qgis_analysis${QGISPOSTFIX}
    LIBRARY_OUTPUT_NAME qgis_analysis${QGISPOSTFIX}
  )
endif()

if (USE_PRECOMPILED_HEADERS)
  target_precompile_headers(qgis_analysis PRIVATE $<$<COMPILE_LANGUAGE:CXX>:${CMAKE_SOURCE_DIR}/src/core/qgis.h>)
endif()

set_target_properties(qgis_analysis PROPERTIES UNITY_BUILD ${ENABLE_UNITY_BUILDS})

# require c++17
target_compile_features(qgis_analysis PRIVATE cxx_std_17)

target_include_directories(qgis_analysis PUBLIC
  ${CMAKE_SOURCE_DIR}/src/analysis
  ${CMAKE_SOURCE_DIR}/src/analysis/georeferencing
  ${CMAKE_SOURCE_DIR}/src/analysis/interpolation
  ${CMAKE_SOURCE_DIR}/src/analysis/mesh
  ${CMAKE_SOURCE_DIR}/src/analysis/network
  ${CMAKE_SOURCE_DIR}/src/analysis/processing
  ${CMAKE_SOURCE_DIR}/src/analysis/raster
  ${CMAKE_SOURCE_DIR}/src/analysis/vector/
  ${CMAKE_SOURCE_DIR}/src/analysis/vector/geometry_checker
  ${CMAKE_SOURCE_DIR}/external/tinygltf
  ${CMAKE_BINARY_DIR}/src/analysis
)

if (WITH_PDAL AND PDAL_2_5_OR_HIGHER)
  target_include_directories(qgis_analysis PUBLIC
    ${CMAKE_SOURCE_DIR}/src/analysis/processing/pdal
  )
endif()

GENERATE_EXPORT_HEADER(
   qgis_analysis
   BASE_NAME ANALYSIS
   EXPORT_FILE_NAME qgis_analysis.h
)

set(QGIS_ANALYSIS_HDRS ${QGIS_ANALYSIS_HDRS} ${CMAKE_CURRENT_BINARY_DIR}/qgis_analysis.h)

#generate unversioned libs for android
if (NOT ANDROID)
  set_target_properties(qgis_analysis PROPERTIES
    VERSION ${COMPLETE_VERSION}
    SOVERSION ${COMPLETE_VERSION}
    )
endif()

target_link_libraries(
  qgis_analysis
  qgis_core
  )

if(HAVE_GSL)
  target_link_libraries(qgis_analysis GSL::gsl)
endif()

if(HAVE_OPENCL)
    target_link_libraries(qgis_analysis ${OpenCL_LIBRARIES})
endif()

if (WITH_DRACO)
  target_link_libraries(qgis_analysis ${DRACO_LIBRARY})
endif()

target_compile_definitions(qgis_analysis PRIVATE "-DQT_NO_FOREACH")

# clang-tidy
if(CLANG_TIDY_EXE)
  set_target_properties(
    qgis_analysis PROPERTIES
    CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
  )
endif()

# install
if(NOT QGIS_MAC_BUNDLE)
  install(FILES ${QGIS_ANALYSIS_HDRS} DESTINATION ${QGIS_INCLUDE_DIR})
endif()

install(TARGETS qgis_analysis
  RUNTIME DESTINATION ${QGIS_BIN_DIR}
  LIBRARY DESTINATION ${QGIS_LIB_DIR}
  ARCHIVE DESTINATION ${QGIS_LIB_DIR})
