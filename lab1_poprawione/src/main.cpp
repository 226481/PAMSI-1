#include <iostream>
#include <fstream>

class Tablica{
    int *tablica;
    int rozmiar;
    int wypelnienie;
    void zmien_rozmiar_tablicy(int nowy_rozmiar);
public:
    void restart(int res_rozmiar);
    void przypisz_o1(int pozycja, int wartosc);
    void przypisz_2x(int pozycja, int wartosc);
    int odczytaj(int pozycja);
    int get_rozmiar();

    Tablica(int con_rozmiar);
    ~Tablica();

    int get_wypelnienie();
};

void Tablica::zmien_rozmiar_tablicy(int nowy_rozmiar) {
    int * nowa_tablica = new int [nowy_rozmiar];
    for (int i=0;i<wypelnienie;i++){
        nowa_tablica[i]=tablica[i];
    }
    delete [] tablica;
    tablica = nowa_tablica;
    nowa_tablica = NULL;
    rozmiar = nowy_rozmiar;
}

void Tablica::przypisz_o1(int pozycja, int wartosc) {
    while (pozycja >= rozmiar) {
        zmien_rozmiar_tablicy(rozmiar+1);
    }
    tablica[pozycja] = wartosc;
    wypelnienie++;
}

void Tablica::przypisz_2x(int pozycja, int wartosc) {
    while (pozycja >= rozmiar) {
        zmien_rozmiar_tablicy(2*rozmiar);
    }
    tablica[pozycja] = wartosc;
    wypelnienie++;
}

int Tablica::odczytaj(int pozycja) {
    if (pozycja < rozmiar){
        return tablica[pozycja];
    } else {
        return 0;
    }
}

int Tablica::get_rozmiar() {
    return rozmiar;
}

int Tablica::get_wypelnienie() {
    return wypelnienie;
}

Tablica::Tablica(int con_rozmiar) {
    rozmiar = con_rozmiar;
    wypelnienie = 0;
    tablica = new int [con_rozmiar];

}

Tablica::~Tablica() {
    delete [] tablica;
}

void Tablica::restart(int res_rozmiar) {
    delete [] tablica;
    rozmiar = res_rozmiar;
    wypelnienie = 0;
    tablica = new int [res_rozmiar];
}


int main() {

    //Tablica tablica(10);

    clock_t start;
    clock_t stop;

    int N = 20;
    double time = 0;
    double av_time = 0;

    std::ofstream file;

    // ------------------------------------------------------------ 2x
    remove("t2x.dat");
    file.open("t2x.dat");
    for (int scale = 10; scale <= 1000000; scale *= 10) {
        for (int n = 0; n < N; n++) {
            start = clock();
            {
                Tablica tablica(10);                //tablica.restart(10);
                for (int i = 0; i < scale; i++) {
                    tablica.przypisz_2x(i, i);
                }
            }
            stop = clock();

            time = difftime(stop, start) / CLOCKS_PER_SEC;
            av_time = av_time + time;
        }
        av_time = av_time/N;
        std::cout << scale << " " << av_time << std::endl;
        file << scale << " " << av_time << std::endl;
        av_time = 0;
    }
    file.close();


    // -------------------------------------------------------------- o1
    remove("to1.dat");
    file.open("to1.dat");
    for (int scale = 10; scale <= 1000000; scale *= 10) {
        for (int n = 0; n < N; n++) {
            start = clock();
            {
                Tablica tablica(10);                //tablica.restart(10);
                for (int i = 0; i < scale; i++) {
                    tablica.przypisz_o1(i, i);
                }
            }
            stop = clock();

            time = difftime(stop, start) / CLOCKS_PER_SEC;
            av_time = av_time + time;
        }
        av_time = av_time/N;
        std::cout << scale << " " << av_time << std::endl;
        file << scale << " " << av_time << std::endl;
        av_time = 0;
    }
    file.close();

    return 0;
}

