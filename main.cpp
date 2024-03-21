#include "FirstExcerciseWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FirstExcerciseWindow w;
    w.show();
    return a.exec();
}
