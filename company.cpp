#include "company.h"


Company::Company(QString _name,QDate _date,int _employees,bool pr)
{
    name = _name;
    date = _date;
    employees = _employees;
    profit = pr;
}
QString Company::getName()
{
    return name;
}
QDate Company::getDate()
{
    return date;
}
int Company::getEmployees()
{
    return employees;
}
bool Company::getProfit()
{
    return profit;
}
Company::~Company(){}
