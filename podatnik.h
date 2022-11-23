#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

struct podatnik{
private:
    string nip="0000000000";
    string imie_nazwisko;
public:
    podatnik(string in="Adam Kowalski",string n="0000000000"){
        imie_nazwisko=in;
        if(n.length()!=10){
            cout<<"nieprawidlowa dlugosc nipu!"<<endl;
            nip="0000000000";
        }
        else
            nip=n;
    }
    friend struct kolejka;
    friend ostream &operator<<(ostream &out,podatnik &p);
    podatnik &operator=(podatnik &p){
    imie_nazwisko=p.imie_nazwisko;
    nip=p.nip;
}

};
struct node{
private:
    podatnik data;
    node * next;
    node * prev;
public:
    node(podatnik d,node * n=nullptr,node * p=nullptr){
        data=d;next=n;prev=n;
    }
    node * get_next(){
        return next;
    }
    podatnik get_data(){
        return data;
    }
    friend struct kolejka;
};
struct kolejka{
private:
    node * head=nullptr;
    node * tail=nullptr;
public:
    kolejka()=default;
    node * get_head(){
        return head;
    }
    void dodaj(podatnik p);
    void wypisz();
    ~kolejka();
    friend void wpisz(string nazwa,kolejka kolejeczka);
};
ostream &operator<<(ostream &out,podatnik &p);
//podatnik &podatnik::operator=(podatnik &p);
