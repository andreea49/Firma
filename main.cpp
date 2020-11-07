#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Angajat{

private:

    int id;
    int* todo;
    bool s;
    char n;
    char* todo3;
    char nume[100];
    float salariu;
    double todo1;
    const int CNP;
    static int NrAngajati;

    Init() {
        nume[0] = 0;
        NrAngajati++;
    }

public:
    Angajat(int cnp) {
        CNP = cnp;
        NrAngajati++;
    }

    Angajat(int _cnp, char* _nume) {
        CNP = _cnp;
        strcpy( nume, _nume );
        NrAngajati++;
    }

    //default constructor
    Angajat(){
        NrAngajati++;
    }

    //constructor de copiere
    Angajat( const Angajati& ang ) {
        *this = ang;
        // operator =(ang)
    }

    //destructor
    ~Angajati() {

    }

    //operator de atribuire
    Angajati& operator = ( const Angajat& ang ) {
        cnp = ang.cnp;
        strcpy( nume, ang.nume );
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

    operator int() () {
        return CNP;
    }

    bool operator < ( const Angajati& ang ) {
        return salariu < ang.salariu ;
    }

    bool operator == ( const Angajati& ang ) {
        return CNP == ang.CNP;
    }
};

ostream &operator<<( ostream &output, const Angajat &ang ) {
         output << "Angajat: " << ang.nume << std::endl;
         return output;
}

istream &operator>>( istream  &input, Angajat &ang ) {
    input >> ang.cnp;
    input >> ang.nume;
    //...
    //toate var

    return input;
}

class Cladire{

private:

    int id;
    int* todo;
    char n;
    char* todo33;
    char nume[100];
    float e;
    double todo2;
    const int todo4;
    static int todo5;

public:
    Cladire() = default;
};



class ListaAngajati{
    std::vector<Angajat> lista;

public:
    ListaAngajati &operator+ (const Angajat& ang) {
        lista.push_back(ang);
        return *this;
    }
    Angajat operator[] (const int& index) {
        return lista[index];
    }
};


ostream &operator<<( ostream &output, const Angajat &ang ) {
         output << "Angajat de " << D.pret() << " dobloons" << std::endl;
         return output;
}

istream &operator>>( istream  &input, Angajat &ang ) {
    int pr;
    input >> pr;
    ang.setPretz(pr);
    return input;
}


int main()
{
    Angajat ang(123);
    ang.id = 10;
    ListaAngajati ang;
    int i, n;
    cin >> n;
    for( i = 0; i < n; i++ ) {
        cin >> ang;
        lista = lista + ang;
        cout << "Adaugat " << lista[i];
    }
    return 0;
}
