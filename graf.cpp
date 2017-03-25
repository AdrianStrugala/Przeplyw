#include "graf.h"


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
graf::graf(){
	lw=0;
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
bool graf::czy_pusty(){
	if(lw==0) return true;
	else return false;
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void graf::wczytaj(string nazwa){
			fstream plik;
			plik.open(nazwa, ios::in);
	if( plik.good()==true){
			
		plik >> lk >> lw >> wp >> wk;



		krawedzi= new krawedz[lk];
		for(int i=0; i<lk; i++){
			plik >> krawedzi[i].po >> krawedzi[i].ko >> krawedzi[i].waga;
		}
		zrob_sasiadow(lw);
	}

	plik.close();
	}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	void graf::zrob_sasiadow(int lw){
		sasiedzi= new int *[lw];
		for(int i=0; i<lw;i++){
			sasiedzi[i]=new int [lw];
		}

		for(int j=0; j<lw; j++){
			for(int i=0; i<lw; i++){
			sasiedzi[j][i] = NO_EDGE;
			}}

		for(int j=0; j<lk; j++){
			sasiedzi[krawedzi[j].po][krawedzi[j].ko]=krawedzi[j].waga;
		}

	}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	void graf::wyswietl_sasiadow(){

		if(!czy_pusty()){
		cout<< "Macierz sasiedztwa (wag)" <<endl;
			for(int j=0; j<lw; j++){
				for(int i=0; i<lw; i++){
					cout << setw(2) << sasiedzi[j][i] << " ";
				}
			cout<<endl;		}
		cout<<endl;
		}
	};
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	void graf::wyswietl_dane(){

		if(!czy_pusty()){
		cout<< "Dane:" <<endl;
			cout<<lk << " " << lw << " " << wp << " " << wk << " "<< endl;
		for(int i=0; i<lk; i++){
			cout << krawedzi[i].po << " " << krawedzi[i].ko << " " << krawedzi[i].waga << endl;
		}
		}
	}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	void graf::zapisz(string nazwa){
			fstream plik;
			plik.open(nazwa, ios::out);
	if( plik.good()==true){
			
		plik << "Dane:" <<endl;
			plik << lk << " " << lw << " " << wp << " " << wk << " "<< endl;
		for(int i=0; i<lk; i++){
			plik << setw(2) << krawedzi[i].po << " " << krawedzi[i].ko << " " << krawedzi[i].waga << endl;

		}
	}

	plik.close();
	};

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	bool graf::czy_krawedz(int n, int m){

		if(n>lw || m>lw){
			cout<< "Podano niepoprawny wierzcholek" <<endl;
			return false;
		}
		else{
			return(sasiedzi[n][m]!=NO_EDGE);

		}
	}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	krawedz graf::najmniejsza(int v){
		
		krawedz min;
		min.po=v;
		min.waga=2147483647;
		for(int i=0; i<lw; i++){
			if(sasiedzi[v][i]<min.waga && sasiedzi[v][i]!=NO_EDGE){
				min.ko=i;
				min.waga=sasiedzi[v][i];
			}
		}
	return min;	
	}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	krawedz graf::najmniejsza(vector<int> k){

		krawedz min;
		min.waga=2147483647;
		for(int i=0; i<k.size(); i++){
			for(int j=0; j<lw; j++){
				if(sasiedzi2[k[i]][j]<min.waga && sasiedzi2[k[i]][j]!=NO_EDGE){
					min.po=k[i];
					min.ko=j;
					min.waga=sasiedzi2[k[i]][j];			
				}
			}
		}
		return min;
	}		


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
		void graf::generuj_graf(int wierz, double ro){
			int a,b;
		lw=wierz;
		wp=0;
		wk=0;
		lk=(ro/100*(lw*lw-lw));   //graf skierowany

		sasiedzi= new int *[lw];
		for(int i=0; i<lw;i++){
			sasiedzi[i]=new int [lw];
		}

		for(int j=0; j<lw; j++){
			for(int i=0; i<lw; i++){
			sasiedzi[j][i] = NO_EDGE;
			}}

		krawedzi= new krawedz[lk];
		for(int i=0; i<lw-1; i++){
			sasiedzi[i][i+1] =(rand()%100)+1;

	}
		int c=lk-lw+1;

		for(int i=0; i<c; i++){
			a=rand()%lw;
			b=rand()%lw;
			if(sasiedzi[a][b]==NO_EDGE && a!=b)
				sasiedzi[a][b] = (rand()%100)+1;
	
			else 
				i--;
		
		}
		int m=0;
		krawedzi= new krawedz[lk];
		for(int j=0; j<lw; j++){
			for(int i=j; i<lw; i++){				//i=j jakbym chcial isc po trojkacie
				if(sasiedzi[j][i]!=NO_EDGE){
					krawedzi[m].po=i;
					krawedzi[m].ko=j;
					krawedzi[m].waga=sasiedzi[j][i];
					m++;
			}
			}

	}

s_drog.clear();
	
		};
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$	
		void graf::Dijkstra(){

						//tablica odpowiadajaca za najkrotsze drogi dla kazdego z elementow
		d= new vector<int>[lw];

		int j=0;								//zmienne pomocnicze
		vector<int> k;								//do wektora naleza wszystkie wierzcholki odwiedzone
		krawedz tym;
		int w=0;

		sasiedzi2= new int *[lw];
		for(int i=0; i<lw;i++){
			sasiedzi2[i]=new int [lw];
		}



		for(int j=0; j<lw; j++){
			for(int i=0; i<lw; i++){
			sasiedzi2[j][i] = sasiedzi[j][i];
			}
		}

		k.push_back(wp);

		d[k[0]].push_back(k[0]);

		for(int i=0; i<lw-1; ){
			tym=najmniejsza(k);
			if(!czy_w_nalezy(tym.ko,k)){
				k.push_back(tym.ko);
				w=0;
				for (int j=0; j<d[tym.po].size()-1; j++){
					w+=sasiedzi[d[tym.po][j]][d[tym.po][j+1]];
				}



				if((w + tym.waga) > sasiedzi[k[0]][tym.ko] && sasiedzi[k[0]][tym.ko]!=NO_EDGE ){
					d[tym.ko].push_back(k[0]);
					d[tym.ko].push_back(tym.ko);
				}
				else{
				d[tym.ko].insert( d[tym.ko].end(), d[tym.po].begin(), d[tym.po].end() );   
				d[tym.ko].push_back(tym.ko);

				}


				i++;
			}
				sasiedzi2[tym.po][tym.ko]=NO_EDGE;
		}
			

			for(int i=0; i<lw; i++){
				w=0;
				for (int j=0; j<d[i].size()-1; j++){

					w+=sasiedzi[d[i][j]][d[i][j+1]];
				}
				s_drog.push_back(w);
			}
		}


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	void graf::Bellman(){

						//tablica odpowiadajaca za najkrotsze drogi dla kazdego z elementow
		d= new vector<int>[lw];
		
		vector<int> o;

		int j=0;								//zmienne pomocnicze
		vector<int> k;								//do wektora naleza wszystkie wierzcholki odwiedzone
		krawedz tym;
		int w=0;

		k.push_back(wp);
		
		o.push_back(k[0]);

		for(int i=0; i<lw; i++){
			s_drog.push_back(MAX_INT);
		}
		
		s_drog[k[0]]=0;


		sasiedzi2= new int *[lw];
		for(int i=0; i<lw;i++){
			sasiedzi2[i]=new int [lw];
		}



		for(int j=0; j<lw; j++){
			for(int i=0; i<lw; i++){
			sasiedzi2[j][i] = sasiedzi[j][i];
			}
		}


	d[k[0]].push_back(k[0]);

	for(int l=0; k.size()>0; l++){
		for(int i=0; i<lw; i++){
			if(sasiedzi2[k[0]][i]!=NO_EDGE){


				if(!czy_w_nalezy(i,o)){
					o.push_back(i);
					k.push_back(i);
				}
				if(s_drog[i]>s_drog[k[0]]+sasiedzi2[k[0]][i]){
					s_drog[i]=s_drog[k[0]]+sasiedzi2[k[0]][i];
					d[i].clear();
					d[i].insert( d[i].end(), d[k[0]].begin(), d[k[0]].end() );
					d[i].push_back(i);
				}
				sasiedzi2[k[0]][i]=NO_EDGE;
			}
		}
		k.erase(k.begin());
	}


			for(int i=0; i<lw; i++){
				w=0;
				for (int j=0; j<d[i].size()-1; j++){

					w+=sasiedzi[d[i][j]][d[i][j+1]];
				}
				s_drog.push_back(w);
			}

		}


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	
void graf::Fulkerson(){

	//sasiedzi2 - przeplywy
	//wp - poczatek
	//wk - koniec

	//wyjscie: maksymalny przeplyw (lista krawedzi zawierajaca max i uzyty przeplyw)

	int cp, fmax=0, j, b, t=3;
	vector<int> kolejka;		//wierzcholki ktore beda odwiedzana

	int *P = new int [lw];		//tablica poprzednikow
	int *Prze= new int [lw];	//tablica przepustowosci  
	sasiedzi2= new int *[lw];	//sasiedzi odpowiadaja za przeplywy

		for(int i=0; i<lw;i++){
			sasiedzi2[i]=new int [lw];
		}

		for(int j=0; j<lw; j++){
			for(int i=0; i<lw; i++){
			sasiedzi2[j][i] = 0;
			}
		}

		while(fmax-t!=0){
			t=fmax;
			for(int i=0; i<lw; i++)
				P[i] = -1;				//-1 oznacza nieodwiedzone
			P[wp] = 0;					//poprzednicy wierzcholka poczatkowego nie istnieja
			Prze[wp]=MAX_INT;

			kolejka.push_back(wp);

			while(kolejka.size()>0){
				for(int i=0; i<lw; i++){
					if(sasiedzi[kolejka[0]][i]!=NO_EDGE){
						cp=sasiedzi[kolejka[0]][i]-sasiedzi2[kolejka[0]][i];
					
						if(cp && (P[i] == -1)){
							P[i]=kolejka[0];		//ustawienie poprzednika

							Prze[i]=Prze[kolejka[0]]>cp ? cp : Prze[kolejka[0]];	//aktualny przeplyw to mniejsza wartosc z przeplywu krawedzi i przeplywu krawedzi poprzednich

								if(i==wk){  //jesli wierzcholek koncowy
					
									fmax+=Prze[i];
									j=wk;

									while(j!= wp){					//pela wsteczna 
										b=P[j];
										sasiedzi2[b][j]+=Prze[i];	//zmiejszanie mozliwego przeplywu
										sasiedzi2[j][b]-=Prze[i];   //przeplyw wsteczny
										j=b;
									}
								}
								kolejka.push_back(i); //jezeli wierzcholek nie jest koncowy
							}
						}
					}
					kolejka.erase(kolejka.begin());
				}
		}

		cout << endl << "fmax = " << fmax << endl << endl;

		for(int x = 0; x < lw; x++)
			 for(int y = 0; y < lw; y++)
				 if(sasiedzi[x][y]) cout <<"(" << x << "," << y << ")" << " " <<  ": " << sasiedzi[x][y] << "|" << sasiedzi2[x][y] << endl;

  cout << endl;

}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

void graf::wyswietl_MR(){
		//wyswietlanie
				for(int i=0; i<lw; i++){
					cout << i << " - Suma: " << setw(3) << s_drog[i] << " Droga: ";
					for(int m=0; m<d[i].size(); m++){
						cout << d[i][m] << " ";
					}
					cout << endl;
				}
		
		};
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	bool graf::czy_w_nalezy(int w, vector<int> k){
			
		for(int i=0; i < k.size(); i++){
				if (w==k[i]) 
					return true;
			}
			return false;
	}

