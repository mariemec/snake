TEMPLATE = vcapp
TARGET = snake
SOURCES += snake.cpp main.cpp fruit.cpp border.cpp Menu.cpp Game.cpp HighScores.cpp
HEADERS += snake.h fruit.h defines.h border.h Menu.h Game.h HighScores.h
INCLUDEPATH += ../snakescene
CONFIG += warn_on qt debug windows console
QT += widgets
