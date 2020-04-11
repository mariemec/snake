TEMPLATE = vcapp
TARGET = snake
SOURCES += snake.cpp main.cpp fruit.cpp score.cpp
HEADERS += snake.h fruit.h defines.h score.h
INCLUDEPATH += ../snakescene
CONFIG += warn_on qt debug windows console
QT += widgets