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
    static int NrCrtAngajati;

    void Init() {
        cld = 0;
        dept = 0;
        NrCrtAngajati++;
        id = 0;
        idProfesiiAnterioare = new int[100]; // pentru simplitate presupunem ca avem sub 100
        s = true;
        numeProfesiiAnterioare = new char[100];
        numeProfesiiAnterioare[0] = 0;
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
        id = NrCrtAngajati;
        //copiem din _idProfesiiAnterioare in idProfesiiAnterioare
        int* src = _idProfesiiAnterioare;
        int* dst = idProfesiiAnterioare;
        while( *src != 0 ) {
            *dst = *src;
            dst++;
            src++;
            nrProfesiiAnterioare++;
        }
        *dst = 0;
        s = _s;
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
        cld = ang.cld;
        dept = ang.dept;
        nrProfesiiAnterioare = ang.nrProfesiiAnterioare;
        memcpy( idProfesiiAnterioare, ang.idProfesiiAnterioare, nrProfesiiAnterioare* sizeof(int) );
        strcpy( numeProfesiiAnterioare, ang.numeProfesiiAnterioare );
        salariu = ang.salariu;
        inaltime = ang.inaltime;
        return *this;
    }

    //operator de indexare
    int operator [] ( int index ) {
        return 0;
    }

    //operator de incrementare
    Angajat& operator ++ () {
        return *this;
    }

    Angajat& operator + ( const float crestere) {
        salariu += crestere;
        return *this;
    }

    Angajat& operator - ( const float diferenta ) {
        salariu -= diferenta;
        return *this;
    }

    // conversie implicita la int
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

    float GetSalariu() const {
        return salariu;
    }

    void ProfesieNoua( int id, char* nume ) {
        idProfesiiAnterioare[nrProfesiiAnterioare] = id;
        strcat( numeProfesiiAnterioare, ", " );
        strcat( numeProfesiiAnterioare, nume );
        nrProfesiiAnterioare++;
    }

    virtual float GetBonus() const = 0;



    friend ostream &operator<<( ostream &output, const Angajat &ang );
    friend istream &operator>>( istream  &input, Angajat &ang );
};

class Casier : public Angajat {
public:
    float GetBonus() const {
        return GetSalariu() * 2;
    }
};

class Manager : public Angajat {
public:
    float GetBonus() const {
        return GetSalariu() * 10;
    }
};

int Angajat::NrCrtAngajati = 0;
const float Angajat::salariuMinim = 10;

ostream &operator<<( ostream &output, const Angajat &ang ) {
         output << "Angajat id: " << ang.id << std::endl;
         output << "nume: " << ang.nume << std::endl;
         output << "cladire: " << ang.cld << std::endl;
         output << "departament: " << ang.dept << std::endl;
         output << "id profesii anterioare: ";
         for (int i = 0; i < ang.nrProfesiiAnterioare; i++) {
               output << ang.idProfesiiAnterioare[i] << ", ";
         }
         output << std::endl;
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
         output << "bonus: " << ang.GetBonus() << std::endl;
         output << "inaltime: " << ang.inaltime << std::endl;
         output << "CNP: " << ang.CNP << std::endl;
         output << std::endl;
         return output;
}

istream &operator>>( istream  &input, Angajat &ang ) {
    cout << "Introduceti CNP: " << endl;
    input >> ang.CNP;
    cout << "Introduceti cladirea: " << endl;
    input >> ang.cld;
    cout << "Introduceti departamentul: " << endl;
    input >> ang.dept;
    cout << "Introduceti genul ( 0 = masculin, 1 = feminin ) : " << endl;
    input >> ang.s;
    cout << "Introduceti numele: " << endl;
    input >> ang.nume;
    cout << "Introduceti salariu: " << endl;
    input >> ang.salariu;
    cout << "Introduceti inaltime: " << endl;
    input >> ang.inaltime;

    return input;
}

class Cladire{

private:

    int NrEtaje;
    int* ListaCNP;
    bool renovare;
    char* Adresa;
    char nume[100];
    float valoare;
    double inaltime;
    int NrCladire;
    static const double inaltimeEtaj;
    static int NrCrtCladiri;

    void Init() {
        NrEtaje = 0;
        nume[0] = 0;
        NrCrtCladiri++;
        Adresa = new char[100];
        ListaCNP = 0;
        renovare = false;
        valoare = 0;
        inaltime = 0;
        NrCladire = 0;
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
        valoare = cl.valoare;
        renovare = cl.renovare;
        return *this;
    }

    //operator de indexare
    int operator [] ( int index ) {
        return 0;
    }

    //operator de incrementare
    Cladire& operator ++ () {
        return *this;
    }

    Cladire& operator + ( int diferenta ) {
        valoare += diferenta;
        return *this;
    }

    Cladire& operator - ( int diferenta ) {
        valoare -= diferenta;
        return *this;
    }

    // conversie implicita la int
    operator int() {
        return NrCladire;
    }

    bool operator < ( const Cladire& cl ) {
        return valoare < cl.valoare;
    }

    bool operator == ( const Cladire& cl ) {
        return NrCladire == cl.NrCladire;
    }

    float GetValoare() const {
        return valoare;
    }

    virtual float GetBonus() const = 0;

    friend ostream &operator<<( ostream &output, const Cladire &cl );
    friend istream &operator>>( istream  &input, Cladire &cl );
};

class Magazin : public Cladire {
public:
    float GetBonus() const {
        return GetValoare() * 2;
    }
};

class Birou  : public Cladire {
public:
    float GetBonus() const {
        return GetValoare() * 10;
    }
};

int Cladire::NrCrtCladiri = 0;

ostream &operator<<( ostream &output, const Cladire &cl ) {
         output << "Numar etaje: " << cl.NrEtaje << std::endl;
         output << "Nume: " << cl.nume << std::endl;
         output << "Valoare: " << cl.valoare<< std::endl;
         output << "Valoarea modificata pentru cladirea precizata: " << cl.GetBonus() << std::endl;
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
         output << std::endl;
         return output;
}

