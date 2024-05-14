#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "company.h"
#include "list.h"
#include <QFile>
#include <QTextStream>
#include <QMetaProperty>
#include "companyprofit.h"
#include "companynonprofit.h"


list listCompany;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->radioButton_profit->setChecked(true);
    ui->checkBox->setEnabled(false);
    ui->label_Char->setEnabled(false);
    ui->dateEdit->setDate(QDate::currentDate());


    openList();
}

MainWindow::~MainWindow()
{
    printList(listCompany);
    delete ui;
}
void MainWindow::printList(list tmp)
{
    QList <QObject*> non = tmp.getCompany("non");
    QList <QObject*> prof = tmp.getCompany("profit");

    QFile file("non.txt");
    file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);
    QTextStream toFile(&file);


    for(int k = 0; k < non.count(); k++)
    {

        const QMetaObject *mo = non[k]->metaObject();

        for( int i = 1; i < mo->propertyCount(); i++)
        {

            QMetaProperty prop = mo->property(i);
            QVariant value = prop.read(non[k]);
            QString valStr = value.toString();

            toFile << valStr << ",";
        }
        toFile << Qt::endl;
    }

    file.close();

    QFile file2("prof.txt");
    file2.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);
    QTextStream toFile2(&file2);


    for(int k = 0; k < prof.count(); k++)
    {

        const QMetaObject *mo = prof[k]->metaObject();

        for( int i = 1; i < mo->propertyCount(); i++)
        {

            QMetaProperty prop = mo->property(i);
            QVariant value = prop.read(prof[k]);
            QString valStr = value.toString();

            toFile2 << valStr << ",";
        }
        toFile2 << Qt::endl;
    }

    file2.close();

}
void MainWindow::openList()
{
    QFile f("non.txt");
    f.open(QIODevice::ReadOnly);
    QTextStream s(&f);

    while (!s.atEnd())
    {
        QString line = s.readLine();
        QStringList fields = line.split(",");
        QVariantList tmp;

        for(int k = 0; k < fields.size(); k++)
        {
            tmp.append(fields[k]);
        }
        Company * non = new CompanyNonProfit(tmp[0].toString(),tmp[1].toDate(),tmp[2].toInt(),tmp[3].toBool(),tmp[4].toBool());
        listCompany.addCompany(non);
        addtoView(fields[0],fields[1],fields[2],fields[4],false);
    }

    f.close();

    QFile t("prof.txt");
    t.open(QIODevice::ReadOnly);
    QTextStream c(&t);

    while (!c.atEnd())
    {
        QString line2 = c.readLine();
        QStringList fields2 = line2.split(",");
        QVariantList tmp2;

        for(int k = 0; k < fields2.size(); k++)
        {
            tmp2.append(fields2[k]);
        }
        Company * prof = new CompanyProfit(tmp2[0].toString(),tmp2[1].toDate(),tmp2[2].toInt(),tmp2[3].toBool());
        listCompany.addCompany(prof);
        addtoView(fields2[0],fields2[1],fields2[2],fields2[3],true);
    }

    t.close();


}
void MainWindow::addtoView(QString name,QString datestr,QString employeestr,QString charitablestr, bool pr)
{


    QString tmp = "Company Name: " + name + ", Date Created: " + datestr
    + ", Employees: " + employeestr;


    if(pr == true)
    {
        ui->listWidget->addItem(tmp);
        ui->listWidget->model()->sort(0);
    }
    else
    {
       tmp.append(", Charitable: " + charitablestr);
        ui->listWidget_nonprofit->addItem(tmp);
        ui->listWidget_nonprofit->model()->sort(0);

    }
}
void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}



void MainWindow::on_radioButton_profit_clicked()
{
    ui->checkBox->setEnabled(false);
    ui->label_Char->setEnabled(false);
}

void MainWindow::on_radioButton_noprofit_clicked()
{
    ui->checkBox->setEnabled(true);
    ui->label_Char->setEnabled(true);

}

void MainWindow::on_pushButton_add_clicked()
{
    QString _name = ui->lineEdit_name->text();
    QDate _date = ui->dateEdit->date();
    int _employee = ui->spinBox_employees->value();
    bool _profit;
    bool _charitable = false;

    if(ui->radioButton_profit->isChecked())
    {
        _profit = true;
        Company *profitCompany = new CompanyProfit(_name,_date,_employee,_profit);
        listCompany.addCompany(profitCompany);

    }
    else if (ui->radioButton_noprofit->isChecked())
    {
        _profit = false;

        if(ui->checkBox->isChecked())
        {
            _charitable = true;
        }
        Company *nonprofitCompany = new CompanyNonProfit(_name,_date,_employee,_profit,_charitable);
        listCompany.addCompany(nonprofitCompany);
    }


    QString datestr = QVariant(_date).toString();
    QString employeestr = QVariant(_employee).toString();
    QString charitablestr = QVariant(_charitable).toString();

    ui->lineEdit_name->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->spinBox_employees->setValue(0);
    ui->checkBox->setChecked(false);

    addtoView(_name,datestr,employeestr,charitablestr,_profit);


}
