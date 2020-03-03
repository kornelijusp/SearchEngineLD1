#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Kandidatai
{
private:
    string firstName, lastName, profesion;
    int experiance;
    double expectedSalary;

public:
    void setData(string, string, string, int, double);
    string getFirstName();
    string getLastName();
    string getProfesion();
    int getExperiance();
    double getExpectedSalary();
};

void Kandidatai::setData(string firstName, string lastName, string profesion, int experiance, double expectedSalary)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->profesion = profesion;
    this->experiance = experiance;
    this->expectedSalary = expectedSalary;
}
string Kandidatai::getFirstName()
{
    return firstName;
}
string Kandidatai::getLastName()
{
    return lastName;
}
string Kandidatai::getProfesion()
{
    return profesion;
}
int Kandidatai::getExperiance()
{
    return experiance;
}
double Kandidatai::getExpectedSalary()
{
    return expectedSalary;
}

int usersNumber()
{
    int usersAmount, y;
    string x;
    double z;
    ifstream fin("data.csv");
    while (true)
    {

        if (fin.eof())
            break;
        fin >> x >> x >> x >> y >> z;
        usersAmount++;
    }
    fin.close();
    return usersAmount;
}

int main()
{
    int usersNum = usersNumber();
    Kandidatai kandidatai[usersNum];

    string firstName, lastName, profesion;
    int experiance, state;
    double expectedSalary, averageSalary = 0;

    ifstream fin;
    fin.open("data.csv");

    for (int i = 0; i < usersNum; i++)
    {
        fin >> firstName >> lastName >> profesion >> experiance >> expectedSalary;
        kandidatai[i].setData(firstName, lastName, profesion, experiance, expectedSalary);
    }
    fin.close();

    // for (int i = 0; i < usersNum; i++)
    // cout << kandidatai[i].getExperiance() << endl;

    do
    {
        cout << "Programa kandidatai" << endl
             << endl;
        cout << "1. Pageidaujamo atlygio vidurkio skaičiavimas" << endl;
        cout << "2. Paieška" << endl;
        cout << "3. Iterpti" << endl;
        cout << "4. Rikiavimas pagal profesinę patirtį ir pageidaujamą atlygį" << endl;
        cout << "5. Perziureti visus irasus" << endl;
        cout << "6. Baigti." << endl
             << endl;
        cin >> state;

        switch (state)
        {
        case 6:
            cout << "Programa baigta!" << endl;
            break;
        case 1:
            cout << "Pageidaujamo atlygio vidurkis: ";
            for (int i = 0; i < usersNum; i++)
                averageSalary += kandidatai[i].getExpectedSalary();
            averageSalary = averageSalary / usersNum;
            cout << averageSalary << endl;
            break;
        case 5:
            for (int i = 0; i < usersNum; i++)
            {
                cout << kandidatai[i].getFirstName() << " " << kandidatai[i].getLastName() << " ";
                cout << kandidatai[i].getProfesion() << " " << kandidatai[i].getExperiance() << " ";
                cout << kandidatai[i].getExpectedSalary() << endl;
            }
            break;

        default:
            cout << "Netinkama komanda!" << endl;
            break;
        }
        cout << endl
             << "--------------------------------------------" << endl
             << endl;
    } while (state != 6);

    return 0;
}