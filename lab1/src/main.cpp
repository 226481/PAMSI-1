#include <iostream>

class Tablica{
    int *tablica;
    int rozmiar_max;
    int rozmiar;
    void powieksz_tablice(int nowy_rozmiar);
public:
    void przypisz(int pozycja, int wartosc);
    int odczytaj(int pozycja);
    int get_rozmiar();
    int j;

    Tablica(int rozmiar);
    ~Tablica();
};

void Tablica::powieksz_tablice(int nowy_rozmiar_max) {
    int * nowa_tablica = new int [nowy_rozmiar_max];
    for (int i=0;i<rozmiar;i++){
        nowa_tablica[i]=tablica[i];
        j++;
    }
    for (int i=rozmiar;i<nowy_rozmiar_max;i++){
        nowa_tablica[i]=1;
    }
    delete [] tablica;
    tablica = nowa_tablica;
    rozmiar_max = nowy_rozmiar_max;
}

void Tablica::przypisz(int pozycja, int wartosc) {
    while (pozycja >= rozmiar_max) {
        powieksz_tablice(rozmiar_max + 10);
    }
    tablica[pozycja] = wartosc;
}

int Tablica::odczytaj(int pozycja) {
    if (pozycja < rozmiar_max){
        return tablica[pozycja];
    } else {
        return 2;
    }
}

int Tablica::get_rozmiar() {
    return rozmiar;
}

Tablica::Tablica(int pocz_rozmiar_max) {
    rozmiar = 0;
    powieksz_tablice(pocz_rozmiar_max);
    for (int i=0;i<pocz_rozmiar_max;i++){
        tablica[i]=1;
    }
    j=0;
}

Tablica::~Tablica() {
    delete [] tablica;
}


int main() {
    Tablica tablica(10);

    for (int i=0;i<15;i++){
        tablica.przypisz(i,i);

        for (int i=0;i<25;i++){
            std::cout << tablica.odczytaj(i) << " ";
        }
        std::cout << "___" << tablica.get_rozmiar() << std::endl;
    }

    std::cout << std::endl << tablica.j;
    return 0;
}