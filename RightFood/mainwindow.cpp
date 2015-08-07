#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "FoodItem.h"
#include "DailyRecommendedNutrition.h"
#include "xlsxdocument.h"
#include <QFile>
#include <QStringListModel>
#include <QInputDialog>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    DailyRecommendedNutrition* dailyRecommendedNutrition = new DailyRecommendedNutrition;
    _dailyNutrition = dailyRecommendedNutrition->getDailyRecommendedNutrition();
    _totalNutrion = new TotalNutrition();

    getBars();
    barsInit();

    completer = new QCompleter(this);
    completer->setModel(modelFromFile());
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setCompletionMode(QCompleter::PopupCompletion);
    ui->lineEdit->setCompleter(completer);

    ui->tableWidget->insertColumn(0);
    ui->tableWidget->insertColumn(1);





}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::foodAdedToRation(int rowId, QString name, int weight) {
    _totalNutrion->add(rowId, weight);

    //table widget
    int rows = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rows);

    QTableWidgetItem *item;
    item = new QTableWidgetItem(QString("%1").arg(weight));
    item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    ui->tableWidget->setItem(rows,1,item);

    item = new QTableWidgetItem(name);
    item->setFlags(item->flags() & ~Qt::ItemIsEditable); // non editable
    ui->tableWidget->setItem(rows,0,item);
}



void MainWindow::barsInit() {
    _nutritionBarList.resize(_barCount);
    for (int i = 0; i < _barCount; i++)
        if (_nutritionBarList[i] != nullptr) {
            _nutritionBarList[i]->setMaximum(_dailyNutrition[i]);
            _nutritionBarList[i]->setValue(0);
        }
}

void MainWindow::getBars() {
    //bars tie
    _nutritionBarList.push_back(ui->progressBar_1);
    _nutritionBarList.push_back(ui->progressBar_2);
    _nutritionBarList.push_back(ui->progressBar_3);
    _nutritionBarList.push_back(ui->progressBar_4);
    _nutritionBarList.push_back(ui->progressBar_5);
    _nutritionBarList.push_back(ui->progressBar_6);
    _nutritionBarList.push_back(ui->progressBar_7);
    _nutritionBarList.push_back(ui->progressBar_8);
    _nutritionBarList.push_back(ui->progressBar_9);
    _nutritionBarList.push_back(ui->progressBar_10);
    _nutritionBarList.push_back(ui->progressBar_11);
    _nutritionBarList.push_back(ui->progressBar_12);
    _nutritionBarList.push_back(ui->progressBar_13);
    _nutritionBarList.push_back(ui->progressBar_14);
    _nutritionBarList.push_back(ui->progressBar_15);
    _nutritionBarList.push_back(ui->progressBar_16);
    _nutritionBarList.push_back(ui->progressBar_17);
    _nutritionBarList.push_back(ui->progressBar_18);
    _nutritionBarList.push_back(ui->progressBar_19);
    _nutritionBarList.push_back(ui->progressBar_20);
    _nutritionBarList.push_back(ui->progressBar_21);
    _nutritionBarList.push_back(ui->progressBar_22);
    _nutritionBarList.push_back(ui->progressBar_23);
    _nutritionBarList.push_back(ui->progressBar_24);
    _nutritionBarList.push_back(ui->progressBar_25);
    _nutritionBarList.push_back(ui->progressBar_26);
    _nutritionBarList.push_back(ui->progressBar_27);
    _nutritionBarList.push_back(ui->progressBar_28);
    _nutritionBarList.push_back(ui->progressBar_29);
    _nutritionBarList.push_back(ui->progressBar_30);
}

QAbstractItemModel *MainWindow::modelFromFile() {
    QXlsx::Document xlsx(_tableName);
    QStringList foodItems;
    for (int row = 2; ; row++) {
        if (QXlsx::Cell *cell = xlsx.cellAt(row, 2))
            foodItems.push_back(cell->value().toString());
        else break;
    }
    if (foodItems.size() == 0)
        return new QStringListModel(completer);

    return new QStringListModel(foodItems, completer);
}

void MainWindow::on_toolButton_clicked() {
    bool bOk;
    QString foodName = ui->lineEdit->text();
    QString foodWeight = QInputDialog::getText( 0,
                                         "Input",
                                         foodName  + ", грамм:",
                                         QLineEdit::Normal,
                                         "Введите вес",
                                         &bOk
                                        );
    if (bOk) {
        QXlsx::Document xlsx(_tableName);
        int rowId = 0;
        for (int row = 2; ; row++) {
            if (QXlsx::Cell *cell = xlsx.cellAt(row, 2)) {
                if(cell->value().toString() == foodName){
                    rowId = row;
                    emit foodAdedToRation(rowId, foodName, foodWeight.toInt());
                    return;
                }
            }
            else return;
        }
    }
    ui->lineEdit->setText("");
}
