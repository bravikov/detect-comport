#-------------------------------------------------
#
# Project created by QtCreator 2014-01-14T21:24:41
#
#-------------------------------------------------

QT       += core widgets
QT       -= gui

TARGET = detect-comport
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

include(qextserialport-1.2rc/src/qextserialport.pri)
QMAKE_CXXFLAGS += -std=c++11

OTHER_FILES += \
    README \
    detect-comport.rc

win32:RC_FILE = detect-comport.rc

RESOURCES += \
    detect-comport.qrc
