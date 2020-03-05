// Biblioteku sarasas
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// GLOBALIEJI KINTAMIEJI

// Duomenu failo globalus pavadinimas
const char dataBase[] = "data.csv";
// Maksimalus studentu kiekis galimas programoje
const int maxStudent = 210;

// Kandidatu klase
class Kandidatas
{
    // Klases Kintamieji
private:
    string vardas;
    string pavarde;
    string profesija;
    int darboPatirtis;
    double norimasAtlig;

public:
    // Konstruktoriai
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
    // Klases metodu prototipai
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

// Klases metodai
// SET
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
// GET
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
void paieska(Kandidatas[], int, Kandidatas[], int &, string, string, string, int, string);
void removeDupWord(char[], string[]);
void pildyti(Kandidatas[], int);
void rikiuoti(Kandidatas[], int, int);
void Spausdinti(Kandidatas[], int);
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// MAIN -------------------------------------------
int main()
{
    // Kintamieji ir klases
    Kandidatas kandidatai[maxStudent];
    Kandidatas kandidatuSarasas[maxStudent];

    int n, darboPatirtis_t, kiek;
    string state, x;
    string vardas_t, pavarde_t, profesija_t;
    double norimasAtlig_t;

    // Patikrina ar yra failas
    if (skaityti(kandidatai, n))
    {
        // vykdo programa
        do
        {
            // User interface
            // Dialogas su naudotoju
            cout << "Programa kandidatai" << endl
                 << endl;
            cout << "1. Pageidaujamo atlygio vidurkio skaičiavimas" << endl;
            cout << "2. Paieška" << endl;
            cout << "3. Iterpti" << endl;
            cout << "4. Rikiavimas pagal profesinę patirtį ir pageidaujamą atlygį" << endl;
            cout << "5. Perziureti visus irasus" << endl;
            cout << "6. Baigti.\n\n:";
            cin >> state;
            cout << "-------------------------------------\n";
            // Switch funkcija valdo procesus
            switch (stoi(state))
            {
                // Apskaiciuoja vidurki
            case 1:
                cout << "Vidurkis: " << vidurkis(kandidatai, n) << endl;
                break;
                // Paieskos variklis
                // Search engine
            case 2:
                // UI
                cout << "Paieska\n";
                cout << "1. Pagal varda, pavarde\n";
                cout << "2. Pagal varda, pavarde, profesija, darbo patirti\n";
                cout << "3. Baigti\n\n:";
                cin >> x;
                cout << "-------------------------------------\n";
                // Iesko paga 2 parametrus
                if (!x.compare("1"))
                {
                    cout << "\nIvesk varda ir pavarde" << endl;
                    cin >> vardas_t >> pavarde_t;
                    cout << "=====================================\n";
                    paieska(kandidatai, n, kandidatuSarasas, kiek, vardas_t, pavarde_t, profesija_t, darboPatirtis_t, x);
                    Spausdinti(kandidatuSarasas, kiek);
                }
                // Iesko pagal 4 parametrus
                else if (!x.compare("2"))
                {
                    cout << "\nIvesk varda, pavarde, profesija ir darbo patirti" << endl;
                    cin >> vardas_t >> pavarde_t >> profesija_t >> darboPatirtis_t;
                    cout << "=====================================\n\n";
                    paieska(kandidatai, n, kandidatuSarasas, kiek, vardas_t, pavarde_t, profesija_t, darboPatirtis_t, x);
                    Spausdinti(kandidatuSarasas, kiek);
                }
                else
                    break;

                break;
                // Iterpimo procesas kai norima prideti kandidata
            case 3:
                cout << "\nIveskite studento varda, pavarde, profesija, darbo patirti ir norima atlygi (Atskirti tarpais).\n";

                cin >> vardas_t >> pavarde_t >> profesija_t >> darboPatirtis_t >> norimasAtlig_t;
                //pridedamas naujas studentas
                kandidatai[n] = Kandidatas(vardas_t, pavarde_t, profesija_t, darboPatirtis_t, norimasAtlig_t);
                //irasoma i faila
                pildyti(kandidatai, n);
                n++;
                cout << "\nIrasyta sekmingai!\n";
                break;
                // Rikiavimas
            case 4:
                // UI
                cout << "Rikiavimas pagal darbo patirti arba norima atlygi\n\n";
                cout << "1. Pagal darbo patirti\n";
                cout << "2. Pagal norima atlygi\n";
                cout << "3. Baigti\n\n:";
                cin >> x;
                cout << "\n\n";
                // Exit
                if (!x.compare("3"))
                    break;
                // Rikiuoja pagal darbo patiri arba norima atligi
                rikiuoti(kandidatai, n, stoi(x) - 1);
                Spausdinti(kandidatai, n);

                break;
                // Isspausdina visus kandidatus
            case 5:
                Spausdinti(kandidatai, n);
                break;
                // Palieka programa
            case 6:
                cout << "Programa baigta!\n";
                break;

            default:
                break;
            }

            cout << "-------------------------------------\n";
        } while (state.compare("6"));
    }
    return 0;
}
//---------------------------------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++=
// Funkcijos
// Skaiciuoja vidurki
double vidurkis(Kandidatas kandidatai[], int n)
{
    double suma = 0;
    for (int i = 0; i < n; i++)
    {
        suma += kandidatai[i].getNorimasAtlig();
    }
    return suma / n;
}
// Skaito is failo
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
// Vykdo paieska
void paieska(Kandidatas kandidatai[], int n, Kandidatas kandidatuSarasas[], int &kiek, string vardas_t, string pavarde_t, string profesija_t, int darboPatirtis_t, string x)
{

    kiek = 0;
    for (int i = 0; i < n; i++)
    {
        //patikrina varda, pavarde, profesija
        if (!x.compare("1") && kandidatai[i].getVardas().compare(vardas_t) == 0 && kandidatai[i].getPavarde().compare(pavarde_t) == 0)
        {
            kandidatuSarasas[kiek] = kandidatai[i];
            kiek++;
        }
        else if (!x.compare("2") && kandidatai[i].getVardas().compare(vardas_t) == 0 && kandidatai[i].getPavarde().compare(pavarde_t) == 0 && kandidatai[i].getProfesija().compare(profesija_t) == 0 && kandidatai[i].getDarboPatirtis() == darboPatirtis_t)
        {
            kandidatuSarasas[kiek] = kandidatai[i];
            kiek++;
        }
    }
}
// Papildo kandidatu sarasa
void pildyti(Kandidatas kandidatai[], int n)
{
    ofstream fout;
    fout.open(dataBase, fstream::app);

    fout << "\n"
         << kandidatai[n].getVardas() << " " << kandidatai[n].getPavarde() << " " << kandidatai[n].getProfesija() << " " << kandidatai[n].getDarboPatirtis() << " " << kandidatai[n].getNorimasAtlig();

    fout.close();
}
// Rikiavimas
// State 1 patirtis
// State 0 Atlygis
void rikiuoti(Kandidatas kandidatai[], int n, int state)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {

            if ((!state && kandidatai[i].getDarboPatirtis() < kandidatai[j].getDarboPatirtis()) || (state && kandidatai[i].getNorimasAtlig() < kandidatai[j].getNorimasAtlig()))
            {
                swap(kandidatai[i], kandidatai[j]);
            }
        }
    }
}
// Spausdina klase
void Spausdinti(Kandidatas kandidatai[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". "
             << kandidatai[i].getVardas() << " ";
        cout << kandidatai[i].getPavarde() << " ";
        cout << kandidatai[i].getProfesija() << " ";
        cout << kandidatai[i].getDarboPatirtis() << " ";
        cout << kandidatai[i].getNorimasAtlig() << endl;
    }
}