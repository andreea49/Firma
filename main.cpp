#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Angajat{

private:

    int id, cld, dept;
    int* idProfesiiAnterioare;
    int nrProfesiiAnterioare;
    bool s;
    char* numeProfesiiAnterioare;
    char nume[100];
    float salariu;
    double inaltime;
    int CNP;
    static const float salariuMinim;
    static int NrAngajati;

    void Init() {
        NrAngajati++;
        id = 0;
        idProfesiiAnterioare = 0;
        s = true;
        numeProfesiiAnterioare = 0;
        nume[0] = 0;
        salariu = 0;
        inaltime = 0;
        CNP = 0;
        nrProfesiiAnterioare = 0;
    }

public:
    //constructor cu un parametru
    Angajat(int cnp) {
        Init();
        CNP = cnp;
    }

    Angajat(int _cnp, char* _nume) {
        Init();
        CNP = _cnp;
        strcpy( nume, _nume );
    }

    Angajat( int* _idProfesiiAnterioare, bool _s, char* _numeProfesiiAnterioare, char _nume[100], float _salariu, double _inaltime, const int _CNP ) {
        Init();
        id = NrAngajati;
        idProfesiiAnterioare = new int[100]; // pentru simplitate presupunem ca avem sub 100
        //copiem din _idProfesiiAnterioare in idProfesiiAnterioare
        int* src = _idProfesiiAnterioare;
        int* dst = idProfesiiAnterioare;
        while( *src != 0 ) {
            *dst = *src;
            dst++;
            src++;
            nrProfesiiAnterioare++;
        }
        s = _s;
        numeProfesiiAnterioare = new char[100];
        strcpy( numeProfesiiAnterioare, _numeProfesiiAnterioare );
        strcpy( nume, _nume );
        salariu = _salariu;
        inaltime = _inaltime;
        CNP = _CNP;
    }

    //default constructor
    Angajat(){
        Init();
    }

    //constructor de copiere
    Angajat( const Angajat& ang ) {
        Init();
        *this = ang;
        // operator =(ang)
    }

    //destructor
    ~Angajat() {
        delete idProfesiiAnterioare;
        delete numeProfesiiAnterioare;
    }

    //operator de atribuire
    Angajat& operator = ( const Angajat& ang ) {
        CNP = ang.CNP;
        strcpy( nume, ang.nume );
        id = ang.id;
        s = ang.s;
        salariu = ang.salariu;
        return *this;
        // si pointeri???

        //...
        //toate var
    }

    //operator de indexare
    int operator [] ( int index ) {
        return 0;
    }

    //operator de incrementare
    Angajat operator ++ () {
        return *this;
    }

    Angajat operator + ( const Angajat& ang ) {
        Angajat a;
        strcpy(a.nume, this->nume);
        strcat(a.nume, "+++++");
        strcat(a.nume, ang.nume);
        return a;
    }

    Angajat operator - ( const Angajat& ang ) {
        Angajat a;
        strcpy(a.nume, this->nume);
        strcat(a.nume, "-----");
        strcat(a.nume, ang.nume);
        return a;
    }

    operator int() {
        return CNP;
    }

    bool operator < ( const Angajat& ang ) {
        return salariu < ang.salariu ;
    }

    bool operator == ( const Angajat& ang ) {
        return CNP == ang.CNP;
    }

    void SetSalariu( float _salariu ) {
        salariu = _salariu;
    }

    float GetSalariu() {
        return salariu;
    }

    void ProfesieNoua( int id, char* nume ) {
        idProfesiiAnterioare[nrProfesiiAnterioare] = id;
        strcat( numeProfesiiAnterioare, ", " );
        strcat( numeProfesiiAnterioare, nume );
        nrProfesiiAnterioare++;
    }

    friend ostream &operator<<( ostream &output, const Angajat &ang );
    friend istream &operator>>( istream  &input, Angajat &ang );
};
int Angajat::NrAngajati = 0;
const float Angajat::salariuMinim = 0;

ostream &operator<<( ostream &output, const Angajat &ang ) {
         output << "Angajat id: " << ang.id << std::endl;
         output << "nume: " << ang.nume << std::endl;
         output << "cladire: " << ang.cld << std::endl;
         output << "departament: " << ang.dept << std::endl;
         output << "id profesii anterioare: " << ang.idProfesiiAnterioare << std::endl; //???
         output << "nume profesii anterioare: " << ang.numeProfesiiAnterioare << std::endl; //???
         output << "gen: ";
         if( ang.s == true ) {
            output << "feminin";
         }
         else {
            output << "masculin";
         }
         output << std::endl;
         output << "salariu: " << ang.salariu << std::endl;
         output << "inaltime: " << ang.inaltime << std::endl;
         output << "CNP: " << ang.CNP << std::endl;
         return output;
}

// _idProfesiiAnterioare, char* _numeProfesiiAnterioare,

