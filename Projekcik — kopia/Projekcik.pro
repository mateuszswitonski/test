TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Enemy.cpp \
        Enemy_waves.cpp \
        Game.cpp \
        Identity_matrix.cpp \
        Orthogonal_matrix.cpp \
        Regular_matrix.cpp \
        Schmidt_boss.cpp \
        main.cpp
INCLUDEPATH += C:/Users/Matsa/Desktop/STUDIA/SFML-2.6.2-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.2/include

LIBS += -LC:/Users/Matsa/Desktop/STUDIA/SFML-2.6.2-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.2/lib\
        -lsfml-graphics -lsfml-window -lsfml-system

HEADERS += \
    Bullett.h \
    Enemy.h \
    Enemy_waves.h \
    Game.h \
    Game.h \
    Game.h \
    Game.h \
    Identity_matrix.h \
    Orthogonal_matrix.h \
    Regular_matrix.h \
    Schmidt_boss.h