istream &operator>>( istream  &input, Cladire &cl ) {
    cout << "Introduceti numarul de etaje: " << endl;
    input >> cl.NrEtaje;
    cout << "Introduceti numele: " << endl;
    input >> cl.nume;
    cout << "Introduceti valoarea: " << endl;
    input >> cl.valoare;
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
    int NrCrtAngajati;
    char nume[100];

    void Init() {
        cod = 0;
        NrCrtAngajati = 0;
        nume[0] = 0;
    }

public:
    Departament(int _cod) {
        Init();
        cod = _cod;
    }

    Departament(int _cod, char* _nume) {
        Init();
        cod = _cod;
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
    Departament& operator ++ () {
        return *this;
    }

    Departament& operator + ( int ang ) {
        NrCrtAngajati += ang;
        return *this;
    }

    Departament& operator - ( int ang ) {
        NrCrtAngajati -= ang;
        return *this;
    }

    // conversie implicita la int
    operator int() {
        return cod;
    }

    bool operator < ( const Departament& dep ) {
        return NrCrtAngajati < dep.NrCrtAngajati ;
    }

    bool operator == ( const Departament& dep ) {
        return cod == dep.cod;
    }

    friend ostream &operator<<( ostream &output, const Departament &dep );
    friend istream &operator>>( istream  &input, Departament &dep );

};

ostream &operator<<( ostream &output, const Departament &dep ) {
         output << "Nume: " << dep.nume << std::endl;
         output << "Numarul de angajati: " << dep.NrCrtAngajati << std::endl;
         output << "Codul: " << dep.cod << std::endl;
         output << std::endl;
         return output;
}

// _idProfesiiAnterioare, char* _numeProfesiiAnterioare,

istream &operator>>( istream  &input, Departament &dep ) {
    cout << "Introduceti numele: " << endl;
    input >> dep.nume;
    cout << "Introduceti codul: " << endl;
    input >> dep.cod;
    return input;
}

class Firma{
    char nume[100];
    int cui;
    std::vector<Angajat*> lista;
    std::vector<Cladire*> listc;
    std::vector<Departament> listd;

    void Init(){
        nume[0] = 0;
        cui = 0;
    }

public:
    Firma &operator+ (Angajat* ang) {
        lista.push_back(ang);
        return *this;
    }

    Angajat* getang( int id ) {
        return lista[id];
    }

    Firma &operator+ (Cladire* cl) {
        listc.push_back(cl);
        return *this;
    }

    Firma &operator+ (const Departament& dep) {
        listd.push_back(dep);
        return *this;
    }
    int getNrCrtAngajati() {
        return lista.size();
    }

    //constructor cu un parametru
    Firma(int _cui) {
        Init();
        cui = _cui;
    }

    Firma(int _cui, char* _nume) {
        Init();
        cui = _cui;
        strcpy( nume, _nume );
    }

    //default constructor
    Firma(){
        Init();
    }

    //constructor de copiere
    Firma( const Firma& fir ) {
        Init();
        *this = fir;
        // operator =(ang)
    }

    //destructor
    ~Firma() {
    }

    //operator de atribuire
    Firma& operator = ( const Firma& fir ) {
        cui = fir.cui;
        strcpy( nume, fir.nume );
        return *this;
    }

    friend ostream &operator<<( ostream &output, const Firma &fir );
    friend istream &operator>>( istream  &input, Firma &fir );
};

ostream &operator<<( ostream &output, const Firma &fir ) {
    cout << "Angajati: " << endl;
    for (std::vector<Angajat*>::const_iterator it = fir.lista.begin(); it != fir.lista.end(); it++) {
        cout << *(*it);
    }
    cout << endl;

    cout << "Cladiri: " << endl;
    for (std::vector<Cladire*>::const_iterator it = fir.listc.begin(); it != fir.listc.end(); it++) {
        cout << *(*it);
    }
    cout << endl;

    cout << "Departamente: " << endl;
    for (std::vector<Departament>::const_iterator it = fir.listd.begin(); it != fir.listd.end(); it++) {
        cout << *it;
    }
    cout << endl;

    return output;
}

istream &operator>>( istream  &input, Firma &fir ) {
    cout << "Introduceti numele firmei: " << endl;
    input >> fir.nume;
    cout << "Introduceti cui-ul: " << endl;
    input >> fir.cui;
    return input;
}

int main()
{
    //Angajat ang(123);
   // ang.id = 10;
    Firma fir;
    int n, nr;
    cout << "Introduceti informatii despre firma: " << endl;
    cin >> fir;
    while ( true ){
        cout << "Pentru a introduce informatii despre angajati apasati tasta 1, pentru cladiri tasta 2, pentru departamente tasta 3, pentru a afisa toata firma tasta 4, iar pentru a iesi tasta 0" << endl;
        cin >> n;
        cout << endl;
        if( n == 0 ) {
            break;
        }
        if( n == 1 ){
            cout << "Apasati tasta 1 pentru casier, iar 2 pentru manager" << endl;
            //adaugam angajat nou
            cin >> nr;
            Angajat* a = NULL;
            if ( nr == 1 ) {
                a = new Casier;
            }
            else {
                a = new Manager;
            }
            cin >> *a;
            fir + a;
        }
        if ( n == 2 ) {
            cout << "Apasati tasta 1 pentru magazine, iar 2 pentru birouri" << endl;
            cin >> nr;
            Cladire* c = NULL;
            if ( nr == 1 ) {
                c = new Magazin;
            }
            else {
                c = new Birou;
            }
            cin >> *c;
            fir + c;
        }
        if ( n == 3 ) {
            Departament dep;
            cin >> dep;
            fir+dep;
        }
        if ( n == 4 ) {
            cout << fir;
        }
    }
    return 0;
}
