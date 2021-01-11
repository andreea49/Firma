/* Voicu Andreea 211
GCC (windows, codeblocks)
Eduard Gabriel Szmeteanca */

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Vaccin {
    int pret, temp;
    string substante; //poate fi vector
public:
    virtual void afisareSchemaVaccinare() = 0;
    friend istream &operator>>( istream &input, Vaccin &v );
    friend ostream &operator<<( ostream &output, const Vaccin &v );
};

istream &operator>>( istream &input, Vaccin &v ){
    cout << "pretul: " << endl;
    input >> v.pret;
    cout << endl;
    cout << "temperatura de depozitare: " << endl;
    input >> v.temp;
    cout << endl;
}

ostream &operator<<( ostream &output, const Vaccin &v ) {
    output << "pret: " << v.pret << endl;
    output << "temperatura de depozitare: " << v.temp << endl;
}

class VaccinAntigripal : public Vaccin {
    int tulpina, respecta;
public:
    void afisareSchemaVaccinare() {
        cout << "e administrează la adulți o doză de 0.5 ml, iar la copii și adolescenți o doză de 0.3 ml, repetându-se din 2 în 2 ani";
    }
};

class VaccinAntihepatic : public Vaccin {
    char t;
    string modvac;
public:
    void afisareSchemaVaccinare() {
        cout << "A și B, la copii cu vârstă mai mică de 1 an se adminstrează 2 injectări la un interval de o lună, a treia injectare după 6 luni de la prima administrare, laadulți conform schemei de imunizare recomandată de medic, cel Antihepatită C doar la recomandarea medicului";
    }
};

class VaccinAntiSarsCov2 : public Vaccin {
    int rata;
    string reactii, medcontra;
public:
    void afisareSchemaVaccinare() {
        cout << "se administrează persoanelor cu vârstă de peste 16 ani, 2 doze la o perioadă de 21 zile";
    }
};

class Comanda {
    int id;
    string data, nume, spital;
public:
    Comanda(const string &_data, const string &_spital, const string &_nume, int _id) {
        data = _data;
        spital = _spital;
        nume = _nume;
        id = _id;
    }

    friend ostream &operator<<( ostream &output, const Comanda &c );
};

ostream &operator<<( ostream &output, const Comanda &c ) {
    output << "data: " << c.data << endl;
    output << "spital: " << c.spital << endl;
    output << "nume: " << c.nume << endl;
    output << "id: " << c.id << endl;

}

class ListaComenzi {
    vector <Comanda> lista;
public:
    ListaComenzi &operator+ (Comanda& c) {
        lista.push_back(c);
        return *this;
    }
    Comanda &operator[](int i) {
        return lista[i];
    }
};

int main()
{
    VaccinAntigripal a;
    VaccinAntihepatic b;
    VaccinAntiSarsCov2 c;
    cin>>a>>b>>c;
    cout<<a<<b<<c;
    Vaccin* list[3];
    list[0]=new VaccinAntigripal();
    list[1]=new VaccinAntihepatic();
    list[2]=new VaccinAntiSarsCov2();
    for(int i=0;i<3;i++)
        list[i]->afisareSchemaVaccinare();
    Comanda com1("20-12-2020", "SpitalX", "AntiSarsCov2",20);
    ListaComenzi lista;lista=lista+com1;
    cout<<lista[0];
    return 0;
}
