#include <iostream>
#include <fstream>
#include <cstdlib>
#include "podatnik.h"
using namespace std;

void pobierz_nipy(string nazwa,kolejka & piotrkow,kolejka & radomsko,kolejka & tomaszow,kolejka & bledne){
fstream plik;
plik.open(nazwa,ios::in);
if(!plik.good()){
    cout<<"nieprawidlowa nazwa pliku"<<endl;exit(0);
}
string linia;
while(getline(plik,linia)){
    string nip,imie_nazwisko,trzy_pierwsze;;
        for(int i=0;i<3;i++){
            trzy_pierwsze+=linia[i];
        }
    for(int i=0;i<10;i++){
        nip+=linia[i];
    }
    for(int i=10;i<linia.length();i++){
        imie_nazwisko+=linia[i];
    }

    if((!isdigit(atoi(nip.c_str())))&&(!isspace(linia[10]))){
        if(!isdigit(atoi(nip.c_str())))
            imie_nazwisko+=" to nie jest numerem";
        else{
            imie_nazwisko+=" nieprawidlowa dlugosc nip";
        }
        podatnik p(imie_nazwisko,nip);
        bledne.dodaj(p);
    }
    else{
        if(atoi(trzy_pierwsze.c_str())==771){
            podatnik p(imie_nazwisko,nip);
            piotrkow.dodaj(p);
        }
        else if(atoi(trzy_pierwsze.c_str())==772){
            podatnik p(imie_nazwisko,nip);
            radomsko.dodaj(p);
        }
        else if(atoi(trzy_pierwsze.c_str())==773){
            podatnik p(imie_nazwisko,nip);
            tomaszow.dodaj(p);
        }
        else{
            imie_nazwisko+=" nie pasuje do zadnego miasta";
            podatnik p(imie_nazwisko,nip);
            bledne.dodaj(p);
        }

    }
}
plik.close();
}
void wpisz(string nazwa,kolejka kolejeczka){
    fstream plik;
    plik.open(nazwa,ios::app | ios ::out);
    node * current=kolejeczka.get_head();
    while(current!=nullptr){
        podatnik p=(*current).get_data();
        plik<<p;
        current=current->get_next();
    }
    plik.close();
}


int main(){
    kolejka p;
    kolejka r;
    kolejka t;
    kolejka b;
    podatnik po;
    pobierz_nipy("nipy.txt",p,r,t,b);
    wpisz("tomaszow.txt",t);
    wpisz("radomsko.txt",r);
    wpisz("piotrkow.txt",p);
    b.wypisz();
return 0;
}