istream &operator>>( istream  &input, Angajat &ang ) {
    cout << "Introduceti CNP: " << endl;
    input >> ang.CNP;
    cout << "Introduceti cladirea: " << endl;
    input >> ang.cld;
    cout << "Introduceti departamentul: " << endl;
    input >> ang.dept;
    cout << "Introduceti genul: " << endl;
    input >> ang.s;
    cout << "Introduceti numele: " << endl;
    input >> ang.nume;
    cout << "Introduceti salariu: " << endl;
    input >> ang.salariu;
    cout << "Introduceti inaltime: " << endl;
    input >> ang.inaltime;
    cout << "Introduceti salariu: " << endl;
    input >> ang.salariu;

    return input;
}

class Cladire{

private:

    int NrEtaje;
    int* ListaCNP;
    bool renovare;
    char* Adresa;
    char nume[100];
    float income;
    double inaltime;
    int NrCladire;
    static const double inaltimeEtaj;
    static int NrCladiri;

    void Init() {
        nume[0] = 0;
        NrCladiri++;
        Adresa = 0;
        ListaCNP = 0;
        renovare = false;
    }

public:
    Cladire(int nrcladire) {
        Init();
        NrCladire = nrcladire;
    }

    Cladire(int nrcladire, char* _nume) {
        Init();
        NrCladire = nrcladire;
        strcpy( nume, _nume );
    }

    //default constructor
    Cladire(){
        Init();
    }

    //constructor de copiere
    Cladire( const Cladire& ang ) {
        Init();
        *this = ang;
        // operator =(ang)
    }

    void SetAdresa( char* _adresa ){
        delete Adresa; // elibereaza vechea resursa
        Adresa = new char[100];
        strcpy(Adresa, _adresa);
    }

    char* GetAdresa(){
        return Adresa;
    }
    //destructor
    ~Cladire() {
        delete ListaCNP;
        delete Adresa;
    }

    //int* ListaCNP; ???

    //operator de atribuire
    Cladire& operator = ( const Cladire& cl ) {
        NrCladire = cl.NrCladire;
        strcpy( nume, cl.nume );
        NrEtaje = cl.NrEtaje;
        strcpy( Adresa, cl.Adresa );
        inaltime = cl.inaltime;
        income = cl.income;
        renovare = cl.renovare;
        return *this;
    }

    //operator de indexare
    int operator [] ( int index ) {
        return 0;
    }

    //operator de incrementare
    Cladire operator ++ () {
        return *this;
    }

    Cladire operator + ( const Cladire& cl ) {
        Cladire a;
        strcpy(a.nume, this->nume);
        strcat(a.nume, "+++++");
        strcat(a.nume, cl.nume);
        return a;
    }

    Cladire operator - ( const Cladire& cl ) {
        Cladire a;
        strcpy(a.nume, this->nume);
        strcat(a.nume, "-----");
        strcat(a.nume, cl.nume);
        return a;
    }

    operator int() {
        return NrCladire;
    }

    bool operator < ( const Cladire& cl ) {
        return income < cl.income ;
    }

    bool operator == ( const Cladire& cl ) {
        return NrCladire == cl.NrCladire;
    }

    friend ostream &operator<<( ostream &output, const Cladire &cl );
    friend istream &operator>>( istream  &input, Cladire &cl );
};

int Cladire::NrCladiri = 0;

ostream &operator<<( ostream &output, const Cladire &cl ) {
         output << "Numar etaje: " << cl.NrEtaje << std::endl;
         output << "Nume: " << cl.nume << std::endl;
         output << "Income: " << cl.income << std::endl;
         output << "Inaltime: " << cl.inaltime << std::endl;
         output << "CNP urile angajatilor din cladire: " << cl.ListaCNP << std::endl; // ???
         output << "Adresa: " << cl.Adresa << std::endl;
         if( cl.renovare == true ) {
            output << "Trebuie renovat";
         }
         else {
            output << "Nu trebuie renovat";
         }
         output << std::endl;
         return output;
}

// _idProfesiiAnterioare, char* _numeProfesiiAnterioare,

istream &operator>>( istream  &input, Cladire &cl ) {
    cout << "Introduceti numarul de etaje: " << endl;
    input >> cl.NrEtaje;
    cout << "Introduceti numele: " << endl;
    input >> cl.nume;
    cout << "Introduceti income ul: " << endl;
    input >> cl.income;
    cout << "Introduceti inaltimea: " << endl;
    input >> cl.inaltime;
    cout << "Introduceti adresa: " << endl;
    input >> cl.Adresa;
    cout << "Introduceti daca ii trebuie renovare: " << endl;
    input >> cl.renovare;
    return input;
}

class Departament{
    int cod;
    int NrAngajati;
    char nume[100];

