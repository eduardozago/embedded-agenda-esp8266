#include <stdio.h>
#include <inttypes.h>
#include <string.h>


#include <iostream>
#include <string>

using namespace std;

typedef struct {
    uint16_t amountRecords;
    uint16_t amountMax;
} Header;

typedef struct  {
    char name[20];
    char phone[14];
    char address[30];
} Record;

void readHeader(Header *H);

void saveHeader(Header H);

void getAllRecords(Record records[]);

void searchByName(Record *R, string name, int *position);

void searchByPhone(Record *R, string phone, int *position);

void insertRecord(Record R);

void removeRecordByName(string name);

void removeRecordByPhone(string phone);

void removeAll();