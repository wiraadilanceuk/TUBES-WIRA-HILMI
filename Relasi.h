#ifndef RELASI_H_INCLUDED

#define RELASI_H_INCLUDED

#include "penyakit.h"

#include "manusia.h"

#include "Relasi.h"

#define Nil NULL

#define next_r(P) (P)->next_r

#define prev_r(P) (P)->prev_r

#define first_r(L) (L).first_r

#define last_r(L) (L).last_r

#define info_r(P) (P)->info_r

using namespace std;



typedef struct elmlist_r *address_r;

struct info_r{

    int id;

    int no_identitas;

    string nama_penyakit;

    string nama;

};

typedef struct info_r infotype_r;

struct elmlist_r{

    infotype_r info_r;

    address_r next_r;

    address_r prev_r;

    address_c penyakit;

    address_p manusia;

};

struct List_r{

    address_r first_r;

    address_r last_r;

};

void CreateList_r(List_r &LR);

void deletefirst_r(List_r &LR,address_r PR);

void insertfirst(List_r &LR, address_r PR);

void deleteRel(List_r &LR, address_r PR);

address_r alokasi_r(address_p PR, address_c CR);

void dealokasi(address_r &PR);

void insertLast(List_r &LR, address_r PR);

address_r findElm_r(List_r LR, int id, int no_identitas);

void printInfo_r(List_r LR);



#endif // RELASI_H_INCLUDED
