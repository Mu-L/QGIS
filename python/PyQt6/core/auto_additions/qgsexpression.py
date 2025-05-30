# The following has been generated automatically from src/core/expression/qgsexpression.h
QgsExpression.ParserError.Unknown = QgsExpression.ParserError.ParserErrorType.Unknown
QgsExpression.ParserError.FunctionUnknown = QgsExpression.ParserError.ParserErrorType.FunctionUnknown
QgsExpression.ParserError.FunctionWrongArgs = QgsExpression.ParserError.ParserErrorType.FunctionWrongArgs
QgsExpression.ParserError.FunctionInvalidParams = QgsExpression.ParserError.ParserErrorType.FunctionInvalidParams
QgsExpression.ParserError.FunctionNamedArgsError = QgsExpression.ParserError.ParserErrorType.FunctionNamedArgsError
QgsExpression.soBbox = QgsExpression.SpatialOperator.soBbox
QgsExpression.soIntersects = QgsExpression.SpatialOperator.soIntersects
QgsExpression.soContains = QgsExpression.SpatialOperator.soContains
QgsExpression.soCrosses = QgsExpression.SpatialOperator.soCrosses
QgsExpression.soEquals = QgsExpression.SpatialOperator.soEquals
QgsExpression.soDisjoint = QgsExpression.SpatialOperator.soDisjoint
QgsExpression.soOverlaps = QgsExpression.SpatialOperator.soOverlaps
QgsExpression.soTouches = QgsExpression.SpatialOperator.soTouches
QgsExpression.soWithin = QgsExpression.SpatialOperator.soWithin
try:
    QgsExpression.ParserError.__attribute_docs__ = {'errorMsg': 'The message for the error at this location.', 'firstLine': "The first line that contained the error in the parser.\nDepending on the error sometimes this doesn't mean anything.", 'firstColumn': "The first column that contained the error in the parser.\nDepending on the error sometimes this doesn't mean anything.", 'lastLine': 'The last line that contained the error in the parser.', 'lastColumn': 'The last column that contained the error in the parser.'}
    QgsExpression.ParserError.__annotations__ = {'errorMsg': str, 'firstLine': int, 'firstColumn': int, 'lastLine': int, 'lastColumn': int}
    QgsExpression.ParserError.__doc__ = """Details about any parser errors that were found when parsing the expression."""
    QgsExpression.ParserError.__group__ = ['expression']
except (NameError, AttributeError):
    pass
try:
    QgsExpression.expressionToLayerFieldIndex = staticmethod(QgsExpression.expressionToLayerFieldIndex)
    QgsExpression.quoteFieldExpression = staticmethod(QgsExpression.quoteFieldExpression)
    QgsExpression.checkExpression = staticmethod(QgsExpression.checkExpression)
    QgsExpression.replaceExpressionText = staticmethod(QgsExpression.replaceExpressionText)
    QgsExpression.evaluateToDouble = staticmethod(QgsExpression.evaluateToDouble)
    QgsExpression.registerFunction = staticmethod(QgsExpression.registerFunction)
    QgsExpression.unregisterFunction = staticmethod(QgsExpression.unregisterFunction)
    QgsExpression.cleanRegisteredFunctions = staticmethod(QgsExpression.cleanRegisteredFunctions)
    QgsExpression.isFunctionName = staticmethod(QgsExpression.isFunctionName)
    QgsExpression.functionIndex = staticmethod(QgsExpression.functionIndex)
    QgsExpression.functionCount = staticmethod(QgsExpression.functionCount)
    QgsExpression.quotedColumnRef = staticmethod(QgsExpression.quotedColumnRef)
    QgsExpression.quotedString = staticmethod(QgsExpression.quotedString)
    QgsExpression.quotedValue = staticmethod(QgsExpression.quotedValue)
    QgsExpression.helpText = staticmethod(QgsExpression.helpText)
    QgsExpression.tags = staticmethod(QgsExpression.tags)
    QgsExpression.addVariableHelpText = staticmethod(QgsExpression.addVariableHelpText)
    QgsExpression.variableHelpText = staticmethod(QgsExpression.variableHelpText)
    QgsExpression.formatVariableHelp = staticmethod(QgsExpression.formatVariableHelp)
    QgsExpression.group = staticmethod(QgsExpression.group)
    QgsExpression.formatPreviewString = staticmethod(QgsExpression.formatPreviewString)
    QgsExpression.createFieldEqualityExpression = staticmethod(QgsExpression.createFieldEqualityExpression)
    QgsExpression.isFieldEqualityExpression = staticmethod(QgsExpression.isFieldEqualityExpression)
    QgsExpression.attemptReduceToInClause = staticmethod(QgsExpression.attemptReduceToInClause)
    QgsExpression.__group__ = ['expression']
except (NameError, AttributeError):
    pass
