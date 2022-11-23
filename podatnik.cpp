#include <iostream>
#include <fstream>
#include <cstdlib>
#include "podatnik.h"
using namespace std;

kolejka::~kolejka(){
    node * killer;
    while(head=nullptr){
        killer=head;
        head=head->next;
        delete killer;
    }
}
void kolejka::dodaj(podatnik p){
    node * dodawany=new node (p);
    if(head==nullptr){
        head=dodawany;
        tail=dodawany;
    }
    else{
        tail->next=dodawany;
        tail=dodawany;
    }
}
void kolejka::wypisz(){
    node * current=head;
    while(current!=nullptr){
        cout<<current->data.nip<<","<<current->data.imie_nazwisko<<endl;
        current=current->next;
    }
}
ostream &operator<<(ostream &out,podatnik &p){
        out<<p.nip<<" "<<p.imie_nazwisko<<endl;
    }


