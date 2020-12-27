#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
bool print=false;

void readString(istream  &input, string& out) {
    string buffer;
    getline(input, buffer);
    while ((buffer.size() == 0) || (buffer[0] == '#')) {
        getline(input, buffer);
    }
    if (input.eof()) {
        cerr << "invalid input format" << endl;
        exit(1);
    }
    out = buffer;
}

void readNumber(istream  &input, int& out) {
    string buffer;
    getline(input, buffer);
    while (buffer[0] == '#') {
        getline(input, buffer);
    }
    if (input.eof()) {
        cerr << "invalid input format" << endl;
        exit(1);
    }
    out = stoi(buffer);
}

void readDouble(istream  &input, double& out) {
    string buffer;
    getline(input, buffer);
    while (buffer[0] == '#') {
        getline(input, buffer);
    }
    if (input.eof()) {
        cerr << "invalid input format" << endl;
        exit(1);
    }
    out = stod(buffer);
}

class Angajat{
    static const int MAX_NUME = 100;
private:

    int id, cld, dept;
    int* idProfesiiAnterioare;
    int nrProfesiiAnterioare;
    bool s;
    char* numeProfesiiAnterioare;
    char nume[MAX_NUME];
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
    virtual ~Angajat() {
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
    if (print)
        cout << "Introduceti CNP: " << endl;
    //input >> ang.CNP;
    readNumber(input, ang.CNP);
    if (print)
        cout << "Introduceti cladirea: " << endl;
    readNumber(input, ang.cld);
    if (print)
        cout << "Introduceti departamentul: " << endl;
    readNumber(input, ang.dept);
    if (print)
        cout << "Introduceti genul ( 0 = masculin, 1 = feminin ) : " << endl;
    int tmpi;
    readNumber(input, tmpi);
    ang.s = (tmpi == 0);
    if (print)
        cout << "Introduceti numele: " << endl;
    string tmp;
    readString(input, tmp);
    if (tmp.size() > Angajat::MAX_NUME) {
        strncpy(ang.nume, tmp.c_str(), Angajat::MAX_NUME - 1 /*consideram doar primele N charactere*/);
        ang.nume[Angajat::MAX_NUME] = 0;
    } else {
        strcpy(ang.nume, tmp.c_str());
    }
    if (print)
        cout << "Introduceti salariu: " << endl;
    double tmpd;
    readDouble(input, tmpd);
    ang.salariu = tmpd;
    if (print)
        cout << "Introduceti inaltime: " << endl;
    readDouble(input, ang.inaltime);

    return input;
}

class Cladire{
    static const int MAX_ADDR = 100;

private:

    int NrEtaje;
    int* ListaCNP;
    bool renovare;
    char* Adresa;
    string nume;
    float valoare;
    double inaltime;
    int NrCladire;
    static const double inaltimeEtaj;
    static int NrCrtCladiri;

    void Init() {
        NrEtaje = 0;
        nume[0] = 0;
        NrCrtCladiri++;
        Adresa = new char[MAX_ADDR];
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
        nume = _nume;
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
        Adresa = new char[MAX_ADDR];
        strcpy(Adresa, _adresa);
    }

    char* GetAdresa(){
        return Adresa;
    }
    //destructor
    virtual ~Cladire() {
        delete ListaCNP;
        delete Adresa;
    }

    //int* ListaCNP; ???

    //operator de atribuire
    Cladire& operator = ( const Cladire& cl ) {
        NrCladire = cl.NrCladire;
        nume = cl.nume;
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
    if (print)
        cout << "Introduceti numarul de etaje: " << endl;
    readNumber(input, cl.NrEtaje);
    if (print)
        cout << "Introduceti numele: " << endl;
    readString(input, cl.nume);
    if (print)
        cout << "Introduceti valoarea: " << endl;
    double tmp;
    readDouble(input, tmp);
    cl.valoare = tmp;
    if (print)
        cout << "Introduceti inaltimea: " << endl;
    readDouble(input, cl.inaltime);
    if (print)
        cout << "Introduceti adresa: " << endl;
    string tmps;
    readString(input, tmps);
    if (tmps.size() > Cladire::MAX_ADDR) {
        strncpy(cl.Adresa, tmps.c_str(), Cladire::MAX_ADDR - 1);
        cl.Adresa[Cladire::MAX_ADDR-1] = 0;
    } else {
        strcpy(cl.Adresa, tmps.c_str());
    }

    if (print)
        cout << "Introduceti daca ii trebuie renovare: " << endl;
    int tmpi;
    readNumber(input, tmpi);
    cl.renovare = (tmpi == 0);
    return input;
}

class Departament{
    int cod;
    int NrCrtAngajati;
    string nume;

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
        nume = _nume;
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
        nume = _nume;
    }