    void Init() {
    }

public:
    Departament(int nrangajati) {
        Init();
        NrAngajati = nrangajati;
    }

    Departament(int nrangajati, char* _nume) {
        Init();
        NrAngajati = nrangajati;
        strcpy( nume, _nume );
    }

    //default constructor
    Departament(){
        Init();
    }

    //constructor de copiere
    Departament( const Departament& dep ) {
        Init();
        *this = dep;
        // operator =(dep)
    }

    void SetNume( char* _nume ){
        strcpy(nume, _nume);
    }

    char* GetNume(){
        return nume;
    }
    //destructor
    ~Departament(){
    }

    //operator de atribuire
    Departament& operator = ( const Departament& dep ) {
        cod = dep.cod;
        strcpy( nume, dep.nume );
        return *this;
    }

    //operator de indexare
    int operator [] ( int index ) {
        return 0;
    }

    //operator de incrementare
    Departament operator ++ () {
        return *this;
    }

    Departament operator + ( const Departament& dep ) {
        Departament a;
        strcpy(a.nume, this->nume);
        strcat(a.nume, "+++++");
        strcat(a.nume, dep .nume);
        return a;
    }

    Departament operator - ( const Departament& dep ) {
        Departament a;
        strcpy(a.nume, this->nume);
        strcat(a.nume, "-----");
        strcat(a.nume, dep.nume);
        return a;
    }

    operator int() {
        return cod;
    }

    bool operator < ( const Departament& dep ) {
        return NrAngajati < dep.NrAngajati ;
    }

    bool operator == ( const Departament& dep ) {
        return cod == dep.cod;
    }

    friend ostream &operator<<( ostream &output, const Departament &dep );
    friend istream &operator>>( istream  &input, Departament &dep );

};

ostream &operator<<( ostream &output, const Departament &dep ) {
         output << "Nume: " << dep.nume << std::endl;
         output << "Numarul de angajati: " << dep.NrAngajati << std::endl;
         output << "Codul: " << dep.cod << std::endl;
         return output;
}

// _idProfesiiAnterioare, char* _numeProfesiiAnterioare,

istream &operator>>( istream  &input, Departament &dep ) {
    cout << "Introduceti numele: " << endl;
    input >> dep.nume;
    cout << "Introduceti codul: " << endl;
    input >> dep.cod;
    cout << "Introduceti numarul angajatilor: " << endl;
    input >> dep.NrAngajati;
    return input;
}

class Firma{
    std::vector<Angajat> lista;
    std::vector<Cladire> listc;
    std::vector<Departament> listd;

public:
    Firma &operator+ (const Angajat& ang) {
        lista.push_back(ang);
        return *this;
    }

    Angajat& getang( int id ) {
        return lista[id];
    }

    Firma &operator+ (const Cladire& cl) {
        listc.push_back(cl);
        return *this;
    }

    Firma &operator+ (const Departament& dep) {
        listd.push_back(dep);
        return *this;
    }
    int getNrAngajati() {
        return lista.size();
    }

    friend ostream &operator<<( ostream &output, const Firma &fir );

    // subpunct 6 7
};

ostream &operator<<( ostream &output, const Firma &fir ) {
    cout << "Angajati: " << endl;
    for (std::vector<Angajat>::const_iterator it = fir.lista.begin(); it != fir.lista.end(); it++) {
        cout << *it;
    }

    cout << "Cladiri: " << endl;
    for (std::vector<Cladire>::const_iterator it = fir.listc.begin(); it != fir.listc.end(); it++) {
        cout << *it;
    }

    cout << "Departamente: " << endl;
    for (std::vector<Departament>::const_iterator it = fir.listd.begin(); it != fir.listd.end(); it++) {
        cout << *it;
    }

    return output;
}

int main()
{
    //Angajat ang(123);
   // ang.id = 10;
    Firma fir;
    int n, m;
    while ( true ){
        cout << "Pentru a accesa sau modifica informatii despre angajati apasati tasta 1, pentru cladiri tasta 2, pentru departamente tasta 3, iar pentru a iesi tasta 0" << endl;
        cin >> n;
        cout << endl;
        if( n == 0 ) {
            break;
        }
        if( n == 1 ){
            cout << "Pentru a afisa informatii despre angajatii firmei apasati tasta 1, iar pentru a introduce informatii tasta 2" << endl;
            cin >> m;
            if ( m == 1 ){
                cout << fir;
            }
            else {
                //adaugam angajat nou
                Angajat ang;
                cin >> ang;
                fir+ang;
            }
        }
        else {
            cout << "Pentru a afisa informatii despre cladirile firmei apasati tasta 1, iar pentru a introduce informatii tasta 2" << endl;
            cin >> m;
            if ( m == 1 ){
                cout << fir; // for dupa ce merge
            }
            else {
                Cladire cl;
                cin >> cl;
                fir+cl;
            }
        }
    }

    return 0;
}
