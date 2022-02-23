#include <iostream>
#include <string>

class Employee
{
    static int employees_count;

    std::string organization, position, name;
    double experience, salary;
    char gender;
    int age;

public:
    Employee(std::string organization, std::string position, std::string name,
             double experience, double salary, char gender, int age)
    {
        this->organization = organization;
        this->position = position;
        this->name = name;
        this->experience = experience;
        this->salary = salary;
        this->gender = gender;
        this->age = age;
        employees_count++;
    }

    ~Employee()
    {
        employees_count--;
    }

    std::string GetOrganization()
    {
        return organization;
    }

    std::string GetPosition()
    {
        return position;
    }

    double GetExperience()
    {
        return experience;
    }

    double GetSalary()
    {
        return salary;
    }

    void addSalary(double salary)
    {
        this->salary += salary;
    }

    void editPosition(std::string position)
    {
        this->position = position;
    }

    void showEmployeesInfo()
    {
        std::cout << "Name: " << name << " Gender: " << gender << " Age: " << age << std::endl;
    }

    Employee operator=(const Employee &b)
    {
        if (this != &b)
        {
            organization = b.organization;
            position = b.position;
            name = b.name;
            experience = b.experience;
            salary = b.salary;
            gender = b.gender;
            age = b.age;
        }
        return *this;
    }

    static void showCount()
    {
        std::cout << "Count: " << employees_count << std::endl;
    }
};

int Employee::employees_count = 0;

int main()
{
    Employee::showCount();
    Employee *a = new Employee("ВТБ", "Аналитик данных", "Вадим", 3, 1500000, 'M', 19);
    Employee::showCount();
    Employee *b = new Employee("Сбербанк", "Менеджер по продажам", "Дима", 1, 1000000, 'M', 18);
    Employee::showCount();
    b->showEmployeesInfo();
    a = b;
    delete b;
    a->showEmployeesInfo();
    Employee::showCount();
    delete a;

    return 0;
}
