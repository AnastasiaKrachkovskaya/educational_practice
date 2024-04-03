#ifndef DIALOGFINISH_H
#define DIALOGFINISH_H

#include <QDialog>

namespace Ui {
class DialogFinish;
}

class DialogFinish : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFinish(QWidget *parent = nullptr);
    ~DialogFinish();

private:
    Ui::DialogFinish *ui;
};

#endif // DIALOGFINISH_H
