QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        circle.cpp \
        factory.cpp \
        figure.cpp \
        figures.cpp \
        main.cpp \
        menu.cpp \
        params.cpp \
        paramsfrominput.cpp \
        point.cpp \
        rectangle.cpp \
        triangle.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    circle.h \
    factory.h \
    figure.h \
    figures.h \
    menu.h \
    params.h \
    paramsfrominput.h \
    point.h \
    rectangle.h \
    triangle.h
