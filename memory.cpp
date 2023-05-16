#include "memory.h"

void Memory::init(/*gpio_num_t pinData, gpio_num_t pinClock*/) {
    f = fopen("agenda.bin", "r+");
    if(f == NULL) {
        f = fopen("agenda.bin", "w+");
        int n1 = 0; 
        int n2 = 999;

        fwrite(&n1, 2, 1, f);
        fwrite(&n2, 2, 1, f);
        /*
        char c1[] = "2"; 
        char c2[] = "5";

        fwrite(c1, 2, 1, f);
        fwrite(c2, 2, 1, f);*/
        if(f == NULL) {
            printf("Could not create file.\n");
        }
    }
}

void Memory::write(void *buffer, uint16_t position, uint16_t size) {
    fseek(f, position, SEEK_SET);
    fwrite(buffer, size, 1, f);
}

void Memory::read(void *buffer, uint16_t position, uint16_t size) {
    fseek(f, position, SEEK_SET);
    fread(buffer, size, 1, f);

    //cout << *buffer << endl;
    //for (int i=0; i<4; i++) {
        //printf("b: %u\n", *buffer);
    //}
}
/*
void init   (/*gpio_num_t pinData, gpio_num_t pinClock) {
    file.open("agenda.bin", ios::in | ios::binary);
}
    
void write  (void *buffer, uint16_t position, uint16_t size) {

}

void read   (void *buffer, uint16_t position, uint16_t size) {
    file.read(buffer, 4);
}*/