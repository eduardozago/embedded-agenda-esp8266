#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include "memory.h"
#include <string>
#include "controller.h"

#include <stdlib.h>
#include <iostream>

//#include "view.h"

void listAll() {
    Header H;
    readHeader(&H);
    Record records[H.amountRecords];
    getAllRecords(records);

    for(int i=0; i<H.amountRecords; i++) {
        cout << "-- REGISTRO " << i << " --" << endl;
        cout << "Nome: " << records[i].name << endl;
        cout << "Telefone: " << records[i].phone << endl;
        cout << "Endereço: " << records[i].address << endl;
    }
}

void nameSearch(string name) {
    Record R;
    int p;

    searchByName(&R, name, &p);

    if(p != -1) {
        cout << "Nome: " << R.name << endl;
        cout << "Telefone: " << R.phone << endl;
        cout << "Endereço: " << R.address << endl;
    }
    
}

int main() {
    //Record R;
    //Header H;

    
    /* ----- LIST ALL ----- */
    /*readHeader(&H);
    Record records[H.amountRecords];
    getAllRecords(records);

    for(int i=0; i<H.amountRecords; i++) {
        // List names
        for(int j=0; j<20; j++) {
            cout << records[i].name[j];
        }

        cout << endl;

        // List phones
        for(int j=0; j<14; j++) {
            cout << records[i].phone[j];
        }

        cout << endl;

        // List addresses
        for(int j=0; j<30; j++) {
            cout << records[i].address[j];
        }

        cout << endl;
    }*/
    /* -------------------------- */


    /* ----- SEARCH BY NAME ----- */
    /*Record R;
    int p;

    searchByName("Artur", &p);

    cout << p << endl;*/
    /* -------------------------- */


    /* ----- INSERT ----- */
    /*Record R;

    strcpy(R.name,"Maria");
	strcpy(R.phone,"4465");
	strcpy(R.address,"Rua Antonio Carlos");

    readHeader(&H);
    // cout << H.amountMax << endl;
    // cout << H.amountRecords << endl;
    insertRecord(R);*/
    /* ------------------ */


    /* ----- REMOVE BY NAME ----- */
    //removeRecordByName("Maria");
    /* -------------------------- */

    //cout << "MENU" << endl;
    //cout << "MENU" << endl;
    while(1) {
        int n;
        printf("MENU\n");
        printf("1 - Listar todos os registros\n");
        printf("2 - Pesquisar por nome\n");
        //printf("3 - \n");
        //printf("4 - List all records\n");
        //printf("5 - List all records\n");
        printf("5 - Sair\n");
        
        scanf("%d", &n);

        if(n == 1) {
            listAll();
        }

        if(n == 2) {
            string name;
            cout << "Digite o nome: " << endl;
            getline(cin, name);
            nameSearch(name);
        }

        if(n == 5) break;
    }
    
}