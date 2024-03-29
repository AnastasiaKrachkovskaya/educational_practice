QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    data \
    models \
    domain \
    presentation/appState \
    presentation/excerciseWindowState \
    presentation/firstWindow \

SOURCES += \
    main.cpp \
    data/ActionsRepository.cpp \
    presentation/appState/AppStateStore.cpp \
    presentation/excerciseWindowState/ExcerciseWindowState.cpp \
    presentation/firstWindow/FirstExcerciseWindow.cpp \

HEADERS += \
    models/Actions.h \
    data/ActionsRepository.h \
    presentation/appState/AppStateStore.h \
    presentation/excerciseWindowState/ExcerciseWindowState.h \
    presentation/firstWindow/FirstExcerciseWindow.h \

FORMS += \
    presentation/firstWindow/FirstExcerciseWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
