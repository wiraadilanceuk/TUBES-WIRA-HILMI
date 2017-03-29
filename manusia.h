#ifndef MANUSIA_H_INCLUDED
#define MANUSIA_H_INCLUDED
#include <iostream>
#define Nil NULL
#define next(P) (P)->next
#define first(L) (L).first
#define info(P) (P)->info

using namespace std;

typedef struct elmlist_p *address_p;

struct info{
    string nama;
    string JK;
    int no_identitas;
    string alamat;
    int umur;
    string gol_darah;
};

typedef info infotype_p;

struct elmlist_p{
    infotype_p info;
    address_p next;

};

struct List_p{

    address_p first;

};



void CreateList(List_p &LP);

void deleteID(List_p &LP, int x);

address_p alokasi(string nama, string JK, int no_identitas, string alamat, int umur, string gol_darah);

void dealokasi(address_p &P);

void insertFirst(List_p &LP, address_p P);

void insertAfter(List_p &LP, int Prec, address_p P);

void insertLast(List_p &LP, address_p P);

address_p findElm(List_p LP, int x);

void deleteFirst(List_p &LP, address_p &P);

void deleteLast(List_p &LP, address_p &P);

void deleteAfter(List_p &LP, address_p &Prec, address_p &P);

void printInfo(List_p LP);

address_p findMinimum(List_p LP);

void insertAscending(List_p &LP, string nama, string JK, int no_identitas, string alamat, int umur, string gol_darah);





#endif // MANUSIA_H_INCLUDED
