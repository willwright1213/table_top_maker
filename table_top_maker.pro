QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets xml

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    lib/sqlite3/sqlite3.c \
    sources/database.cpp \
    sources/era.cpp \
    sources/main.cpp \
    sources/mainwindow.cpp \
    sources/world.cpp \
    sources/worldwindow.cpp

HEADERS += \
    headers/xml.h \
    lib/sqlite3/sqlite3.h \
    headers/database.h \
    headers/world.h \
    headers/era.h \
    headers/mainwindow.h \
    headers/worldwindow.h


FORMS += \
    UI/mainwindow.ui \
    UI/worldwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
