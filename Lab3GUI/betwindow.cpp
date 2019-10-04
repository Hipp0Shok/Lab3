#include "betwindow.h"
#include "ui_betwindow.h"
#include "QRegExpValidator"
#include "mainwindow.h"

BetWindow::BetWindow(HashTable<std::string, int> *parentTable, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BetWindow)
{
    ui->setupUi(this);
    QRegExp text(".+");
    QRegExp number("[0-9]+");
    ui->betEdit->setValidator(new QRegExpValidator(number, this));
    ui->nameEdit->setValidator(new QRegExpValidator(text, this));
    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addBet()));
    table = parentTable;
}

BetWindow::~BetWindow()
{
    delete ui;
}

void BetWindow::addBet()
{
    QPalette warningPalette, defaultPallete;
    warningPalette.setColor(QPalette::Base, Qt::red);
    if(ui->nameEdit->text().isEmpty())
    {
        ui->nameEdit->setPalette(warningPalette);

    }
    else {
        ui->nameEdit->setPalette(defaultPallete);
        if(ui->betEdit->text().toInt() == 0)
        {
            ui->betEdit->setPalette(warningPalette);
        }
        else
        {
            table->addPair(ui->nameEdit->text().toStdString(), ui->betEdit->text().toInt());
            static_cast<MainWindow*>(parent())->updateTable();
            this->close();
        }
    }


}

