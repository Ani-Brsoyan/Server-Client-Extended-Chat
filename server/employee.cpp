#include "employee.h"

int employee::startID = 1247;

employee::employee (const std::string& empName, const std::string& empDepartment, double empSalary)
    :name(empName)
    ,department(empDepartment)
    ,salary(empSalary)
    ,ID(getStartID())
    {}

std::string employee::getName () const
{
    return name;
}

void employee::setName (const std::string& newName)
{
    name = newName;
}

std::string employee::getDepartment () const
{
    return department;
}

void employee::setDepartment (const std::string& newDepartment)
{
    department = newDepartment;
}

double employee::getSalary () const
{
    return salary;
}

void employee::setSalary (int newSalary)
{
    salary = newSalary;
}

int employee::getID () const
{
    return ID;
}

int employee::getStartID ()
{
    return employee::startID++;
}
      
employee::~employee ()
{}