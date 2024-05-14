#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "list.h"
#include "company.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private slots:

    void on_pushButton_add_clicked();

    void on_radioButton_profit_clicked();

    void on_radioButton_noprofit_clicked();

    void printList(list);

    void openList();

    void addtoView(QString name,QString datestr,QString employeestr,QString charitablestr,bool);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
