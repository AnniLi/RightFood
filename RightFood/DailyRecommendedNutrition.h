#ifndef DAILY_RECOMMENDED_NUTRITION_H
#define DAILY_RECOMMENDED_NUTRITION_H

#include <QVector>

class DailyRecommendedNutrition {
public:
    DailyRecommendedNutrition();
    QVector<int> getDailyRecommendedNutrition();

private:
    QVector<int> _dailyRecommendedNutritionValue;
    void setDailyRecommendedNutrition();
};

#endif // DAILY_RECOMMENDED_NUTRITION_H
