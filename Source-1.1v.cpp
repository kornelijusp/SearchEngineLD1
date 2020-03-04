#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const char dataBase[] = "data.csv"; // File name

// Klase 1
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
    string getProfession();
    int getExperiance();
    double getExpectedSalary();

    void insertUser()
    {
        cout << "Insert User" << endl
             << endl;
        cout << "First name: ";
        cin >> firstName;
        cout << endl
             << endl
             << "Last name: ";
        cin >> lastName;
        cout << "Profession: ";
        cin >> profession;
    }
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
string Kandidatas::getProfession()
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

// ===================================================
// Klase 2
class List
{
private:
    Kandidatas k[200];
    int n; // Users amount
public:
    List()
    {
        ifstream f(dataBase);
        n = 0;
        if (f.fail())
            cout << "Can't find file!";
        else
        {
            string v, p, prof;
            int pat;
            double sal;
            int a;
            while (!f.eof())
            {
                f >> v >> p >> prof >> pat >> sal;
                k[n].setData(v, p, prof, pat, sal);
                n++;
            }
        }
        f.close();
    }
};
// ===========================================================
// Main

int main()
{

    return 0;
}