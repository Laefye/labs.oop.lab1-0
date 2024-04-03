QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    exceptions/incorrectfigureindexexception.cpp \
    exceptions/incorrectinputexception.cpp \
    exceptions/incorrectradiusexception.cpp \
    exceptions/incorrectrectanglepointexception.cpp \
    exceptions/samepointexception.cpp \
    makers/rectanglemaker.cpp \
    makers/trianglemaker.cpp \
    menu.cpp \
    shapes/circle.cpp \
    shapes/point.cpp \
    shapes/rectangle.cpp \
    shapes/shape.cpp \
    shapes/shapes.cpp \
    shapes/triangle.cpp \
        main.cpp \
    makers/circlemaker.cpp \
    makers/maker.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS +=  \
    exceptions/incorrectfigureindexexception.h \
    exceptions/incorrectinputexception.h \
    exceptions/incorrectradiusexception.h \
    exceptions/incorrectrectanglepointexception.h \
    exceptions/samepointexception.h \
    makers/rectanglemaker.h \
    makers/trianglemaker.h \
    menu.h \
    shapes/circle.h \
    shapes/point.h \
    shapes/rectangle.h \
    shapes/shape.h \
    shapes/shapes.h \
    shapes/triangle.h \
    makers/circlemaker.h \
    makers/maker.h
