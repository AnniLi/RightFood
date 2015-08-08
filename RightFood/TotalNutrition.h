#ifndef TOTAL_NUTRITION_H
#define TOTAL_NUTRITION_H

#include <QObject>
#include <QVector>
#include "FoodItem.h"

class TotalNutrition : public QObject {
    Q_OBJECT

public:
    TotalNutrition(QObject *parent = 0);
    void add(int rowId, int weight, QString name);
    void remove(QString name);
    QVector<int> getTotalNutrion();

public slots:
    void changeWeight(int rowId, int weight);

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
