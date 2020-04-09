TEMPLATE = vcapp
TARGET = snake
SOURCES += snake.cpp main.cpp fruit.cpp border.cpp
HEADERS += snake.h fruit.h defines.h border.h
INCLUDEPATH += ../snakescene
CONFIG += warn_on qt debug windows console
QT += widgets