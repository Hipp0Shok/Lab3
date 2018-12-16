#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "D:\study\info\Lab3\hashtable.h"
#include "string.h"
#include "betwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateTable();
private:
    Ui::MainWindow *ui;
    HashTable<std::string, int> table;
public slots:
    void openFile();
    void saveFile();
    void makeAddWindow();
    void profit();

};

#endif // MAINWINDOW_H
