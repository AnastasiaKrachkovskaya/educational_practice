#ifndef QMESSAGEBOXDIALOGSPROVIDER_H
#define QMESSAGEBOXDIALOGSPROVIDER_H

#include <QMessageBox>
#include <QInputDialog>
#include <QString>

class DialogsManager
{
private:
    DialogsManager();
public:
    static void showInstruction();

    static bool askForEndTrainingConfirmation();

    static QString askForLastNameInput();
};

#endif // QMESSAGEBOXDIALOGSPROVIDER_H
