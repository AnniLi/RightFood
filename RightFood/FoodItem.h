#ifndef FOOD_ITEM_H
#define FOOD_ITEM_H

#include <QObject>
#include <QVector>

class FoodItem : public QObject {
    Q_OBJECT

public:
    FoodItem(QObject *parent = 0);
    FoodItem(int rowId, int weight, QString name, QObject *parent = 0);
    QVector<int> getFoodItemValue();
    QString name();
    int rowId();

signals:
    void weightChanged();

public slots:
    void setWeight(int weight);

private:
    int _rowId;
    QString _name;
    int _weight;
    QVector<int> _foodItemValue;
    const int _factsCount = 30;

    void setFoodItemValue();
};

#endif // FOOD_ITEM_H
