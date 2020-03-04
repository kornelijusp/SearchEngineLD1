//Ä¯keliamos bibliotekos
#include <iostream>
#include <fstream>
using namespace std;
//apsiraÅ¡omi failÅ³ pavadinimai
const char duom[] = "duom.txt";
//apraÅ¡omas maksimalus studentÅ³ kiekis
const int maxStud = 20;
//studentÅ³ klasÄ—
class Studentas {
  private:
    //kintamieji apraÅ¡antys studentÄ…
    string vardas;
    string pavarde;
    string grupe;
    double vidurkis;
  public:
    //konstruktoriai
    Studentas() {
      vardas = "Nera";
      pavarde = "Nera";
      grupe = "Nera";
      vidurkis = 0;
    }

    Studentas(string vardas, string pavarde, string grupe, double vidurkis) {
      this->vardas = vardas;
      this->pavarde = pavarde;
      this->grupe = grupe;
      this->vidurkis = vidurkis;
    }
    //nustatymas individualiÅ³ parametrÅ³
    void setVardas(string vardas) {
      this->vardas = vardas;
    }
    void setPavarde(string pavarde) {
      this->pavarde = pavarde;
    }
    void setGrupe(string grupe) {
      this->grupe = grupe;
    }
    void setVidurkis(double vidurkis) {
      this->vidurkis = vidurkis;
    }
    //graÅ¾inami objekto parametrai
    string getVardas() {
      return vardas;
    }
    string getPavarde() {
      return pavarde;
    }
    string getGrupe() {
      return grupe;
    }
    double getVidurkis() {
      return vidurkis;
    }

};
//apsiraÅ¡omos funkcijos
bool skaityti(Studentas studentai[], int &n);
void pildyti(Studentas studentai[], int n);
void spausdintiStud(Studentas studentai[], int n);
void ieskGerBlogStud(Studentas studentai[], int n, Studentas studentaiGerBlog[], int &kiekGeru, int &kiekBlogu);
void ieskotiStud(Studentas studentai[], int n, Studentas studentuSarasas[], int &kiek, string vardasTemp, string pavardeTemp);
void ieskotiStud(Studentas studentai[], int n, Studentas studentuSarasas[], int &kiek, string vardasTemp, string pavardeTemp, string grupeTemp);
void rikiuoti(Studentas studentai[], int n, int vidurkiArPavarde);

