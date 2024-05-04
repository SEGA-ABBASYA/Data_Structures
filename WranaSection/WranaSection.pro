QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Graph.cpp \
    Maingraph.cpp \
    Location.cpp \
    Schedule.cpp \
    course.cpp \
    Admin.cpp \
    main.cpp \
    database.cpp \
    Admin_View.cpp \
    user.cpp \
    Location.cpp
    mainwindow.cpp \
    user.cpp \
    newuser.cpp \
    login.cpp

HEADERS += \
    Graph.h \
    Maingraph.h \
    Location.h \
    Schedule.h \
    course.h \
    Admin.h \
    database.h \
    Admin_View.h \
    user.h
FORMS += \
    Admin_View.ui
    mainwindow.h \
    user.h \
    newuser.h \
    login.h

FORMS += \
    mainwindow.ui \
    newuser.ui \
    login.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Login-Register.qrc \
    Materials.qrc
