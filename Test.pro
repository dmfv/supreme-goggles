QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
INCLUDEPATH += include
INCLUDEPATH += config/

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    sources/centralwidget.cpp \
    sources/main.cpp \
    sources/mainwindow.cpp \
    sources/stylewindow.cpp \
    sources/tablewithbuttons.cpp \
    sources/textwithbuttons.cpp \
    sources/textwithbuttonscontainer.cpp


HEADERS += \
    include/centralwidget.h \
    include/mainwindow.h \
    include/stylewindow.h \
    include/tablewithbuttons.h \
    include/textwithbuttons.h \
    include/textwithbuttonscontainer.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    config/blue.stylesheet \
    config/conf.json \
    config/green.stylesheet \
    config/grey.stylesheet \
    config/red.stylesheet
