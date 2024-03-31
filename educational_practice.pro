QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Переменная окружения - номер тренажера, для которого сконфигурирован проект
# при изменении значения выполнять rebuild проекта (иначе не подтянется актуальное значение)
TRAINING_APPLICATION_NUMBER=1

INCLUDEPATH += $$files("*/", true)

SOURCES += $$files("*.cpp", true)

HEADERS += $$files("*.h", true)

FORMS += $$files("*.ui", true)

DEFINES += TRAINING_APPLICATION_NUMBER=$$TRAINING_APPLICATION_NUMBER

TARGET = TrainingApplication-$$TRAINING_APPLICATION_NUMBER

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
