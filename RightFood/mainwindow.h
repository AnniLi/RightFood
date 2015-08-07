#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QProgressBar>
#include "TotalNutrition.h"
#include <QAbstractItemModel>
#include <QCompleter>
#include <QTableWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void foodAdedToRation(int, QString, int);

private slots:
    void on_toolButton_clicked();
    void setBars();

private:
    Ui::MainWindow *ui;
    QList<int> _rationList;
    QVector<QProgressBar*> _nutritionBarList;
    const int _barCount = 30;
    QVector<int> _dailyNutrition;
    TotalNutrition *_totalNutrion;
    const QString _tableName = "FoodList.xlsx";

    void barsInit();
    void getBars();

    QAbstractItemModel *modelFromFile();
    QCompleter *completer;
};

#endif // MAINWINDOW_H
