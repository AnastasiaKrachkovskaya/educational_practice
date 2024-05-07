#ifndef DIALOGSMANAGER_H
#define DIALOGSMANAGER_H

#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>
#include <QString>
#include "ReplayTrainingSpeedFactorSelectionDialog.h"

/*!
 * \brief The DialogsManager class
 * Класс менеджера для работы с диалогами
 */
class DialogsManager
{
private:
    DialogsManager();
public:
    static void showInstruction();

    static bool requestEndTrainingConfirm();

    static QString requestLastNameInput();

    static QString requestReplayTrainingFilePath();

    static double requestReplayTrainingSpeedFactor();
};

#endif // DIALOGSMANAGER_H
