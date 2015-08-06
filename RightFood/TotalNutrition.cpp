#include "TotalNutrition.h"

TotalNutrition::TotalNutrition(QObject *parent) : QObject(parent) {
    connect(this, SIGNAL(rationChanged()), SLOT(setTotalNutrion()));
}

void TotalNutrition::add(int rowId, int weight) {
    FoodItem* foodItem = new FoodItem(rowId, weight);
    _rationList.push_back(foodItem);
    emit rationChanged();
}

void TotalNutrition::setTotalNutrion() {
    foreach (FoodItem* foodItem, _rationList)
        if (foodItem != nullptr) {
            const QVector<int> foodItemValues = foodItem->getFoodItemValue();
            _totalNutrition += foodItemValues;
        }
    emit totalNutritionChanged();
}

QVector<int> TotalNutrition::getTotalNutrion() {
    return _totalNutrition;
}

void TotalNutrition::remove(QString foodName) {
    for (int i = 0; i < _rationList.count(); i++) {
        if (_rationList[i] == nullptr)
            break;
        if (_rationList[i]->name() == foodName) {
            delete _rationList[i];
            _rationList.removeAt(i);
            emit rationChanged();
            return;
        }
    }
}




