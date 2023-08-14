#include "parsing.h"

#include <sstream>
#include <functional>
#include <unordered_map>
#include <vector>

#include "employee.h"

std::vector<employee> myEmpList;

std::unordered_map<std::string, std::function <std::string (const std::string&)>> parsingMap = {
    { "CREATE", createInstance },
    { "LIST", listInstance },
    { "DELETE", deleteInstance }
};

std::unordered_map<std::string, std::function <std::string (const std::string&)>> listingMap = {
    { "DEPARTMENT", listDepartment },
};

std::string execute (const std::string& request)
{
    std::istringstream iss(request);
    std::string command;
    iss >> command;

    std::string restOfTheCommand;
    std::getline(iss, restOfTheCommand);

    std::string response = parsingMap[command](restOfTheCommand);
    return response;
}

std::string createInstance (const std::string& request) 
{
    //EMPLOYEE { [name], [department], [salary] }
    size_t start = request.find("{"); 
    size_t end = request.find_last_of("}"); 
    std::string coreInfo = request.substr(start + 2, end - start - 3);
    if (!wordCountMatch(coreInfo)) {
        return "INVALID PARAMETER LIST";
    }

    std::istringstream iss(coreInfo);
    std::string name;
    iss >> name;
    std::string dep;
    iss >> dep;
    std::string sal;
    iss >> sal;
    if (!isDouble(sal)) {
        return "SALARY SHOULD BE DOUBLE";
    } 
    myEmpList.push_back(employee(name.erase(name.size() - 1), dep.erase(dep.size() - 1), std::stod(sal)));
    return "EMPLOYEE " + name + " CREATED";
}

std::string listInstance (const std::string& request)
{
    //EMPLOYEE { * } or EMPLOYEE { DEPARTMENT = [dep] }
    size_t start = request.find("{"); 
    size_t end = request.find_last_of("}"); 
    std::string coreInfo = request.substr(start + 2, end - start - 3);

    if(coreInfo == "*") {
        return listAll();
    }
    if (!wordCountMatch(coreInfo)) {
        return "INVALID PARAMETER LIST";
    }

    std::istringstream iss(coreInfo);
    std::string category;
    iss >> category;
    if (listingMap.find(category) == listingMap.end()) {
        return "INVALID CATEGORY";
    }

    std::string restOfTheCondition;
    std::getline(iss, restOfTheCondition);

    std::string response = listingMap[category](restOfTheCondition); 
    return response;
  
}

std::string listAll ()
{
    std::string response = "\t\t***\n";
    for (std::vector<employee>::iterator it = myEmpList.begin(); it != myEmpList.end(); ++it) {
        std::string temp = "ID: " + std::to_string(it->getID()) + "\t" + "Department: " + it->getDepartment() + "\t" + "Name: " + it->getName() + "\t" + "Salary: " + std::to_string(it->getSalary()) + "\n";
        response += temp;
    }
    return response;
}

std::string listDepartment (const std::string& request)
{
    std::istringstream iss(request);
    std::string temp;
    iss >> temp;
    if (temp != "=") {
        return "INVALID CONDITION";
    }
    iss >> temp;
    std::string response = temp + "DEPARTMENT LIST\n";
    bool empty = true;
    for (std::vector<employee>::iterator it = myEmpList.begin(); it != myEmpList.end(); ++it) {
        if(temp == it->getDepartment()) {
            empty = false;
            std::string info = "ID: " + std::to_string(it->getID()) + "\t" + "Name: " + it->getName() + "\n";
            response += info; 
        }
    }
    if(empty) {
        response += "EMPTY";
    }
    return response;
}

std::string deleteInstance (const std::string& request) 
{
    //EMPLOYEE { ID = 1247 }
    size_t start = request.find("{"); 
    size_t end = request.find_last_of("}"); 
    std::string coreInfo = request.substr(start + 2, end - start - 3);
    if (!wordCountMatch(coreInfo)) {
        return "INVALID PARAMETER LIST";
    }

    std::istringstream iss(coreInfo);
    std::string tmp;
    iss >> tmp;
    if (tmp != "ID") {
        return "INVALID REQUEST";
    }
    iss >> tmp;
    if (tmp != "=") {
        return "INVALID REQUEST";
    }
    iss >> tmp;
    if (!isInteger(tmp)) {
        return "ID SHOULD BE INTEGER";
    }
    int id = std::stoi(tmp);
    for (std::vector<employee>::iterator it = myEmpList.begin(); it != myEmpList.end(); ++it) {
        if(it->getID() == id) {
            myEmpList.erase(it);
            return "EMPLOYEE WITH ID " + tmp + " DELETED";
        }
    }
    return "NO EMPLOYEE WITH ID " + tmp;
}

bool wordCountMatch (const std::string& info)
{
    std::istringstream iss(info);
    std::string tmp;
    int count = 0;
    while (iss >> tmp) {
        count++;
    }
    if (count != 3) {
        return false;
    }
    return true;
}

bool isDouble (const std::string& str) 
{
    try {
        size_t pos;
        std::stod(str, &pos);
        return pos == str.length();
    } catch (const std::exception& e) {
        return false;
    }
}

bool isInteger(const std::string& str) 
{
    try {
        size_t pos;
        std::stoi(str, &pos);
        return pos == str.length();
    } catch (const std::exception& e) {
        return false;
    }
}

