#include "qmessageboxdialogsprovider.h"

DialogsManager::DialogsManager() {}

void DialogsManager::showInstruction() {
    QMessageBox* instructionDialog = new QMessageBox(
        QMessageBox::Information, "Информация",
        "<p align='left' style='line-height: 2; font-weight: normal;'>\
Для начала, Вы можете ознакомиться с тренировкой.<br>\
Чтобы Ваши действия записывались, необходимо нажать пункт меню <b>\"Начать тренировку\"</b>.<br>\
Чтобы завершить тренировку, необходимо нажать пункт меню <b>\"Завершить тренировку\"</b>.<br>\
Меню расположено в верхнем левом углу на Вашем экране.</p>",
        QMessageBox::Ok,
        nullptr
    );

    instructionDialog->exec();
}


bool DialogsManager::askForEndTrainingConfirmation() {
    QMessageBox* confirmEndTrainingDialog = new QMessageBox(
        QMessageBox::Question, "Завершить тренировку",
            "Вы уверены, что хотите завершить тренировку?",
            QMessageBox::Yes | QMessageBox::No,
        nullptr
        );

    bool reply = confirmEndTrainingDialog->exec() == QMessageBox::Yes;

    return reply;
}

QString DialogsManager::askForLastNameInput() {
    QString enteredLastName = QInputDialog::getText(nullptr, "Введите фамилию", "Фамилия:");

    return enteredLastName;
}
