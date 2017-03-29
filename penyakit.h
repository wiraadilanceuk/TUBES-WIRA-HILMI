#ifndef PENYAKIT_H_INCLUDED
#define PENYAKIT_H_INCLUDED
#include <iostream>
#define Nil NULL
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) (L).first
#define last(L) (L).last
#define info_c(P) (P)->info_c

using namespace std;



typedef struct elmlist_c *address_c;

struct info_c{
    int id;
    string nama_penyakit;
    string kategori_penyakit;
    string jenis_obat;
    string jenis_penanganan;
};

typedef info_c infotype_c;

struct elmlist_c{

    infotype_c info_c;

    address_c next;

    address_c prev;

};

struct List_c{

    address_c first;

    address_c last;

};



void CreateList_c(List_c &LC);

void deleteID_c(List_c &LC, int x);

address_c alokasi_c(int id, string nama_penyakit, string kategori_penyakit, string jenis_obat, string jenis_penanganan);

void dealokasi_c(address_c &PC);

void insertFirst_c(List_c &LC, address_c PC);

void insertAfter_c(List_c &LC, int Precc, address_c PC);

void insertLast_c(List_c &LC, address_c PC);

address_c findElm_c(List_c LC, int x);

void deleteFirst_c(List_c &LC, address_c &PC);

void deleteafter_c(List_c &LC, address_c &Precc, address_c &PC);

void deleteLast_c(List_c &LC, address_c &PC);

void printInfo_c(List_c LC);

address_c findMinimum_c(List_c LC);

void insertAscending_c(List_c &LC, int id, string nama_penyakit, string kategori_penyakit, string jenis_obat, string jenis_penanganan);



#endif // PENYAKIT_H_INCLUDED
