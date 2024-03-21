#ifndef FIRSTEXCERCISEWINDOW_H
#define FIRSTEXCERCISEWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
    class FirstExcerciseWindow;
}
QT_END_NAMESPACE

class FirstExcerciseWindow : public QMainWindow
{
    Q_OBJECT

public:
    FirstExcerciseWindow(QWidget *parent = nullptr);
    ~FirstExcerciseWindow();

private slots:
    void on_id_push_btn_clicked();

private:
    Ui::FirstExcerciseWindow *ui;
};
#endif // FIRSTEXCERCISEWINDOW_H
