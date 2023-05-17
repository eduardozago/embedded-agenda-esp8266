#include "view.h"

void listAll() {
    Header H;
    readHeader(&H);
    Record records[H.amountRecords];
    getAllRecords(records);

    cout << endl;

    if(H.amountRecords > 0) {  
        for(int i=0; i<H.amountRecords; i++) {
            cout << "-- Record " << i << " --" << endl;
            cout << "Name: " << records[i].name << endl;
            cout << "Phone: " << records[i].phone << endl;
            cout << "Address: " << records[i].address << endl << endl; 
        }
    } else {
        cout << "There are no records stored" << endl << endl;
    }
}

void nameSearch(string name) {
    Record R;
    int p;

    searchByName(&R, name, &p);

    if(p != -1) {
        cout << endl;
        cout << "Name: " << R.name << endl;
        cout << "Phone: " << R.phone << endl;
        cout << "Address: " << R.address << endl;   
        cout << endl; 
    }
 
}

void phoneSearch(string phone) {
    Record R;
    int p;
    
    searchByPhone(&R, phone, &p);

    if(p != -1) {
        cout << endl;
        cout << "Name: " << R.name << endl;
        cout << "Phone: " << R.phone << endl;
        cout << "Address: " << R.address << endl;
        cout << endl;
    }  
}

void insert(string name, string phone, string address) {

    Record R;

    strcpy(R.name, name.c_str());
	strcpy(R.phone, phone.c_str());
	strcpy(R.address, address.c_str());

    insertRecord(R);
}

void nameRemove(string name) {
    removeRecordByName(name);
}

void phoneRemove(string phone) {
    removeRecordByPhone(phone);
}