# The following has been generated automatically from src/gui/maptools/qgsmaptooldigitizefeature.h
try:
    QgsMapToolDigitizeFeature.__attribute_docs__ = {'digitizingCompleted': 'Emitted whenever the digitizing has been successfully completed\n\n:param feature: the new digitized feature\n', 'digitizingFinished': 'Emitted whenever the digitizing has been ended without digitizing any\nfeature\n', 'digitizingCanceled': 'Emitted when the digitizing process was interrupted by the user.\n\n.. versionadded:: 3.28\n'}
    QgsMapToolDigitizeFeature.__virtual_methods__ = ['layerGeometryCaptured', 'featureDigitized']
    QgsMapToolDigitizeFeature.__overridden_methods__ = ['capabilities', 'supportsTechnique', 'cadCanvasReleaseEvent', 'activate', 'deactivate', 'reactivate', 'keyPressEvent']
    QgsMapToolDigitizeFeature.__signal_arguments__ = {'digitizingCompleted': ['feature: QgsFeature']}
    QgsMapToolDigitizeFeature.__group__ = ['maptools']
except (NameError, AttributeError):
    pass
