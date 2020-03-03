#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const char dataBase[] = "data.csv"; // File name

class Kandidatas
{
private:
    string firstName, lastName, profession;
    int experience;
    double expectedSalary;

public:
    Kandidatas() : firstName(""), lastName(""), profession(""), experience(0), expectedSalary(0.1) {}
    Kandidatas(string firstName, string lastName, string profession, int experience, double expectedSalary)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->profession = profession;
        this->experience = experience;
        this->expectedSalary = expectedSalary;
    }

    void setData(string, string, string, int, double);
    string getFirstName();
    string getLastName();
    string getProfesion();
    int getExperiance();
    double getExpectedSalary();
};
void Kandidatas::setData(string firstName, string lastName, string profession, int experience, double expectedSalary)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->profession = profession;
    this->experience = experience;
    this->expectedSalary = expectedSalary;
}
string Kandidatas::getFirstName()
{
    return firstName;
}
string Kandidatas::getLastName()
{
    return lastName;
}
string Kandidatas::getProfesion()
{
    return profession;
}
int Kandidatas::getExperiance()
{
    return experience;
}
double Kandidatas::getExpectedSalary()
{
    return expectedSalary;
}


int main() {

    return 0;
}