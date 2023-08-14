#pragma once

#include <string>

class employee 
{
    public:
        employee (const std::string&, const std::string&, double);
        std::string getName () const;
        void setName (const std::string&);
        std::string getDepartment () const;
        void setDepartment (const std::string&);
        double getSalary () const;
        void setSalary (int);
        int getID () const;
        static int getStartID ();
        ~employee ();
    private:
        std::string name;
        std::string department;
        double salary;
        int ID;
        static int startID;
};