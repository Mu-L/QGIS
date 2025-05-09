# The following has been generated automatically from src/gui/editorwidgets/qgsdatetimeedit.h
try:
    QgsDateTimeEdit.__attribute_docs__ = {'valueChanged': 'Signal emitted whenever the value changes.\n\n:param date: The new date/time value.\n'}
    QgsDateTimeEdit.__virtual_methods__ = ['emitValueChanged']
    QgsDateTimeEdit.__overridden_methods__ = ['clear', 'event', 'mousePressEvent', 'focusOutEvent', 'focusInEvent', 'wheelEvent', 'showEvent']
    QgsDateTimeEdit.__signal_arguments__ = {'valueChanged': ['date: QDateTime']}
    QgsDateTimeEdit.__group__ = ['editorwidgets']
except (NameError, AttributeError):
    pass
try:
    QgsTimeEdit.__attribute_docs__ = {'timeValueChanged': 'Signal emitted whenever the time changes.\n'}
    QgsTimeEdit.__overridden_methods__ = ['emitValueChanged']
    QgsTimeEdit.__signal_arguments__ = {'timeValueChanged': ['time: QTime']}
    QgsTimeEdit.__group__ = ['editorwidgets']
except (NameError, AttributeError):
    pass
try:
    QgsDateEdit.__attribute_docs__ = {'dateValueChanged': 'Signal emitted whenever the date changes.\n'}
    QgsDateEdit.__overridden_methods__ = ['emitValueChanged']
    QgsDateEdit.__signal_arguments__ = {'dateValueChanged': ['date: QDate']}
    QgsDateEdit.__group__ = ['editorwidgets']
except (NameError, AttributeError):
    pass
