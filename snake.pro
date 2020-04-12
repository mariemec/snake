TEMPLATE = vcapp
TARGET = snake
INCLUDEPATH += ../snake ./headers ./source
SOURCES += ./source/snake.cpp ./source/main.cpp ./source/fruit.cpp ./source/Menu.cpp ./source/Game.cpp ./source/HighScores.cpp ./source/Score.cpp
HEADERS += ./headers/snake.h ./headers/fruit.h ./headers/defines.h ./headers/Menu.h ./headers/Game.h ./headers/HighScores.h ./headers/Score.h
CONFIG += warn_on qt debug windows console
QT += widgets
RC_FILE = snake.rc
