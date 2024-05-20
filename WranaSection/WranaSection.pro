QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Buildingchoose.cpp \
    ChatWindow.cpp \
    Graph.cpp \
    Groundfloor.cpp \
    Maingraph.cpp \
    Location.cpp \
    Navigation.cpp \
    Schedule.cpp \
    Secondfloorother.cpp \
    ThirdFloor.cpp \
    User_View.cpp \
    cellcourseselection.cpp \
    course.cpp \
    Admin.cpp \
    main.cpp \
    database.cpp \
    Admin_View.cpp \
    scheduleadddelete.cpp \
    undergroundfloor.cpp \
    secondfloor.cpp \
    user.cpp \
    newuser.cpp \
    login.cpp \
    firstfloor_credit.cpp \
    firstfloor_general.cpp

HEADERS += \
    Buildingchoose.h \
    ChatWindow.h \
    Graph.h \
    Groundfloor.h \
    Maingraph.h \
    Location.h \
    Navigation.h \
    Schedule.h \
    Secondfloorother.h \
    ThirdFloor.h \
    User_View.h \
    cellcourseselection.h \
    course.h \
    Admin.h \
    database.h \
    Admin_View.h \
    scheduleadddelete.h \
    undergroundfloor.h \
    secondfloor.h \
    user.h \
    newuser.h \
    login.h \
    firstfloor_credit.h \
    firstfloor_general.h

FORMS += \
    Buildingchoose.ui \
    ChatWindow.ui \
    Groundfloor.ui \
    Navigation.ui \
    Secondfloorother.ui \
    ThirdFloor.ui \
    User_View.ui \
    cellcourseselection.ui \
    newuser.ui \
    login.ui \
    Admin_View.ui \
    scheduleadddelete.ui \
    undergroundfloor.ui \
    secondfloor.ui \
    firstfloor_credit.ui \
    firstfloor_general.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Login-Register.qrc \
    Materials.qrc \
    secondFloor.qrc
