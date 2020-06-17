include(gtest_dependency.pri)

INCLUDEPATH += ..\..\testproject

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        ../../testproject/IKeypad.h \
        ../../testproject/ILatch.h \
        ../../testproject/lockcontroller.h \
        tst_testdivisionbyzero.h

SOURCES += \
        ../../testproject/lockcontroller.cpp \
        main.cpp