    const char* GetNume(){
        return nume.c_str();
    }
    //destructor
    ~Departament(){
    }

    //operator de atribuire
    Departament& operator = ( const Departament& dep ) {
        cod = dep.cod;
        nume = dep.nume;
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
    if (print)
        cout << "Introduceti numele: " << endl;
    readString(input, dep.nume);
    if (print)
        cout << "Introduceti codul: " << endl;
    readNumber(input, dep.cod);
    return input;
}

class Firma{
    string nume;
    int cui;
    std::vector<Angajat*> lista;
    std::vector<Cladire*> listc;
    std::vector<Departament> listd;

    void Init(){
        cui = 0;
    }

public:

    ~Firma () {
        for (std::vector<Angajat*>::const_iterator it = lista.begin(); it != lista.end(); it++) {
            delete *it;
        }
        for (std::vector<Cladire*>::const_iterator it = listc.begin(); it != listc.end(); it++) {
            delete *it;
        }
    }

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
        nume = _nume;
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

    //operator de atribuire
    Firma& operator = ( const Firma& fir ) {
        cui = fir.cui;
        nume = fir.nume;
        return *this;
    }

    friend ostream &operator<<( ostream &output, const Firma &fir );
    friend istream &operator>>( istream  &input, Firma &fir );
};

ostream &operator<<( ostream &output, const Firma &fir ) {
    output << "Angajati: " << endl;
    for (std::vector<Angajat*>::const_iterator it = fir.lista.begin(); it != fir.lista.end(); it++) {
        output << *(*it);
    }
    output << endl;

    output << "Cladiri: " << endl;
    for (std::vector<Cladire*>::const_iterator it = fir.listc.begin(); it != fir.listc.end(); it++) {
        output << *(*it);
    }
    output << endl;

    output << "Departamente: " << endl;
    for (std::vector<Departament>::const_iterator it = fir.listd.begin(); it != fir.listd.end(); it++) {
        output << *it;
    }
    output << endl;

    return output;
}

istream &operator>>( istream  &input, Firma &fir ) {
    int nrCasieri, nrMng, nrBirou, nrMagazine, nrDep;

    if (print)
            cout << "Introduceti numele firmei: " << endl;
    readString(input, fir.nume);

    if (print)
            cout << "Introduceti cui-ul: " << endl;
    readNumber(input, fir.cui);
    readNumber(input, nrCasieri);
    readNumber(input, nrMng);
    readNumber(input, nrBirou);
    readNumber(input, nrMagazine);
    readNumber(input, nrDep);
    for (int i = 0; i < nrCasieri; i++) {
        Casier* a = new Casier;
        input >> *a;
        fir + a;
    }
    for (int i = 0; i < nrMng; i++) {
        Manager* a = new Manager;
        input >> *a;
        fir + a;
    }
    for (int i = 0; i < nrBirou; i++) {
        Birou* a = new Birou;
        input >> *a;
        fir + a;
    }
    for (int i = 0; i < nrMagazine; i++) {
        Magazin* a = new Magazin;
        input >> *a;
        fir + a;
    }
    for (int i = 0; i < nrDep; i++) {
        Departament a;
        input >> a;
        fir + a;
    }
    return input;
}

int main()
{
    Firma fir;
    int n, nr;
    while ( true ){
        cout << "Apasati:" << endl <<
        "       1 -> pentru angajati" << endl <<
        "       2 -> pentru cladiri" << endl <<
        "       3 -> pentru departamente" << endl <<
        "       4 -> pentru a afisa toata firma" << endl <<
        "       5 -> pentru a incarca totul dintr-un fisier" << endl <<
        "       6 -> pentru a salva totul intr-un fisier" << endl <<
        "       0 -> pentru a iesi" << endl;
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
        if ( n == 5 ) {
            ifstream ifs("file.txt");
            ifs >> fir;
        }
        if ( n == 6 ) {
            ofstream ofs("out.txt");
            ofs << fir;
        }
    }
    return 0;
}
