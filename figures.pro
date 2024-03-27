QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        exceptions/incorrectfigureindex.cpp \
        factories/circlefactory.cpp \
        factories/rectanglefactory.cpp \
        factories/trianglefactory.cpp \
        figures/circle.cpp \
        exceptions/badparams.cpp \
        exceptions/incorrectcircleradius.cpp \
        exceptions/incorrectrectanglepoint.cpp \
        exceptions/samecoordinate.cpp \
        factories/factory.cpp \
        figures/figure.cpp \
        figures/figures.cpp \
        main.cpp \
        menu.cpp \
        params.cpp \
        paramsfrominput.cpp \
        figures/point.cpp \
        figures/rectangle.cpp \
        figures/triangle.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    exceptions/incorrectfigureindex.h \
    factories/circlefactory.h \
    factories/rectanglefactory.h \
    factories/trianglefactory.h \
    figures/circle.h \
    exceptions/badparams.h \
    exceptions/incorrectcircleradius.h \
    exceptions/incorrectrectanglepoint.h \
    exceptions/samecoordinate.h \
    factories/factory.h \
    figures/figure.h \
    figures/figures.h \
    menu.h \
    params.h \
    paramsfrominput.h \
    figures/point.h \
    figures/rectangle.h \
    figures/triangle.h
