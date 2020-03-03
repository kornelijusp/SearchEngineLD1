#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const char VARDAS[] = "adresatai.txt"; //Failo vardas
class adresatas
{
private:
    string vardas;
    string pav;
    string miestas;
    int amzius;

public:
    adresatas() : vardas(""), pav(""), miestas(""), amzius(0) {}
    adresatas(string v, string p, string m, int a)
    {
        vardas = v;
        pav = p;
        miestas = m;
        amzius = a;
    }
    void setAdresatas(string v, string p, string m, int a)
    {
        vardas = v;
        pav = p;
        miestas = m;
        amzius = a;
    }
    string getVardas() { return vardas; }
    string getPav() { return pav; }
    string getMiestas() { return miestas; }
    int getAmzius() { return amzius; }
    void IveskAdresata()
    {
        cout << "Ivesk varda:";
        cin >> vardas;
        cout << "Ivesk pavarde:";
        cin >> pav;
        cout << "Ivesk miesta:";
        cin >> miestas;
        cout << "Ivesk amziu:";
        cin >> amzius;
    }
};
class Sarasas
{
private:
    adresatas A[50];
    int n; //adresatu kiekis masyve
public:
    Sarasas()
    {
        ifstream f(VARDAS);
        n = 0;
        if (f.fail())
            cout << "Failo nera.";
        else
        {
            string v, p, m;
            int a;
            while (!f.eof())
            {
                f >> v >> p >> m >> a;
                A[n].setAdresatas(v, p, m, a);
                n++;
            }
        }
        f.close();
    }
    void RodykSarasa()
    {
        if (n == 0)
            cout << "Sarasas tuscias.";
        else
        {
            cout << "Adresatu sarasas: \n";
            for (int i = 0; i < n; i++)
            {
                cout << i + 1 << ". ";
                cout << A[i].getVardas() << "\t";
                cout << A[i].getPav() << "\t";
                cout << A[i].getMiestas() << "\t" << A[i].getAmzius() << endl;
            }
        }
    }
    void pridetiAdresata(adresatas naujas)
    {
        A[n].setAdresatas(naujas.getVardas(), naujas.getPav(), naujas.getMiestas(), naujas.getAmzius());
        n++;
    }
};
int main()
{
    char pasirink; //naudotojo įvedamas pasirinktas veiksmo numeris
    pasirink = '0';
    Sarasas S;
    do
    {
        //spausdinamas ekrane siūlomų veiksmų sąrašas
        cout << "1 - Perziureti duomenis.\n";
        cout << "2 - Ivesti nauja adresata.\n";
        cout << "3 - ....\n";
        cout << "4 - ....\n";
        cout << "5 - darbo pabaiga.\n";
        cout << "Pasirinkite veiksma ir iveskite jo numeri:";
        cin >> pasirink; //naudotojo įvedamas veiksmo numeris

        switch (pasirink) //veiksmo pasirinkimas
        {
        case '1':
        {
            S.RodykSarasa();
            cin >> pasirink;
            break;
        }
        case '2':
        {
            adresatas naujas;
            naujas.IveskAdresata();
            S.pridetiAdresata(naujas);
            ofstream ff(VARDAS, ios::app);
            ff << endl
               << naujas.getVardas() << "\t" << naujas.getPav() << "\t" << naujas.getMiestas() << "\t" << naujas.getAmzius();
            ff.close();
            break;
        }
        case '3':
        { //...
            break;
        }
        case '4':
        { //...
            break;
        }
        case '5':
        {
            break;
        }
        default:
            cout << "Rinktis galima 1..5!!!\n";
        } //case pabaiga
    } while (pasirink != '5');
    return 0;
}