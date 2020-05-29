#-------------------------------------------------
#
# Project created by QtCreator 2011-06-11T10:57:14
#
#-------------------------------------------------

QT       += core gui
QT       += network


TARGET = MappingAnalysis
TEMPLATE = app

TEMPLATE = app
DEPENDPATH += .
INCLUDEPATH += ../..
QMAKE_LIBDIR += ../../build

SOURCES += main.cpp\
    MappingAnalysis.cpp \
    PostureRecorder.cpp \
    USBConnector.cpp \
    DataHandler.cpp \
    DataCalculatingThread.cpp \
    VibroThread.cpp \
    testingIMUthread.cpp \
    testingVibroThread.cpp

HEADERS  += MappingAnalysis.h \
    PostureRecorder.h \
    USBConnector.h \
    DataHandler.h \
    MainStructure.h \
    DataCalculatingThread.h \
    VibroThread.h \
    testingIMUthread.h \
    testingVibroThread.h

FORMS    += MappingAnalysis.ui


CONFIG(debug, debug|release):LIBS  += -lqextserialportd
else:LIBS  += -lqextserialport

unix:DEFINES   = _TTY_POSIX_
win32:DEFINES  = _TTY_WIN_

RESOURCES += \
    MappingAnalysis.qrc
