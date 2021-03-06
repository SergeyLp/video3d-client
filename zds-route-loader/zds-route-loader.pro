TEMPLATE = lib

CONFIG -= qt

CONFIG += plugin
CONFIG += no_plugin_name_prefix

TARGET = zds-route-loader

DESTDIR = ../../plugins

win32 {

    OSG_LIB_DIRECTORY = $$(OSG_BIN_PATH)
    OSG_INCLUDE_DIRECTORY = $(OSG_INCLUDE_PATH)


    CONFIG(debug, debug|release) {

        LIBS += -L$$OSG_LIB_DIRECTORY -losgd
        LIBS += -L$$OSG_LIB_DIRECTORY -losgViewerd
        LIBS += -L$$OSG_LIB_DIRECTORY -losgDBd
        LIBS += -L$$OSG_LIB_DIRECTORY -lOpenThreadsd
        LIBS += -L$$OSG_LIB_DIRECTORY -losgGAd
        LIBS += -L$$OSG_LIB_DIRECTORY -losgUtild

        LIBS += -L../../lib -lroute-loader_d
        LIBS += -L../../lib -lfilesystem_d

    } else {

        LIBS += -L$$OSG_LIB_DIRECTORY -losg
        LIBS += -L$$OSG_LIB_DIRECTORY -losgViewer
        LIBS += -L$$OSG_LIB_DIRECTORY -losgDB
        LIBS += -L$$OSG_LIB_DIRECTORY -lOpenThreads
        LIBS += -L$$OSG_LIB_DIRECTORY -losgGA
        LIBS += -L$$OSG_LIB_DIRECTORY -losgUtil

        LIBS += -L../../lib -lroute-loader
        LIBS += -L../../lib -lfilesystem

    }

    INCLUDEPATH += $$OSG_INCLUDE_DIRECTORY
}

unix {

    CONFIG(debug, debug|release) {

        LIBS += -losgd
        LIBS += -losgViewerd
        LIBS += -losgDBd
        LIBS += -lOpenThreadsd
        LIBS += -losgGAd
        LIBS += -losgUtild

        LIBS += -L../../lib -lroute-loader_d
        LIBS += -L../../lib -lfilesystem_d

    } else {

        LIBS +=  -losg
        LIBS +=  -losgViewer
        LIBS +=  -losgDB
        LIBS +=  -lOpenThreads
        LIBS +=  -losgGA
        LIBS +=  -losgUtil

        LIBS += -L../../lib -lroute-loader
        LIBS += -L../../lib -lfilesystem
    }
}

INCLUDEPATH += ../include
INCLUDEPATH += ../filesystem/include
INCLUDEPATH += ../route-loader/include
INCLUDEPATH += ./include

HEADERS += $$files(./include/*.h)
SOURCES += $$files(./src/*.cpp)

