TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    queue.cpp \
    address.cpp \
    name.cpp \
    person.cpp \
    housingq.cpp \
    func.cpp

HEADERS += \
    queue.h \
    address.h \
    name.h \
    person.h \
    housingq.h \
    func.h

QMAKE_CXXFLAGS = -W -Wall -Wextra -pedantic -ansi
QMAKE_LFLAGS = -W -Wall -Wextra -pedantic -ansi
