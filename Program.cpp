#include "program.h"
#include "manusia.h"
#include "penyakit.h"
#include "Relasi.h"



address_p P,Q;

int pil,a,q,angka,id,idc,p,penya,rel,manus,nom,nim,id1,no_identitas,e;

string b,t,w,x,y,c,d,u,f;

List_p LP;

List_c LC;

List_r LR;



void menu(){

    CreateList(LP);

    CreateList_c(LC);

    CreateList_r(LR);

    pil = 0;

    while(pil != 13){

    cout<<"1.) Insert Manusia\n";

    cout<<"2.) Insert Penyakit\n";

    cout<<"3.) view Manusia\n";

    cout<<"4.) Connecting relation\n";

    cout<<"5.) View Connected\n";

    cout<<"6.) Disconnect Relation\n";

    cout<<"7.) Find Relation \n";

    cout<<"8.) view Penyakit\n";

    cout<<"9.) delete Manusia\n";

    cout<<"10.) delete Penyakit\n";

    cout<<"11.) Find Manusia\n";

    cout<<"12.) Find Penyakit\n";

    cout<<"13.) EXIT \n";

    cout<<"Masukan pilihan anda :  ";

    cin>>pil;

    switch(pil){

    case 1 : insertParents();

             break;

    case 2 : insertchilds();

             break;

    case 3 : viewparents();

             break;

    case 4 : connectrel();

             break;

    case 5 : viewconnected();

             break;

    case 6 : deleterelat();

             break;

    case 7 : findrel();

             break;

    case 8 : viewchilds();

             break;

    case 9 : deleteParents();

             break;

    case 10 : deletechilds();

             break;

    case 11 : FindParents();

             break;

    case 12 : findchilds();

             break;

    };

    }

};

void findrel(){

    address_r PR;

    string pil2;

    cout<<"Masukan ID Penyakit : ";

    cin>>id;

    cout<<"Masukan No identitas      : ";

    cin>>no_identitas;

    PR = findElm_r(LR,id1,no_identitas);

    if (PR == NULL){

        cout<<"maaf list kosong \n";

    }

    else if (info_r(PR).id == id && info_r(PR).no_identitas == no_identitas){

        cout<<"Data ditemukan ingin menampilkannya : (y/t) \n";

        cin>>pil2;

        if (pil2 == "y" || pil2 == "Y"){

            cout<<"----------"<<endl;

            cout<<"ID   :"<<info_r(PR).id<<endl;

            cout<<"Nama penyakit:"<<info_r(PR).nama_penyakit<<endl;

            cout<<"      |     "<<endl;

            cout<<"      |     "<<endl;

            cout<<"      V     "<<endl;

            cout<<"No Identitas       :"<<info_r(PR).no_identitas<<endl;

            cout<<"Nama      :"<<info_r(PR).nama<<endl;

        }

        else{



        }

    }

    else{

        cout<<"Maaf data tidak ditemukan ";

    }

}

void deleterelat(){

    address_p PR;

    address_c CR;

    address_r R;

    cout<<"Masukan ID yang ingin didelete : ";

    cin>>nom;

    cout<<"Masukan No Identitas yang ingin didelete      : ";

    cin>>nim;

    PR = findElm(LP,nom);

    CR = findElm_c(LC,nim);

    R = first_r(LR);

    while(info_r(R).id != nom || info_r(R).no_identitas != nim){

        R = next_r(R);

    }

    deleteRel(LR, R);

};

void findchilds(){

        address_c QC;

    cout<<"Masukan ID yang ingin dicari : ";

    cin>>idc;

    QC = findElm_c(LC,idc);

    if(QC == NULL){

        cout<<"Maaf ID yang anda cari tidak ada \n";

    }

    else if(info_c(QC).id != idc){

        cout<<"ID yang anda cari tidak ditemukan \n";

    }

    else{

            cout<<"ID yang anda cari tersedia dalam list \n";

        cout<<"Apakah anda ingin melihatnya ? (Y/T) \n";

        cin>>u;

        if (u == "Y" || u == "y"){

            address_c QC;

            QC = first(LC);

            if ((QC) == first(LC)){

                cout<<"----------"<<endl;
            cout<<"ID       :"<<info_c(QC).id<<endl;

            cout<<"Nama penyakit     :"<<info_c(QC).nama_penyakit<<endl;

            cout<<"kategori penyakit  :"<<info_c(QC).kategori_penyakit<<endl;

            cout<<"jenis obat   :"<<info_c(QC).jenis_obat<<endl;

            cout<<"jenis penanganan   :"<<info_c(QC).jenis_penanganan<<endl;

            }

            else{

            while(next(QC) != last(LC)){

                    if (info_c(QC).id == idc){

                cout<<"----------"<<endl;

            cout<<"ID       :"<<info_c(QC).id<<endl;

            cout<<"Nama penyakit     :"<<info_c(QC).nama_penyakit<<endl;

            cout<<"kategori penyakit  :"<<info_c(QC).kategori_penyakit<<endl;

            cout<<"jenis obat   :"<<info_c(QC).jenis_obat<<endl;

            cout<<"jenis penanganan   :"<<info_c(QC).jenis_penanganan<<endl;

                    }

                    QC = next(QC);

            }

            if (info_c(QC).id == idc){

                cout<<"----------"<<endl;

               cout<<"ID       :"<<info_c(QC).id<<endl;

            cout<<"Nama penyakit     :"<<info_c(QC).nama_penyakit<<endl;

            cout<<"kategori penyakit  :"<<info_c(QC).kategori_penyakit<<endl;

            cout<<"jenis obat   :"<<info_c(QC).jenis_obat<<endl;

            cout<<"jenis penanganan   :"<<info_c(QC).jenis_penanganan<<endl;

                    }

            }

        }

    }

};

