#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTableWidget"
#include "QFileDialog"
#include "fstream"
#include "profitwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    connect(ui->openButton, SIGNAL(clicked()), this, SLOT(openFile()));
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveFile()));
    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(makeAddWindow()));
    connect(ui->profitButton, SIGNAL(clicked()), this, SLOT(profit()));
    ui->saveButton->setDisabled(true);
    ui->profitButton->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTable()
{
    HashTable<std::string, int>::Iterator iter;
    QTableWidgetItem *object;
    if(table.getLength() != 0)
    {
        iter = table.begin();
        ui->tableWidget->setRowCount(table.getLength());
        ui->saveButton->setDisabled(false);
        ui->profitButton->setDisabled(false);
        int i = 0;
        do
        {
            object = new QTableWidgetItem();
            object->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            object->setText(QString::fromStdString(*iter));
            ui->tableWidget->setItem(i, 0, object);
            object = new QTableWidgetItem();
             object->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            object->setText(QString::number(iter.getValue()));
            ui->tableWidget->setItem(i, 1, object);
            i++;
        }while(iter++ != table.end());
    }
}

void MainWindow::openFile()
{
    QString filename;
    filename = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("*.txt"));
    if(!filename.isEmpty())
    {
        std::ifstream file;
        file.open(filename.toStdString(), std::ios::in);
        file >> table;
        file.close();
    }
    updateTable();
}

void MainWindow::saveFile()
{
    if(table.getLength() != 0)
    {
        QString filename;
        filename = QFileDialog::getSaveFileName(this, "Сохранить файл как", "", "*.txt");
        std::ofstream file;
        file.open(filename.toStdString(), std::ios::out);
        file << table;
        file.close();
    }
}

void MainWindow::makeAddWindow()
{
    BetWindow *win;
    win = new BetWindow(&table, this);
    win->setWindowTitle("Add Bet");
    win->show();
}

void MainWindow::profit()
{
    ProfitWindow *win = new ProfitWindow(table.bankProfit(), this);
    win->show();
}
