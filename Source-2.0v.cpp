#include <iostream>
#include <fstream>

using namespace std;

const char dataBase[] = "data.csv";

const int maxStudent = 200;

class Kandidatas
{
private:
    string vardas;
    string pavarde;
    string profesija;
    int darboPatirtis;
    double norimasAtlig;

public:
    Kandidatas()
    {
        vardas = "-";
        pavarde = "-";
        profesija = "-";
        darboPatirtis = 0;
        norimasAtlig = 0;
    }
    Kandidatas(string vardas, string pavarde, string profesija, int darboPatirtis, double norimasAtlig)
    {
        this->vardas = vardas;
        this->pavarde = pavarde;
        this->profesija = profesija;
        this->darboPatirtis = darboPatirtis;
        this->norimasAtlig = norimasAtlig;
    }
    void setVardas(string);
    void setPavarde(string);
    void setProfesija(string);
    void setDarboPatirtis(int);
    void setNorimasAtlig(double);

    string getVardas();
    string getPavarde();
    string getProfesija();
    int getDarboPatirtis();
    double getNorimasAtlig();
};

void Kandidatas::setVardas(string vardas)
{
    this->vardas = vardas;
}
void Kandidatas::setPavarde(string pavarde)
{
    this->pavarde = pavarde;
}
void Kandidatas::setProfesija(string profesija)
{
    this->profesija = profesija;
}
void Kandidatas::setDarboPatirtis(int darboPatirtis)
{
    this->darboPatirtis = darboPatirtis;
}
void Kandidatas::setNorimasAtlig(double norimasAtlig)
{
    this->norimasAtlig = norimasAtlig;
}
//----
string Kandidatas::getVardas()
{
    return vardas;
}
string Kandidatas::getPavarde()
{
    return pavarde;
}
string Kandidatas::getProfesija()
{
    return profesija;
}
int Kandidatas::getDarboPatirtis()
{
    return darboPatirtis;
}
double Kandidatas::getNorimasAtlig()
{
    return norimasAtlig;
}