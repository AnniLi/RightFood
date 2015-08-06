#include "DailyRecommendedNutrition.h"

DailyRecommendedNutrition::DailyRecommendedNutrition() {
    setDailyRecommendedNutrition();
}

QVector<int> DailyRecommendedNutrition::getDailyRecommendedNutrition() {
    return _dailyRecommendedNutritionValue;
}

void DailyRecommendedNutrition::setDailyRecommendedNutrition() {
    _dailyRecommendedNutritionValue.append(1500);//kkal
    _dailyRecommendedNutritionValue.append(80 * 10000);//protein
    _dailyRecommendedNutritionValue.append(100 * 10000);//fat
    _dailyRecommendedNutritionValue.append(100 * 10000);//carb
    _dailyRecommendedNutritionValue.append(1000000);//omega
    _dailyRecommendedNutritionValue.append(800 * 10000);//vA
    _dailyRecommendedNutritionValue.append(1300 * 10000);//vB1
    _dailyRecommendedNutritionValue.append(1300 * 10000);//vB2
    _dailyRecommendedNutritionValue.append(16000);//vB3
    _dailyRecommendedNutritionValue.append(6500);//vB5
    _dailyRecommendedNutritionValue.append(1800 * 10000);//vB6
    _dailyRecommendedNutritionValue.push_back(90 * 10000);//B7
    _dailyRecommendedNutritionValue.push_back(350 * 10000);//B9
    _dailyRecommendedNutritionValue.push_back(3 * 10000); //B12
    _dailyRecommendedNutritionValue.push_back(60000);//vC
    _dailyRecommendedNutritionValue.push_back(10 * 10000); //vD
    _dailyRecommendedNutritionValue.push_back(5333);//vE
    _dailyRecommendedNutritionValue.push_back(65 * 10000);//vK
    _dailyRecommendedNutritionValue.push_back(20000);//Fe
    _dailyRecommendedNutritionValue.push_back(1200000);//Ca
    _dailyRecommendedNutritionValue.push_back(150 * 10000);//I
    _dailyRecommendedNutritionValue.push_back(4700000);//K
    _dailyRecommendedNutritionValue.push_back(310000);//Mg
    _dailyRecommendedNutritionValue.push_back(3000);//Cu
    _dailyRecommendedNutritionValue.push_back(1500000);//P
    _dailyRecommendedNutritionValue.push_back(2500);//F
    _dailyRecommendedNutritionValue.push_back(8000);//Zn
    _dailyRecommendedNutritionValue.push_back(110 * 1000);//Se
    _dailyRecommendedNutritionValue.push_back(550000);//N
    _dailyRecommendedNutritionValue.push_back(4000);//Mn
}

