#include "manusia.h"

using namespace std;

void CreateList(List_p &LP){

    first(LP) = NULL;

};

address_p alokasi(string nama, string JK, int no_identitas, string alamat, int umur, string gol_darah){

    address_p P;

    P = new elmlist_p;

    info(P).nama = nama;

    info(P).JK = JK;

    info(P).no_identitas = no_identitas;

    info(P).alamat = alamat;

    info(P).umur = umur;

    info(P).gol_darah = gol_darah;

    next(P) = NULL;

        return P;

};

void dealokasi(address_p &P){

    delete P;

};

void insertFirst(List_p &LP, address_p P){

        if (first(LP) == NULL){

            first(LP) = P;

            next(P) = first(LP);

        }

        else{

             address_p Q = first(LP);

        while(next(Q) != first(LP)){

            Q = next(Q);

        };

        next(Q) = P;

        next(P) = first(LP);

            first(LP) = P;

        }

};

void insertLast(List_p &LP, address_p P){

    if (first(LP) == NULL){

        first(LP) = P;

        next(P) = first(LP);

    }

    else{

        address_p Q = first(LP);

        while(next(Q) != first(LP)){

            Q = next(Q);

        };

        next(Q) = P;

        next(P) = first(LP);

    }

};

address_p findElm(List_p LP, int x){

    address_p Q = first(LP);

    if (first(LP) == NULL){

        Q = NULL;

    }

    else{

        while (info(Q).no_identitas != x && next(Q) != first(LP)){

            Q = next(Q);

        }

    }

    return Q;

};

void deleteFirst(List_p &LP, address_p &P){

    if (first(LP) == NULL){



    }

    else if(next(first(LP)) == first(LP)){

        P = first(LP);

        next(P) = NULL;

        first(LP) = NULL;

        dealokasi(P);

    }

    else{

        address_p Q = first(LP);

        P = first(LP);

        while(next(Q) != first(LP)){

            Q = next(Q);

        }

        next(Q) = next(P);

        first(LP) = next(P);

        next(P) = NULL;

        dealokasi(P);

    }

};

void deleteID(List_p &LP, int x){

    address_p P;

    if (first(LP) != NULL){

    P = findElm(LP,x);

    if (info(P).no_identitas == x){

        address_p Q;

        Q = first(LP);

        while(next(Q) != P){

            Q = next(Q);

        }

        deleteAfter(LP,Q,P);

        cout<<"Data telah dihapus\n";

    }

    else{

        cout<<"ID tidak ditemukan";

    }

    }

    else{

        cout<<"Data kosong";

    }

}

void deleteAfter(List_p &LP, address_p &Prec, address_p &P){

    P = first(LP);

    if(next(P) == first(LP)){

        deleteFirst(LP,P);

    }

    else{

        P = next(Prec);

        next(Prec) = next(P);

        next(P) = NULL;

        dealokasi(P);

    }



};

void deleteLast(List_p &LP, address_p &P){

    address_p Q;

    if (first(LP) == NULL){



    }

    else if(next(first(LP)) == first(LP)){

        P = first(LP);

        next(P) = NULL;

        first(LP) = NULL;

        dealokasi(P);

    }

    else{

        P = first(LP);

        Q = first(LP);

        while(next(Q) != first(LP)){

            Q = next(Q);

        }

        while(next(next(P)) != first(LP)){

            P = next(P);

        }

        next(P) = first(LP);

        next(Q) = NULL;

        dealokasi(Q);

    }

};

void printInfo(List_p LP){

    int i;

    i = 1;

    if (first(LP) == NULL){

        cout<<"data kosong";

    }

    else{

    address_p Q;

    Q = first(LP);

    while(next(Q) != first(LP)){

        cout<<"List Psioteraphist ke-"<<i<<"\n";

        cout<<"----------"<<endl;

            cout<<"Nama       :"<<info(Q).nama<<endl;

            cout<<"Jenis Kelamin     :"<<info(Q).JK<<endl;

            cout<<"No Identitas   :"<<info(Q).no_identitas<<endl;

            cout<<"Alamat    :"<<info(Q).alamat<<endl;

            cout<<"Umur   :"<<info(Q).umur<<endl;

            cout<<"Golongan Darah     :"<<info(Q).gol_darah<<endl;

        Q = next(Q);

        i = i+1;

    }cout<<"List Psioteraphist ke-"<<i<<endl;

    cout<<"----------"<<endl;


            cout<<"Nama       :"<<info(Q).nama<<endl;

            cout<<"Jenis Kelamin     :"<<info(Q).JK<<endl;

            cout<<"No Identitas   :"<<info(Q).no_identitas<<endl;

            cout<<"Alamat    :"<<info(Q).alamat<<endl;

            cout<<"Umur   :"<<info(Q).umur<<endl;

            cout<<"Golongan Darah     :"<<info(Q).gol_darah<<endl;

    }

};

void insertAfter(List_p &LP, int Prec, address_p P){

    address_p Q;

    Q = first(LP);

    while(info(Q).no_identitas != Prec){

        Q = next(Q);

    };

    next(P) = next(Q);

    next(Q) = P;

 };

 void insertAscending(List_p &LP, string nama, string JK, int no_identitas, string alamat, int umur, string gol_darah){

    address_p P,Q;

    int prec;

    P = alokasi(nama,JK,no_identitas,alamat,umur,gol_darah);

    if(first(LP) == NULL || info(first(LP)).no_identitas > no_identitas){

        insertFirst(LP, P);

    }

    else{

        Q = first(LP);

        while(next(Q) != first(LP) && info(next(Q)).no_identitas < no_identitas){

            Q = next(Q);

        }

        prec = info(Q).no_identitas;

        insertAfter(LP, prec, P);

    }

};
