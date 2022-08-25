TEMPLATE = app
CONFIG += console c++11
CONFIG -= qt

QMAKE_MACOSX_DEPLOYMENT_TARGET = 11.0

exists($$OUT_PWD/conanbuildinfo.pri) {
    CONFIG += conan_basic_setup
    include ($$OUT_PWD/conanbuildinfo.pri)
} else {
   LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

macx {
    CONFIG += app_bundle
    LIBS += -ObjC
}

SOURCES += \
        Engine/bitmapstore.cpp \
        Engine/gameengine.cpp \
        Engine/screenmanager.cpp \
        Engine/screenmanagerremotecontrol.cpp \
        Engine/soundengine.cpp \
        Screens/button.cpp \
        Screens/screenmanagerremotecontrol.cpp \
        Screens/uipannel.cpp \
        main.cpp

DISTFILES += \
        conanfile.txt \
        fonts/Roboto-Bold.ttf \
        graphics/background.png \
        graphics/bullet.png \
        graphics/invader1.png \
        graphics/playership.png \
        sound/click.ogg \
        sound/invaderexplode.ogg \
        sound/playerexplode.ogg \
        sound/shoot.ogg

HEADERS += \
    Engine/bitmapstore.h \
    Engine/developstate.h \
    Engine/gameengine.h \
    Engine/screenmanager.h \
    Engine/screenmanagerremotecontrol.h \
    Engine/soundengine.h \
    Screens/button.h \
    Screens/screenmanagerremotecontrol.h \
    Screens/uipannel.h
