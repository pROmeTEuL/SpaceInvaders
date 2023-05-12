TEMPLATE = app
CONFIG += console c++17
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

include(Engine/Engine.pri)
include(FileIO/FileIO.pri)
include(GameObjects/GameObjects.pri)
include(Screens/Screens.pri)


SOURCES += \
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
