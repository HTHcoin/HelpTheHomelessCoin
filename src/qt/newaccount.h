#ifndef NEWACCOUNT_H
#define NEWACCOUNT_H

#include <QMainWindow>
#include "mainwindow.h"
namespace Ui {
class newAccount;
}

class newAccount : public QWidget
{
    Q_OBJECT

public:
    explicit newAccount(QWidget *parent = 0);
    ~newAccount();
    int id;


public Q_SLOTS:
    void setLoginPtr(MainWindow *ptr);


private Q_SLOTS:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::newAccount *ui;

    MainWindow *mainWindowPtr;
};

#endif // NEWACCOUNT_H
