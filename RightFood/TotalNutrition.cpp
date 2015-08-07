#include "TotalNutrition.h"

TotalNutrition::TotalNutrition(QObject *parent) : QObject(parent) {
    connect(this, SIGNAL(rationChanged()), SLOT(setTotalNutrion()));

}

void TotalNutrition::add(int rowId, int weight) {
    FoodItem* foodItem = new FoodItem(rowId, weight);
    connect(foodItem, SIGNAL(weightChanged()), this, SLOT(setTotalNutrion()));
    _rationList.push_back(foodItem);
    emit rationChanged();
}

void TotalNutrition::setTotalNutrion() {
    _totalNutrition.fill(0, _factsCount);
    foreach (FoodItem* foodItem, _rationList)
        if (foodItem != nullptr) {
            QVector<int> foodItemValues = foodItem->getFoodItemValue();
            for(int i = 0; i < _factsCount; i++)
                _totalNutrition[i] += foodItemValues[i];
        }
    emit totalNutritionChanged();
}

QVector<int> TotalNutrition::getTotalNutrion() {
    return _totalNutrition;
}

void TotalNutrition::remove(int rowId) {
    for (int i = 0; i < _rationList.count(); i++) {
        if (_rationList[i] == nullptr)
            break;
        if (_rationList[i]->rowId() == rowId) {
            FoodItem* foodItem = _rationList[i];
            disconnect(foodItem, SIGNAL(weightChanged()), this, SLOT(setTotalNutrion()));
            delete foodItem;
            _rationList.removeAt(i);
            emit rationChanged();
            return;
        }
    }
}

void TotalNutrition::changeWeight(int rowId, int weight) {
    foreach (FoodItem* foodItem, _rationList)
        if (foodItem != nullptr)
            if (foodItem->rowId() == rowId) {
                foodItem->setWeight(weight);
                return;
            }
}




