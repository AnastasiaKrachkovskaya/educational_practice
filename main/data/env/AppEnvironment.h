#ifndef APPENVIRONMENT_H
#define APPENVIRONMENT_H

#define MIN_TRAINING_APP_NUMBER 1
#define MAX_TRAINING_APP_NUMBER 3

/*!
 * \brief Всего три тренажера. Номер тренажера (для отображения на экране) присваеиваем переменной.
 * Также, производим проверку номера. Если он выходит за пределы (1-3), то сообщаем об этом.
 */

enum class TrainingAppNumber {
    FIRST = MIN_TRAINING_APP_NUMBER,
    SECOND,
    THIRD = MAX_TRAINING_APP_NUMBER
};

static constexpr TrainingAppNumber getTrainingAppNumber() {
    const int trainingAppNubmerInt = static_cast<int>(TRAINING_APPLICATION_NUMBER);
    static_assert(trainingAppNubmerInt <= MAX_TRAINING_APP_NUMBER && trainingAppNubmerInt >= MIN_TRAINING_APP_NUMBER,
                  "Недопустимое значение номера тренажера в конфигурации приложения");
    return static_cast<TrainingAppNumber>(trainingAppNubmerInt);
}

class AppEnvironment final {
private:
    AppEnvironment() {};

public:
    static const TrainingAppNumber trainingAppNumber = getTrainingAppNumber();
};

#endif // APPENVIRONMENT_H
