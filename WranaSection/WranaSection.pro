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
    ThirdFloor.cpp \
    User_View.cpp \
    course.cpp \
    Admin.cpp \
    main.cpp \
    database.cpp \
    Admin_View.cpp \
    undergroundfloor.cpp \
    user.cpp \
    newuser.cpp \
    login.cpp

HEADERS += \
    Graph.h \
    Maingraph.h \
    Location.h \
    Schedule.h \
    ThirdFloor.h \
    User_View.h \
    course.h \
    Admin.h \
    database.h \
    Admin_View.h \
    undergroundfloor.h \
    user.h \
    newuser.h \
    login.h

FORMS += \
    ThirdFloor.ui \
    User_View.ui \
    newuser.ui \
    login.ui \
    Admin_View.ui \
    undergroundfloor.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Login-Register.qrc \
    Materials.qrc
