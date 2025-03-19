#-------------------------------------------------
#
# Project created by QtCreator 2025-02-26T13:32:40
#
#-------------------------------------------------

QT       += core gui sql

QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = BCYWithTRY
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17
CONFIG   += extserialport

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    adgain.cpp \
    datahistry.cpp \
    datetimechange.cpp \
    dbbackrest.cpp \
    endpoint.cpp \
    endqc1.cpp \
    endqc2.cpp \
    keyboard.cpp \
    pi2c.cpp \
    printer.cpp \
    printingbtns.cpp \
    qc.cpp \
    qcustomplot.cpp \
    test.cpp \
    testconfig.cpp \
    twopoint.cpp \
    virtual_keyboard.cpp \
    wifi-setup.cpp \
    optimization.cpp \
    linalg.cpp \
    interpolation.cpp \
    integration.cpp \
    ap.cpp \
    alglibmisc.cpp \
    alglibinternal.cpp \
    specialfunctions.cpp \
    solvers.cpp \
    brycss.cpp \
    trycss.cpp

HEADERS += \
        mainwindow.h \
    HL7Exception.h \
    hl7mllp.h \
    HL7Object.h \
    hl7socket.h \
    pi2c.h \
    printer.h \
    qcustomplot.h \
    Util.h \
    virtual_keyboard.h \
    optimization.h \
    linalg.h \
    interpolation.h \
    integration.h \
    ap.h \
    alglibmisc.h \
    alglibinternal.h \
    stdafx.h \
    specialfunctions.h \
    solvers.h

FORMS += \
        mainwindow.ui \
    virtual_keyboard.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QMAKE_CXXFLAGS_RELEASE += -Os
QMAKE_CFLAGS_RELEASE -= -O2

INCLUDEPATH    += /usr/local/include
LIBS += -L/usr/local/lib -lwiringPi -liir

RESOURCES += \
    icons.qrc
