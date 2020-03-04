#include <iostream>
#include <fstream>
#include <string>

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
// Prototipai
double vidurkis(Kandidatas[], int);
bool skaityti(Kandidatas[], int &);

int main()
{
    Kandidatas kandidatai[maxStudent];
    int n;
    string state;
    if (skaityti(kandidatai, n))
    {
        do
        {
            cout << "Programa kandidatai" << endl
                 << endl;
            cout << "1. Pageidaujamo atlygio vidurkio skaičiavimas" << endl;
            cout << "2. Paieška" << endl;
            cout << "3. Iterpti" << endl;
            cout << "4. Rikiavimas pagal profesinę patirtį ir pageidaujamą atlygį" << endl;
            cout << "5. Perziureti visus irasus" << endl;
            cout << "6. Baigti.\n\n:";
            cin >> state;

            switch (stoi(state))
            {
                // Vidurkis
            case 1:
                cout << "Vidurkis: " << vidurkis(kandidatai, n) << endl;

                break;

            default:
                break;
            }

        } while (state.compare("6"));
    }
    return 0;
}
//---------------------------------------------------
// Funkcijos
double vidurkis(Kandidatas kandidatai[], int n)
{
    double suma = 0;
    for (int i = 0; i < n; i++)
    {
        suma += kandidatai[i].getNorimasAtlig();
    }
    return suma / n;
}
bool skaityti(Kandidatas kandidatai[], int &n)
{
    ifstream fin;
    fin.open(dataBase);
    if (fin.is_open())
    {
        n = 0;
        while (!fin.eof())
        {
            string vardas_t;
            string pavarde_t;
            string profesija_t;
            int darboPatirtis_t;
            double norimasAtlig_t;

            fin >> vardas_t >> pavarde_t >> profesija_t >> darboPatirtis_t >> norimasAtlig_t;
            kandidatai[n].setVardas(vardas_t);
            kandidatai[n].setPavarde(pavarde_t);
            kandidatai[n].setProfesija(profesija_t);
            kandidatai[n].setDarboPatirtis(darboPatirtis_t);
            kandidatai[n].setNorimasAtlig(norimasAtlig_t);
            n++;
        }
        fin.close();

        return true;
    }
    else
    {
        cout << "\nFailas nerastas"
             << "\n\n";
        return false;
    }
}