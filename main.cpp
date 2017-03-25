//Adrian Strugala



#include <fstream>
#include <iostream>
#include <ctime>

#include "graf.h"
using namespace std;

int main(){

	int po,ko,czas,caly_czas=0;
	int lw,ro;
	int ILOSC=1;


	string nazwa = "flow_3.txt";


	graf pierwszy;

	pierwszy.wczytaj(nazwa);

	//pierwszy.Fulkerson();

	

	int zm=0;

	while(zm!=6){

	cout << endl << "Wybierz opcje: " << endl;
	cout << "1 - podaj liczbe wierzcholkow grafu." << endl;
	cout << "2 - podaj gestosc grafu w %." << endl;
	cout << "3 - Dijkstra." << endl;
	cout << "4 - Bellman." << endl;
	cout << "5 - Fulkerson." << endl;
	cout << "6 - Wyjscie." << endl;

	cin>>zm;

	switch(zm){

	case 1:
		cout<<"Podaj liczbe wierzcholkow w grafie"<<endl;
		cin>>lw;
	break;

	case 2:
		cout<<"Podaj gestosc grafu w %"<<endl;
		cin>>ro;
	break;

	case 3:
		caly_czas=0;

		for(int i=0; i<ILOSC; i++){
		pierwszy.generuj_graf(lw, ro);
		po=clock();
		pierwszy.Dijkstra();
		ko=clock();
		czas=ko-po;
		caly_czas+=czas;
		}
		cout << "CZAS: " << caly_czas/ILOSC <<endl;
	break;

	case 4:
		caly_czas=0;

		for(int i=0; i<ILOSC; i++){
		pierwszy.generuj_graf(lw, ro);
		po=clock();
		pierwszy.Bellman();
		ko=clock();
		czas=ko-po;
		caly_czas+=czas;
		}
		cout << "CZAS: " << caly_czas/ILOSC <<endl;
	break;

		case 5:
		caly_czas=0;

		for(int i=0; i<ILOSC; i++){
		pierwszy.generuj_graf(lw, ro);
		po=clock();
		pierwszy.Fulkerson();
		ko=clock();
		czas=ko-po;
		caly_czas+=czas;
		}
		cout << "CZAS: " << caly_czas/ILOSC <<endl;
	break;

	case 6:
		cout<< "KONIEC" <<endl;
		break;

	default:
		cout<< "Niepoeprawna opcja" <<endl;
		break;

	};
	};


	
	system ("pause");



};
