#ifndef BETWINDOW_H
#define BETWINDOW_H

#include <QMainWindow>
#include "D:\study\info\Lab3\hashtable.h"

namespace Ui {
class BetWindow;
}

class BetWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BetWindow(HashTable<std::string, int>*,QWidget *parent = nullptr);
    ~BetWindow();

private:
    Ui::BetWindow *ui;
    HashTable<std::string, int> *table;
public slots:
    void addBet();
};

#endif // BETWINDOW_H
