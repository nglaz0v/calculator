TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

DEFINES += USE_VALUE

SOURCES += \
        main.cpp\
        expression.cpp\
        value.cpp\
        verylong.cpp\
        identity.cpp

HEADERS += \
        expression.h\
        value.h\
        verylong.h\
        identity.h \
        bitset_arithmetic.hpp \
        big_int.hpp

#unix {
#    YACCSOURCES = parser.yy
#    LEXSOURCES = scanner.ll
#}
