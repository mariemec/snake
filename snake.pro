TEMPLATE = subdirs
TARGET = snake
INCLUDEPATH += ../P-13
SUBDIRS += Source/
SOURCES += snake.cpp main.cpp fruit.cpp border.cpp Menu.cpp Game.cpp HighScores.cpp Score.cpp
HEADERS += snake.h fruit.h defines.h border.h Menu.h Game.h HighScores.h Score.h
CONFIG += warn_on qt debug windows console
QT += widgets
