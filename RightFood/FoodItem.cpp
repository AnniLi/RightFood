#include "FoodItem.h"
#include "xlsxdocument.h"

FoodItem::FoodItem(QObject *parent) : QObject(parent) {

}

FoodItem::FoodItem(int rowId, int weight, QObject *parent)
    :QObject(parent),_rowId(rowId), _weight(weight) {
    _name = "";
}

void FoodItem::setWeight(int weight) {
    if (weight == _weight)
        return;
    _weight = weight;
    emit weightChanged();
}

QVector<int> FoodItem::getFoodItemValue() {
    QVector<int> foodItemValue(_foodItemValue);

    if (_weight = 0)
        return foodItemValue.fill(0);

    if (_weight != 100)
        foreach (int fact, foodItemValue)
            fact = fact * _weight / 100;

    return foodItemValue;
}

QString FoodItem::name() {
    return _name;
}

void FoodItem::setFoodItemValue() {
    QXlsx::Document xlsx("FoodList.xlsx");
    for (int column = 3; column < 3 + _factsCount; ++column)
        if (QXlsx::Cell *cell = xlsx.cellAt(_rowId, column))
            _foodItemValue.push_back(cell->value().toInt());
}