void deletechilds(){

    address_c PC;

    cout<<"Masukan ID yang ingin dihapus : ";

    cin>>penya;

    cout<<"okay\n";

    deleteID_c(LC,penya);

};

void insertchilds(){

    address_c PC;

    cout<<"Masukan id : ";

             cin>>q;

             cout<<"Masukan nama penyakit  : ";

             cin>>t;

             cout<<"Masukan kategori penyakit : ";

             cin>>w;

             cout<<"Masukan Jenis obat : ";

             cin>>x;

             cout<<"Masukan jenis penanganan : ";

             cin>>y;


            PC = alokasi_c(q,t,w,x,y);

        if (first(LC) == NULL){

                insertAscending_c(LC,q,t,w,x,y);

             }

             else{

                PC = findElm_c(LC, q);

                    if (info_c(PC).id != q){

             insertAscending_c(LC, q,t,w,x,y);

                    }

                    else{

            cout<<"ID duplicate\n";

                    }

             }

}

void insertParents(){

    address_p P;

       cout<<"Masukan No Identitas : ";

             cin>>a;

             cout<<"Masukan nama  : ";

             cin>>b;

             cout<<"Masukan alamat : ";

             cin>>c;

             cout<<"Masukan Jenis Kelamin : ";

             cin>>d;

             cout<<"Masukan Umur : ";

             cin>>e;

             cout<<"Masukan Golongan Darah : ";

             cin>>f;

             if (first(LP) == NULL){

                insertAscending(LP,b,d,a,c,e,f);

             }

             else{

                P = findElm(LP, a);

                    if (info(P).no_identitas != a){

                        insertAscending(LP,b,d,a,c,e,f);

                    }

                    else{

                        cout<<"ID duplicate\n";

                    }

             }

    };

void viewparents(){

        printInfo(LP);

             cout<<endl;

    };

void viewchilds(){

     printInfo_c(LC);

             cout<<endl;

}

void deleteParents(){

             cout<<"Masukan No Identitas yang ingin didelete : ";

             cin>>angka;

             deleteID(LP,angka);

    };

void connectrel(){

    address_p P;

    address_c C;

    address_r PR;

    cout<<"Masukan nomor ID  : ";

    cin>>rel;

    cout<<"Masukan nomor No Identitas : ";

    cin>>manus;

    P = findElm(LP,rel);

    C = findElm_c(LC,manus);

    PR = alokasi_r(P,C);

    insertfirst(LR,PR);

};

void viewconnected(){

    printInfo_r(LR);

};

void FindParents(){

    address_p Q;

    cout<<"Masukan No Identitas yang ingin dicari : ";

    cin>>id;

    Q = findElm(LP,id);

    if(Q == NULL){

        cout<<"Maaf No Identitas yang anda cari tidak ada \n";

    }

    else if(info(Q).no_identitas != id){

        cout<<"No Identitas yang anda cari tidak ditemukan \n";

    }

    else{

            cout<<"No Identitas yang anda cari tersedia dalam list \n";

        cout<<"Apakah anda ingin melihatnya ? (Y/T) \n";

        cin>>u;

        if (u == "Y" || u == "y"){

            address_p Q;

            Q = first(LP);

            if ((Q) == first(LP)){

                cout<<"----------"<<endl;
            cout<<"Nama       :"<<info(Q).nama<<endl;

            cout<<"Jenis Kelamin     :"<<info(Q).JK<<endl;

            cout<<"No Identitas   :"<<info(Q).no_identitas<<endl;

            cout<<"Alamat    :"<<info(Q).alamat<<endl;

            cout<<"Umur   :"<<info(Q).umur<<endl;

            cout<<"Golongan Darah     :"<<info(Q).gol_darah<<endl;

            }

            else{

            while(next(Q) != first(LP)){

                    if (info(Q).no_identitas == id){

                cout<<"----------"<<endl;
            cout<<"Nama       :"<<info(Q).nama<<endl;

            cout<<"Jenis Kelamin     :"<<info(Q).JK<<endl;

            cout<<"No Identitas   :"<<info(Q).no_identitas<<endl;

            cout<<"Alamat    :"<<info(Q).alamat<<endl;

            cout<<"Umur   :"<<info(Q).umur<<endl;

            cout<<"Golongan Darah     :"<<info(Q).gol_darah<<endl;


                    }

                    Q = next(Q);

            }

            if (info(Q).no_identitas  == id){

                cout<<"----------"<<endl;

            cout<<"Nama       :"<<info(Q).nama<<endl;

            cout<<"Jenis Kelamin     :"<<info(Q).JK<<endl;

            cout<<"No Identitas   :"<<info(Q).no_identitas<<endl;

            cout<<"Alamat    :"<<info(Q).alamat<<endl;

            cout<<"Umur   :"<<info(Q).umur<<endl;

            cout<<"Golongan Darah     :"<<info(Q).gol_darah<<endl;


                    }

            }

        }

    }



};
