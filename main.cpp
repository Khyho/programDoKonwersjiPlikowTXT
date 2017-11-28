#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <windows.h>

using namespace std;

vector <string> wczytajOsobyZPliku (vector <string> ksiazkaAdresowa, string plikDoKonwersji){
    int nr_linii=1;
    int x=0;
    string linia;
    fstream plik;
    string liniaPomocznicza="";
    plikDoKonwersji+=".txt";
    plik.open(plikDoKonwersji.c_str());

    while (getline(plik,linia)){

        switch(nr_linii){
        case 1:
            liniaPomocznicza+=linia+"|";
            break;
        case 2:
            liniaPomocznicza+=linia+"|";
            break;
        case 3:
            liniaPomocznicza+=linia+"|";
            break;
        case 4:
            liniaPomocznicza+=linia+"|";
            break;
        case 5:
            liniaPomocznicza+=linia+"|";
            break;
        case 6:
            liniaPomocznicza+=linia+"|";
            break;
        }
        if (nr_linii==6){
            ksiazkaAdresowa.push_back(liniaPomocznicza);
            nr_linii=0;
            liniaPomocznicza ="";
            x++;
        }
        nr_linii++;
    }

    plik.close();
   return ksiazkaAdresowa;

}

void zapisDoNowegoPliku (vector <string> ksiazkaAdresowa, string plikDoKonwersji){
    fstream plik;
    int i = 0;
    plikDoKonwersji +="_nowy_format.txt";
    plik.open(plikDoKonwersji.c_str(), ios::out);
    if (plik.good()==false){
        cout <<"plik nie istnieje!";
        exit(0);
    }
    while (i < ksiazkaAdresowa.size()){
    plik<<ksiazkaAdresowa[i]<<endl;
    i++;
    }
    plik.close();
    cout <<"Konwersja Zakonczona! Zamieniono "<<ksiazkaAdresowa.size()<<" rekordow."<<endl;
    system ("pause");
}

int main(){
    vector <string> ksiazkaAdresowa;

    string plikDoKonwersji;

    cout << "Podaj nazwe pliku do konwersji:"<<endl;
    cin >> plikDoKonwersji;

    ksiazkaAdresowa = wczytajOsobyZPliku(ksiazkaAdresowa, plikDoKonwersji);

    zapisDoNowegoPliku (ksiazkaAdresowa, plikDoKonwersji);

    return 0;
}
