QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    main/data \
    main/models \
    main/domain \
    main/presentation/appState \
    main/presentation/excerciseWindowState \
    main/presentation/firstWindow \

SOURCES += \
    main/main.cpp \
    main/data/ActionsRepository.cpp \
    main/presentation/appState/AppStateStore.cpp \
    main/presentation/excerciseWindowState/ExcerciseWindowStateStore.cpp \
    main/presentation/firstWindow/FirstExcerciseWindow.cpp \

HEADERS += \
    main/models/Actions.h \
    main/data/ActionsRepository.h \
    main/presentation/appState/AppStateStore.h \
    main/presentation/excerciseWindowState/ExcerciseWindowState.h \
    main/presentation/excerciseWindowState/ExcerciseWindowStateStore.h \
    main/presentation/firstWindow/FirstExcerciseWindow.h \

FORMS += \
    main/presentation/firstWindow/FirstExcerciseWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
