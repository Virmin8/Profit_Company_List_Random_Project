#ifndef COMPANY_H
#define COMPANY_H
#include <QString>
#include <QList>
#include <QDate>
#include <QObject>

class Company : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName)
    Q_PROPERTY(QDate date READ getDate)
    Q_PROPERTY(int employees READ getEmployees)
    Q_PROPERTY(bool profit READ getProfit)
public:

    Company(QString,QDate,int,bool);
    ~Company();
    virtual QString getName();
    virtual QDate getDate();
    virtual int getEmployees();
    virtual bool getProfit();

private:
    QString name;
    QDate date;
    int employees;
    bool profit;
};

#endif // COMPANY_H
