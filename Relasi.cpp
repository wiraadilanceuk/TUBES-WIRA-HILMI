#include "Relasi.h"



using namespace std;



void CreateList_r(List_r &LR){

    first_r(LR) = NULL;

    last_r(LR)  = NULL;

};

void deletefirst_r(List_r &LR,address_r PR){

    PR = first_r(LR);

    if (first_r(LR) == NULL){

        cout<<"Data kosong \n";

    }

    else if(PR == last_r(LR)){

        first_r(LR) = NULL;

        last_r(LR) = NULL;

        dealokasi(PR);

    }

    else{

        prev_r(next_r(PR)) = NULL;

        first_r(LR) = next_r(PR);

        next_r(PR) = NULL;

        dealokasi(PR);

    }

}

void deleteRel(List_r &LR, address_r PR){

    if (first_r(LR) == NULL){

        cout<<"Data kosong";

    }

    else if(first_r(LR) == last_r(LR)){

        deletefirst_r(LR,PR);

    }

    else{

        address_r QR;

        QR = prev_r(PR);

        next_r(QR) = next_r(PR);

        prev_r(next_r(PR)) = QR;

        next_r(PR) = NULL;

        prev_r(PR) = NULL;

        dealokasi(PR);

    }

};

address_r alokasi_r(address_p P, address_c C){

    address_r PR;

    PR = new elmlist_r;

    info_r(PR).no_identitas = info(P).no_identitas;

    info_r(PR).nama= info(P).nama;

    info_r(PR).id  = info_c(C).id ;

    info_r(PR).nama_penyakit = info_c(C).nama_penyakit;

    next_r(PR) = NULL;

    prev_r(PR) = NULL;

    return PR;
};

void dealokasi(address_r &PR){

    delete PR;

};

void insertLast(List_r &LR, address_r PR){

    address_r R;

    address_p P;

    address_c C;

    R = first_r(LR);

    PR = alokasi_r(P,C);

    while(R != last_r(LR)){

        R = next_r(R);

    };

    next_r(R) = PR;

    prev_r(PR) = R;

    last_r(LR) = PR;

};

address_r findElm_r(List_r LR, int id, int no_identitas){

    address_r PR = first_r(LR);

    if (first_r(LR) == NULL){

        PR = NULL;

    }

    else{

        while (info_r(PR).no_identitas != no_identitas && info_r(PR).id != id && next_r(PR) != last_r(LR)){

            PR = next_r(PR);

        }



    }

    return PR;

};

void printInfo_r(List_r LR){

    int i;

    i = 1;

    if (first_r(LR) == NULL){

        cout<<"data kosong";

    }

    else{

    address_r PR;

    PR = first_r(LR);

    while(PR != last_r(LR)){

        cout<<"List Pasien ke-"<<i<<"\n";

        cout<<"----------"<<endl;

            cout<<"ID   :"<<info_r(PR).id<<endl;

            cout<<"Nama penyakit:"<<info_r(PR).nama_penyakit<<endl;

            cout<<"      |     "<<endl;

            cout<<"      |     "<<endl;

            cout<<"      V     "<<endl;

            cout<<"No Identitas       :"<<info_r(PR).no_identitas<<endl;

            cout<<"Nama      :"<<info_r(PR).nama<<endl;

        PR = next_r(PR);

        i = i+1;

    }cout<<"List Pasien ke-"<<i<<endl;

    cout<<"----------"<<endl;

            cout<<"ID   :"<<info_r(PR).id<<endl;

            cout<<"Nama penyakit:"<<info_r(PR).nama_penyakit<<endl;

            cout<<"      |     "<<endl;

            cout<<"      |     "<<endl;

            cout<<"      V     "<<endl;

            cout<<"No Identitas       :"<<info_r(PR).no_identitas<<endl;

            cout<<"Nama      :"<<info_r(PR).nama<<endl;

    }

};

void insertfirst(List_r &LR, address_r PR){

    if (first_r(LR) == NULL){

        first_r(LR) = PR;

        last_r(LR) = PR;

    }

    else{

        next_r(PR) = first_r(LR);

        prev_r(first_r(LR)) = PR;

        first_r(LR) = PR;

    }

};
