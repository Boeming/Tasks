#include <iostream>
#include <string.h>

const int LNAME=25;

class STUDENT
{
    char name[LNAME];
    int age;
    float grade;

public:
    char* GetName()
    {
        return name;
    }
    
    int GetAge() const
    {
        return age;
    }
    
    float GetGrade() const
    {
        return grade;
    }
    
    void SetName(char* name)
    {
        for(int i = 0; i < strlen(name); i++)
        {
            this->name[i] = name[i];
        }
    }
    
    void SetAge(int age)
    {
        this->age = age;
    }
    
    void SetGrade(float grade)
    {
        this->grade = grade;
    }
    
    void Set(char* name, int age, float grade)
    {
        SetName(name);
        SetAge(age);
        SetGrade(grade);
    }
    
    void Show()
    {
        std::cout << name << " " << age << " " << grade;
    }

};



int main()
{
    STUDENT first;
    char first_student_name[LNAME] = "Vadim";
    first.SetName(first_student_name);
    std::cout << first.GetName() << std::endl;
    first.SetAge(25);
    std::cout << first.GetAge() << std::endl;
    first.SetGrade(52.5);
    std::cout << first.GetGrade() << std::endl;
    
    STUDENT second;
    char second_student_name[LNAME] = "Ivan";
    second.Set(second_student_name, 19, 57.5);
    second.Show();
    
    return 0;
}
