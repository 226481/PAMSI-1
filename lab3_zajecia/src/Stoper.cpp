#include "../inc/Stoper.hh"

double Stoper::wykonaj_pomiar(Testowalny *obiekt, int ilosc_pomiarow, int nr_algorytmu, int ilosc_elem){
	srand(time(NULL));
	clock_t start;
	clock_t stop;
	double diff_time;
	av_time = 0;
	wyp_ilosc_elem = ilosc_elem;
	for (int i=0; i<ilosc_pomiarow; i++){
			start = clock();
			obiekt->wykonaj_obliczenia(nr_algorytmu, ilosc_elem, rand()%10);
			stop = clock();

			diff_time = difftime(stop, start) / CLOCKS_PER_SEC;
			av_time = av_time + diff_time;
	}
	av_time = av_time/ilosc_pomiarow;
	return av_time;
}

void Stoper::wypisz_pomiar(std::ostream & stream){
	stream << wyp_ilosc_elem << " " << av_time << "\n";
}

Stoper::Stoper(){
	av_time = 0;
	wyp_ilosc_elem = 0;
}

Stoper::~Stoper(){

}