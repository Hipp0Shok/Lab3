#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTableWidget"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTable()
{
    HashTable<char*, float>::Iterator iter;
    QTableWidgetItem *object;
    if(table.getLength() != 0)
    {
        iter = table.begin();
        int i = 0;
        do
        {
            object = new QTableWidgetItem(QString(*iter));
            ui->tableWidget->setItem(i, 0, object);
            object = new QTableWidgetItem(QString::number(iter.getValue()));
            ui->tableWidget->setItem(i, 1, object);
        }while(iter++ != table.end());
    }
}