int main() {
  //kiek rasta studentÅ³
  int n;
  //studentÅ³ masyvas
  Studentas studentai[maxStud];
  //jei pavyko nuskaityti failÄ… programa vyksta toliau
  if (skaityti(studentai, n)) {
    //isspausdina Ä¯ ekranÄ… rastÄ… studentÅ³ saraÅ¡Ä…
    spausdintiStud(studentai, n);
    //klaviatÅ«ros input kintamasis
    string input;
    do {
      cout << "\nKomandos:\n0. Baigti darbÄ…\n1. Geriausio ir blogiausio studento paieÅ¡ka.\n2. PaieÅ¡ka nurodÅ¾ius vardÄ… ir pavardÄ™.\n3. PaieÅ¡ka nurodÅ¾ius vardÄ…, pavardÄ™ ir grupÄ™.\n4. Rikiavimas pagal vidurkÄ¯ arba pavardÄ™.\n5. Pildyti duomenis.\n\n";
      //ivedimas is klaviatÅ«ros navigacijai po meniu
      cout << "Komanda: ";
      cin >> input;
      //tikrina kas buvo Ä¯vesta ir atitinkamai atlieka veiksmus
      if (input.compare("1") == 0) {
        //geru ir blogu studentu masyvas, nes gali bÅ«ti ir keli su tais paÄiais parametrais
        Studentas studentaiGerBlog[maxStud];
        int kiekGeru, kiekBlogu;
        //suieÅ¡ko stundetus
        ieskGerBlogStud(studentai, n, studentaiGerBlog, kiekGeru, kiekBlogu);
        //iÅ¡veda Ä¯ ekranÄ… rastus studentus
        cout << "\nGeras(-i) studentas(-ai):" << endl;
        for (int i = 0; i < kiekGeru; i++) {
          cout << studentaiGerBlog[i].getVardas() << " ";
          cout << studentaiGerBlog[i].getPavarde() << " ";
          cout << studentaiGerBlog[i].getGrupe() << " ";
          cout << studentaiGerBlog[i].getVidurkis() << "\n";
        }
        cout << "\nBlogas(-i) studentas(-ai):" << endl;
        for (int i = kiekGeru; i < kiekGeru + kiekBlogu; i++) {
          cout << studentaiGerBlog[i].getVardas() << " ";
          cout << studentaiGerBlog[i].getPavarde() << " ";
          cout << studentaiGerBlog[i].getGrupe() << " ";
          cout << studentaiGerBlog[i].getVidurkis() << "\n";
        }
      } else if (input.compare("2") == 0) {
        //apsiraÅ¡omas gautÅ³ studentu sÄ…raÅ¡ui saugoti
        Studentas studentuSarasas[maxStud];
        int kiek;
        //trumpalaikiai kintamieji
        string vardasTemp;
        string pavardeTemp;
        cout << "\nÄ®veskite vardÄ… ir pavardÄ™ (atskirti tarpu)\n";
        cin >> vardasTemp >> pavardeTemp;
        //suieÅ¡ko studento pagal vardÄ… ir pavardÄ™
        ieskotiStud(studentai, n, studentuSarasas, kiek, vardasTemp,pavardeTemp);
        if (kiek > 0) {
          cout << "\nRasti studentas(-ai) pagal vardÄ… ir pavardÄ™:\n";
          for (int i = 0; i < kiek; i++) {
            cout << studentuSarasas[i].getVardas() << " ";
            cout << studentuSarasas[i].getPavarde() << " ";
            cout << studentuSarasas[i].getGrupe() << " ";
            cout << studentuSarasas[i].getVidurkis() << "\n";
          }
        } else {
          cout << "\nNieko nerasta!\n";
        }
      } else if (input.compare("3") == 0) {
        //apsiraÅ¡omas gautÅ³ studentu sÄ…raÅ¡ui saugoti
        Studentas studentuSarasas[maxStud];
        int kiek;
        string vardasTemp;
        string pavardeTemp;
        string grupeTemp;
        cout << "\nÄ®veskite vardÄ…, pavardÄ™ ir grupÄ™ (atskirti tarpu)\n";
        cin >> vardasTemp >> pavardeTemp >> grupeTemp;
        //suieÅ¡ko studento pagal vardÄ…, pavardÄ™ ir grupÄ™
        ieskotiStud(studentai, n, studentuSarasas, kiek, vardasTemp,pavardeTemp, grupeTemp);
        if (kiek > 0) {
          cout << "\nRasti studentas(-ai) pagal vardÄ…, pavardÄ™ ir grupÄ™:\n";
          for (int i = 0; i < kiek; i++) {
            cout << studentuSarasas[i].getVardas() << " ";
            cout << studentuSarasas[i].getPavarde() << " ";
            cout << studentuSarasas[i].getGrupe() << " ";
            cout << studentuSarasas[i].getVidurkis() << "\n";
          }
        } else {
          cout << "\nNieko nerasta!\n";
        }
      } else if (input.compare("4") == 0) {
        //ivedama is klaviatÅ«ros palei kÄ… nori atlikti rÅ«Å¡iavimÄ…
        int vidurkiArPavarde;
        cout << "\n1. Pagal vidurkÄ¯.\n2. Pagal pavardÄ™.\n\n";
        cout << "Komanda: ";
        cin  >> vidurkiArPavarde;
        //iÅ¡rikiuoja studentu masyve
        rikiuoti(studentai, n, vidurkiArPavarde);
        //isspausdina studentus
        spausdintiStud(studentai, n);
      } else if (input.compare("5") == 0) {
        cout << "\nIveskite studento varda, pavarde, grupe ir vidurki (Atskirti tarpu).\n";
        string vardasTemp;
        string pavardeTemp;
        string grupeTemp;
        double vidurkisTemp;
        cin >> vardasTemp >> pavardeTemp >> grupeTemp >> vidurkisTemp;
        //pridedamas naujas studentas
        studentai[n] = Studentas(vardasTemp, pavardeTemp, grupeTemp, vidurkisTemp);
        //irasoma i faila
        pildyti(studentai, n);
        n++;
        cout << "\nIrasyta sekmingai!\n";
      }
    } while (input.compare("0") != 0);
  }

  return 0;
}

