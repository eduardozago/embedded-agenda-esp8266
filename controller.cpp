#include "controller.h"
#include "memory.h"

Memory mem;

void readHeader(Header *H) {
    mem.init();
    mem.read((void*)  H, 0, sizeof(Header));
}

void saveHeader(Header H) {
    mem.init();
    mem.write((void *) &H, 0, sizeof(Header));
}

void getAllRecords(Record records[]) {
    Header H;
    readHeader(&H);

    mem.init();
    for(int i=0; i<H.amountRecords; i++) {
        mem.read((void*) &records[i], sizeof(Header) + 64 * i, sizeof(Record));
    }
    
}

void getRecordByPosition(Record *R, int position) {
    Header H;
    readHeader(&H);

    if(position < H.amountRecords) {
        mem.init();
        mem.read((void*) R, sizeof(Header) + sizeof(Record) * position, sizeof(Record));
    } else {
        cout << "There is no record in this position" << endl;
    }
}

void searchByName(Record *R, string name, int *position) {
    Header header;

    readHeader(&header);

    if(header.amountRecords != 0) {
        Record records[header.amountRecords];

        getAllRecords(records);

        for(int i=0; i<header.amountRecords; i++) {

            for(int j=0; j < name.size() ; j++) {
                if( j == (name.size() - 1) ) {
                    *position = i;
                    break;
                }

                if(records[i].name[j] != name.at(j)) {
                    break;
                }
            }
            
            if(*position == i) {
                getRecordByPosition(R,i);
                break;
            }
        }
    } else {
        cout << "No record registered" << endl;
    }
}

void insertRecord(Record R) {
    Header header;

    readHeader(&header);
    
    int position = header.amountRecords * sizeof(Record) + sizeof(Header);
    
    mem.write((void *) &R, position, sizeof(Record));
    header.amountRecords++;

    saveHeader(header);
}

void removeRecordByName(string name) {
    Header header;
    Record R;

    readHeader(&header);

    if(header.amountRecords != 0) {

        int r;

        searchByName(&R, name, &r);

        if(r != -1) {
            if(r == (header.amountRecords - 1)) {
                // In case of last record

                header.amountRecords--;
                saveHeader(header);
                cout << "Name removed" << endl;
            }
            else {
                Record R;
                
                getRecordByPosition(&R, (header.amountRecords - 1));

                mem.write((void *) &R, r * sizeof(Record) + sizeof(header), sizeof(Record));

                header.amountRecords--;
                saveHeader(header);

                cout << "Name removed" << endl;
            }
        } else {
            cout << "Name not registered" << endl;
        }
    } else {
        cout << "No record registered" << endl;
    }

    

}