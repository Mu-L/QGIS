# The following has been generated automatically from src/core/layout/qgslayout.h
QgsLayout.ZPage = QgsLayout.ZValues.ZPage
QgsLayout.ZItem = QgsLayout.ZValues.ZItem
QgsLayout.ZGrid = QgsLayout.ZValues.ZGrid
QgsLayout.ZGuide = QgsLayout.ZValues.ZGuide
QgsLayout.ZSmartGuide = QgsLayout.ZValues.ZSmartGuide
QgsLayout.ZMouseHandles = QgsLayout.ZValues.ZMouseHandles
QgsLayout.ZViewTool = QgsLayout.ZValues.ZViewTool
QgsLayout.ZSnapIndicator = QgsLayout.ZValues.ZSnapIndicator
QgsLayout.UndoLayoutDpi = QgsLayout.UndoCommand.UndoLayoutDpi
QgsLayout.UndoNone = QgsLayout.UndoCommand.UndoNone
try:
    QgsLayout.__attribute_docs__ = {'changed': 'Emitted when properties of the layout change. This signal is only\nemitted for settings directly managed by the layout, and is not emitted\nwhen child items change.\n', 'variablesChanged': 'Emitted whenever the expression variables stored in the layout have been\nchanged.\n', 'selectedItemChanged': 'Emitted whenever the selected item changes. If ``None``, no item is\nselected.\n', 'refreshed': 'Emitted when the layout has been refreshed and items should also be\nrefreshed and updated.\n', 'backgroundTaskCountChanged': 'Emitted whenever the ``total`` number of background tasks running in\nitems from the layout changes.\n\n.. versionadded:: 3.10\n', 'itemAdded': 'Emitted when an ``item`` was added to the layout.\n\n.. versionadded:: 3.20\n'}
    QgsLayout.__virtual_methods__ = ['writeXml', 'readXml']
    QgsLayout.__overridden_methods__ = ['createExpressionContext', 'createCommand']
    QgsLayout.__signal_arguments__ = {'selectedItemChanged': ['selected: QgsLayoutItem'], 'backgroundTaskCountChanged': ['total: int'], 'itemAdded': ['item: QgsLayoutItem']}
    QgsLayout.__group__ = ['layout']
except (NameError, AttributeError):
    pass