bool skaityti(Studentas studentai[], int &n) {
  //atidaromas failas
  ifstream FD;
  FD.open(duom);
  //patikrina ar pavyko atidaryti faila
  if (FD.is_open()) {
    cout << "\nNuskaitomas studentÅ³ sÄ…raÅ¡as" << endl;
    n = 0;
    //skaito kol baigsis failas
    while (!FD.eof()) {
      //nuskaitomos reiksmes ir priskiriamos studentams
      string vardasTemp;
      string pavardeTemp;
      string grupeTemp;
      double vidurkisTemp;
      FD >> vardasTemp >> pavardeTemp >> grupeTemp >> vidurkisTemp;
      studentai[n].setVardas(vardasTemp);
      studentai[n].setPavarde(pavardeTemp);
      studentai[n].setGrupe(grupeTemp);
      studentai[n].setVidurkis(vidurkisTemp);
      n++;
    }
    FD.close();
    cout << "Nuskaityta sÄ—kmingai" << "\n\n";
    return true;
  } else {
    cout << "\nNerastas duomenÅ³ failas" << "\n\n";
    return false;
  }
}

void pildyti(Studentas studentai[], int n) {
  ofstream FR;
  FR.open(duom, fstream::app);

  FR << "\n" << studentai[n].getVardas() << " " << studentai[n].getPavarde() << " " << studentai[n].getGrupe() << " " << studentai[n].getVidurkis();

  FR.close();
}

void spausdintiStud(Studentas studentai[], int n) {
  //spasudina studentu saraÅ¡Ä…
  cout << "StudentÅ³ sÄ…raÅ¡as:" << endl;
  for (int i = 0; i < n; i++) {
    cout << studentai[i].getVardas() << " ";
    cout << studentai[i].getPavarde() << " ";
    cout << studentai[i].getGrupe() << " ";
    cout << studentai[i].getVidurkis() << "\n";
  }
}

void ieskGerBlogStud(Studentas studentai[], int n, Studentas studentaiGerBlog[], int &kiekGeru, int &kiekBlogu) {
  //suieskoma koks yra didÅ¾iausias ir maÅ¾iausias vidurkis
  double maxVid = 0;
  double minVid = 10;
  for (int i = 0; i < n; i++) {
    if (studentai[i].getVidurkis() > maxVid) {
      maxVid = studentai[i].getVidurkis();
    }

    if (studentai[i].getVidurkis() < minVid) {
      minVid = studentai[i].getVidurkis();
    }
  }
  // suieskomi geri ir blogi studentai ir issaugomi i atskirÄ… masyva
  kiekGeru = 0;
  for (int i = 0; i < n; i++) {
    if (studentai[i].getVidurkis() == maxVid) {
      studentaiGerBlog[kiekGeru] = studentai[i];
      kiekGeru++;
    }
  }
  kiekBlogu = 0;
  for (int i = 0; i < n; i++) {
    if (studentai[i].getVidurkis() == minVid) {
      studentaiGerBlog[kiekGeru + kiekBlogu] = studentai[i];
      kiekBlogu++;
    }
  }
}

void ieskotiStud(Studentas studentai[], int n, Studentas studentuSarasas[], int &kiek, string vardasTemp, string pavardeTemp) {
  // iesko studentÅ³ kurie atitinka kriterijus
  kiek = 0;
  for (int i = 0; i < n; i++) {
    //patikrina varda ir pavardÄ™
    if (studentai[i].getVardas().compare(vardasTemp) == 0 && studentai[i].getPavarde().compare(pavardeTemp) == 0) {
      studentuSarasas[kiek] = studentai[i];
      kiek++;
    }
  }
}

void ieskotiStud(Studentas studentai[], int n, Studentas studentuSarasas[], int &kiek, string vardasTemp, string pavardeTemp, string grupeTemp) {
  // iesko studentÅ³ kurie atitinka kriterijus
  kiek = 0;
  for (int i = 0; i < n; i++) {
    //patikrina varda, pavardÄ™ ir grupe
    if (studentai[i].getVardas().compare(vardasTemp) == 0 && studentai[i].getPavarde().compare(pavardeTemp) == 0 && studentai[i].getGrupe().compare(grupeTemp) == 0) {
      studentuSarasas[kiek] = studentai[i];
      kiek++;
    }
  }
}

void rikiuoti(Studentas studentai[], int n, int vidurkiArPavarde) {
  //isrikiuoja masyva pagal kas yra pasirinkta, 1 - pagal vidurki; 2 - pagal pavardÄ™
  for (int i = 0; i < n - 1; i++) {
    for (int j = i; j < n; j++) {
      if (vidurkiArPavarde == 1) {
        if (studentai[i].getVidurkis() < studentai[j].getVidurkis()) {
          swap(studentai[i], studentai[j]);
        }
      } else if (vidurkiArPavarde == 2) {
        if (studentai[i].getPavarde().compare(studentai[j].getPavarde()) > 0) {
          swap(studentai[i], studentai[j]);
        }
      }
    }
  }
}
