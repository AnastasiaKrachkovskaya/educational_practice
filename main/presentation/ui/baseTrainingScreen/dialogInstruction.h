#ifndef DIALOGINSTRUCTION_H
#define DIALOGINSTRUCTION_H

#include <QDialog>
#include "ui_dialogInstruction.h"

namespace Ui {
class DialogInstruction;
}

class DialogInstruction : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInstruction(QWidget *parent = nullptr);
    ~DialogInstruction();

private:
    Ui::DialogInstruction *ui;
};

#endif // DIALOGINSTRUCTION_H