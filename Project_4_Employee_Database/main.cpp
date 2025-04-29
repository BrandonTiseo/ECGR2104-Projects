#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

//Employee class declaration & methods
class Employee{
    public:
    
    Employee();

    Employee(string name, string title, double wage);

    void setName(string newName);

    string getName() const;

    void setTitle(string newTitle);

    string getTitle() const;

    void setWage(double newWage);

    double getWage() const;

    private:
    string name;
    string title;
    double wage;

};

Employee::Employee(){
    setName("N/A");
    setTitle("N/A");
    setWage(0.0);
}

Employee::Employee(string name, string title, double wage){
    setName(name);
    setTitle(title);
    setWage(wage);
}

void Employee::setName(string newName){
    name = newName;
}

string Employee::getName() const{
    return name;
}

void Employee::setTitle(string newTitle){
    title = newTitle;
}

string Employee::getTitle() const{
    return title;
}

void Employee::setWage(double newWage){
    if(newWage < 0.0){
        cout << "INVALID WAGE" << endl;
        wage = -1.0;
    }
    else
        wage = newWage;
}

double Employee::getWage() const{
    return wage;
}


//Functions
void printEmployees(vector<Employee> employees){
    for(int i = 0; i < employees.size(); i++){
        cout << "--------------------------------" << endl;
        cout << "Name: " << employees[i].getName() << endl;
        cout << "Title: " << employees[i].getTitle() << endl;
        cout << "Hourly Wage: $" << employees[i].getWage() << " per hour" << endl;
    }

}

void calculateTotalWage(vector<Employee> employees){
    double total = 0.0;
    double hours = 0.0;
    for(int i = 0; i < employees.size(); i++){
        double currentWage = employees[i].getWage();
        cout << "Enter the amount of hours that " << employees[i].getName() << " worked this week: " << endl;
        cin >> hours;
        if(hours < 0.0){
            cout << "INVALID HOURS, SKIPPING EMPLOYEE IN CALCULATION" << endl;
            continue;
        }
        else
            total += currentWage * hours;
    }
    cout << "Total wage earned this week: $" << total << endl;
}

//Main program
int main(){

    vector<Employee> employees = {
        Employee("Bill", "CEO", 100.0),
        Employee("Jimmy","Janitor",20.0),
        Employee("Samson", "IT", 30.0),
        Employee("Gregory", "Accountant", 28.50),
        Employee("Brandon", "Emperor",1000.0)
    };

    int user_input = -1;
    while(user_input != 3){
        cout << "Please select one of the following options (Choose the number value):\n1. Print list of employees\n2. Calculate total wages\n3. Exit applicaiton" << endl;
        cin >> user_input;
        switch(user_input){
            case 1:
                printEmployees(employees);
                break;
            case 2:
                calculateTotalWage(employees);
                break;
            case 3:
                continue;
            default:
                cout << "INVALID INPUT" << endl;
        }
    }
    return 0;
}