QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets xml testlib

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    sources/addcharacterview.cpp \
    lib/sqlite3/sqlite3.c \
    sources/character.cpp \
    sources/database.cpp \
    sources/main.cpp \
    sources/mainwindow.cpp \
    sources/model.cpp \
    sources/testcase.cpp \
    sources/world.cpp \
    sources/worldwindow.cpp

HEADERS += \
    headers/addcharacterview.h \
    headers/model.h \
    headers/character.h \
    lib/sqlite3/sqlite3.h \
    headers/database.h \
    headers/world.h \
    headers/mainwindow.h \
    headers/worldwindow.h \
    lib/sqlite3/sqlite3ext.h


FORMS += \
    UI/mainwindow.ui \
    UI/worldwindow.ui \
    UI/addcharacterview.ui

SUBDIRS = assets
SUBDIRS += assets/html
SUBDIRS += assets/html/character.html

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    README.md
