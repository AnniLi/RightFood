#include "FoodItem.h"
#include "xlsxdocument.h"

FoodItem::FoodItem(QObject *parent) : QObject(parent) {
    setFoodItemValue();
}

FoodItem::FoodItem(int rowId, int weight, QString name, QObject *parent)
    :QObject(parent),_rowId(rowId), _weight(weight), _name(name) {
    setFoodItemValue();
}

void FoodItem::setWeight(int weight) {
    if (weight == _weight)
        return;
    _weight = weight;
    emit weightChanged();
}

QVector<int> FoodItem::getFoodItemValue() {
    QVector<int> foodItemValue(_factsCount);

    if (!_weight)
        return foodItemValue.fill(0);

    if (_weight != 100)
        for (int i = 0; i < _factsCount; i++)
            foodItemValue[i] = _foodItemValue[i] * _weight / 100;
    else
        return _foodItemValue;

    return foodItemValue;
}

QString FoodItem::name() {
    return _name;
}
int FoodItem::rowId() {
    return _rowId;
}

void FoodItem::setFoodItemValue() {
    QXlsx::Document xlsx("FoodList.xlsx");
    for (int column = 3; column < 3 + _factsCount; ++column)
        if (QXlsx::Cell *cell = xlsx.cellAt(_rowId, column))
            _foodItemValue.push_back(cell->value().toInt());
}
