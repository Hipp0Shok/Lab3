#include "profitwindow.h"
#include "ui_profitwindow.h"

ProfitWindow::ProfitWindow(int profit,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProfitWindow)
{
    ui->setupUi(this);
    ui->profitLabel->setText(QString::number(profit));

}

ProfitWindow::~ProfitWindow()
{
    delete ui;
}
