#include <iostream>


using namespace std;

struct node { // mendefinisikan struct node
    int data; // data dari node
    node *next; // pointer yang menunjukkan alamat node selanjutnya
};

node *head = NULL; // pointer yang berfungsi sebagai head sekaligus mendeklarasikan head = NULL

bool cekKosong() {
    return head == NULL;
}

void insertAfter( node *prev_node, int nilai) {
    if ( prev_node == NULL ) { // cek kondisi head = NULL
        cout << "Nilai sebelumnya tidak boleh NULL";
    }
    node *new_node; // mendeklarasikan node baru
    new_node = new node; // alokasi memori dinamis
    new_node -> data = nilai; // mengisi node data dengan value dari int nilai
    new_node -> next = prev_node -> next; // mengisi node next dengan node next yang ditunjukkan head
    prev_node -> next = new_node; // nengisi node next head dengan menunjukkan node yang baru
}

void insertAkhir( int nilai ) { // fungsi insert pada akhir linked list
    node *new_node; // mendeklarasikan node baru
    node *temp; // pointer untuk operasi insert akhir linked list
    new_node = new node; // alokasi memori dinamis
    new_node -> data = nilai; // mengisi node data dengan value dari int nilai
    new_node -> next = NULL; // mengisi node next pada node baru dengan NULL

    if ( cekKosong()) {
        head = new_node; // pointer head menunjukkan alamat dari node baru
        head -> next = NULL; // mengisi node next pada node baru dengan NULL
    } else {
        temp = head; // pointer temp menunjukkan alamat dari node pertama (yang sebelumnya ditunjukkan oleh pointer head)
        while ( temp -> next != NULL) { // mengecek node next pada temp apakah tidak sama dengan NULL
            temp = temp -> next; // jika tidak sama dengan NULL, maka temp bergeser menuju alamat yang terdapat di node next
        }
        temp -> next = new_node; // jika sama dengan NULL, maka node next akan menunjukkan alamat dari node baru
    }
}



void tampilkanList() { // menampilkan isi dari linked list
    if (!cekKosong()) { // cek kondisi list apakah kosong atau tidak
        node *telusur; // membuat node baru untuk pengecekan penelusuran
        telusur = head; // penelusuran dimulai dari head
        cout << "\n===== Data Linked List =====" << endl;
        while ( telusur != NULL ) { 
            cout << telusur -> data << " "; // menampilkan node data linked list
            telusur = telusur -> next; // bergeser menuju alamat yang terdapat di node next
        }
        cout << endl;
    }
}


//DELETE
void  deleteAwal(){ // delete nilai awal
    node *hapus;
    if(cekKosong()){    //cek kondisi data 
        head =  NULL;
    }
    else{
        if(he ad->next != NULL){ //jika data data tidak kosong maka hapus nilai awal
            hapus = head;
            head = hapus->next;
            delete hapus;
        
        }
    }
}

void  deleteAkhir(){ //delete nilai akhir
    node *hapus, *temp;

    if(cekKosong()){ //cek kondisi nilai akhir
    } else{ 

        temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }                                       //jika nilai akhir tidak kosong maka hapus nilai akhir

        hapus = temp->next;
        temp->next = NULL;
        delete hapus;
        
    }

}

void deleteTengah(int nilai) { //delete nilai tengah
    node *prev = NULL;
    node *temp = head;

    if (cekKosong()) {      //cek kondisi nilai
        return;
    }

    if (head->data == nilai) {              // Jika head/nilai awa itu sendiri memegang
                                            // nilai yang akan dihapus, ubah head 
        head = temp->next;
        delete temp;
        return;
    }
    
    while (temp != NULL && temp->data != nilai)     // Lain Cari nilai yang akan dihapus,
                                                    // lacak node sebelumnya saat kita
                                                    // perlu mengubah 'prev->next' */
    {
        prev = temp;
        temp = temp->next;
    }
 
    if (temp == NULL)
        return;
 
    prev->next = temp->next;
 
    delete temp;    //terhapus
}


int main() {
    system("clear");
    insertAkhir(1);
    insertAkhir(2);
    insertAkhir(3);
    insertAfter(head,15);
    tampilkanList();

    deleteAwal();
    tampilkanList();
    deleteTengah(2);
    tampilkanList();
    deleteAkhir();
    tampilkanList();
}