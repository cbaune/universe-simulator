TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    simulation/universe.cpp \
    simulation/object.cpp \
    simulation/vec.cpp \
    preset/presetobject.cpp \
    simulation/forces/force.cpp \
    simulation/forces/gravitation.cpp \
    simulation/objectcontainer.cpp \
    simulation/forces/collision.cpp \
    ui/game.cpp \
    ui/window.cpp

HEADERS += \
    simulation/universe.h \
    simulation/object.h \
    simulation/vec.h \
    simulation/types.h \
    simulation/constants.h \
    preset/presetobject.h \
    simulation/forces/force.h \
    simulation/forces/gravitation.h \
    simulation/objectcontainer.h \
    simulation/forces/collision.h \
    ui/game.h \
    ui/window.h

OTHER_FILES += \
    simulation.plt

LIBS += -L/usr/include/allegro5 -lallegro -lallegro_primitives -lallegro_font -lallegro_ttf
