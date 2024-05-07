#ifndef REPLAYTRAININGSPEEDFACTORSELECTIONDIALOG_H
#define REPLAYTRAININGSPEEDFACTORSELECTIONDIALOG_H

#include <QDialog>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

using namespace std;

/*!
 * \brief The ReplayTrainingSpeedFactorSelectionDialog class
 * Диалог выбора скорости воспроизведения
 */
class ReplayTrainingSpeedFactorSelectionDialog : public QDialog {
    Q_OBJECT

public:
    ReplayTrainingSpeedFactorSelectionDialog(QWidget *parent = nullptr) : QDialog(parent), comboBox(new QComboBox(this)) {
        setWindowTitle("Выберите скорость воспроизведения записи тренировки");

        for(auto speedFactorToUiString: speedFactorsToUiStrings) {
            QString comboBoxString = QString::fromStdString(speedFactorToUiString.second);
            comboBox->addItem(comboBoxString);
        }

        QPushButton *okButton = new QPushButton("OK");
        //QPushButton *cancelButton = new QPushButton("Отмена");

        // Слоты для кнопок
        connect(okButton, &QPushButton::clicked, this, &ReplayTrainingSpeedFactorSelectionDialog::accept);
        //connect(cancelButton, &QPushButton::clicked, this, &ReplayTrainingSpeedFactorSelectionDialog::reject);

        // Расположение элементов в диалоге
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(comboBox);

        QHBoxLayout *buttonLayout = new QHBoxLayout();
        buttonLayout->addWidget(okButton);
        //buttonLayout->addWidget(cancelButton);
        layout->addLayout(buttonLayout);
    }

    double getSelectedReplayTrainingSpeedFactor() const {
        double speedFactor = speedFactorsToUiStrings.at(comboBox->currentIndex()).first;
        qDebug() << "Selected speed factor = " + to_string(speedFactor);
        return speedFactor;
    }

private:
    QComboBox *comboBox;
    array<pair<double, string>, 5> speedFactorsToUiStrings = { { {0.5, "0.5x"}, {1, "1x"}, {1.5, "1.5x"}, {2, "2x"}, {3, "3x"} } };
};

#endif // REPLAYTRAININGSPEEDFACTORSELECTIONDIALOG_H
