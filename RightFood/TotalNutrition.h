#ifndef TOTAL_NUTRITION_H
#define TOTAL_NUTRITION_H

#include <QObject>
#include <QVector>
#include "FoodItem.h"

class TotalNutrition : public QObject {
    Q_OBJECT

public:
    TotalNutrition(QObject *parent = 0);
    void add(int rowId, int weight);
    void remove(QString foodName);
    QVector<int> getTotalNutrion();

signals:
    void rationChanged();
    void totalNutritionChanged();

private:
    QVector<int> _totalNutrition;
    QVector<FoodItem*> _rationList;
    const int _factsCount = 30;

private slots:
    void setTotalNutrion();
};

#endif // TOTAL_NUTRITION_H
