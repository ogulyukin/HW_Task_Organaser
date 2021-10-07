QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
win32 : RC_ICONS += favicon.ico
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addedittaskdialog.cpp \
    io.cpp \
    main.cpp \
    priority.cpp \
    setcolorsdialog.cpp \
    task.cpp \
    taskadddialog.cpp \
    tasllist.cpp

HEADERS += \
    addedittaskdialog.h \
    io.h \
    priority.h \
    setcolorsdialog.h \
    task.h \
    taskadddialog.h \
    tasllist.h

FORMS += \
    addedittaskdialog.ui \
    setcolorsdialog.ui \
    taskadddialog.ui \
    tasllist.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
