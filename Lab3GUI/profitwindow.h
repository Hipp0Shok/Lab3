#ifndef PROFITWINDOW_H
#define PROFITWINDOW_H

#include <QMainWindow>

namespace Ui {
class ProfitWindow;
}

class ProfitWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProfitWindow(int profit, QWidget *parent = nullptr);
    ~ProfitWindow();

private:
    Ui::ProfitWindow *ui;
};

#endif // PROFITWINDOW_H
