#include "memory.h"

void Memory::init(/*gpio_num_t pinData, gpio_num_t pinClock*/) {
    f = fopen("agenda.bin", "r+");
    if(f == NULL) {
        f = fopen("agenda.bin", "w+");
        int n1 = 0; 
        int n2 = 999;

        fwrite(&n1, 2, 1, f);
        fwrite(&n2, 2, 1, f);
        
        if(f == NULL) {
            cout << "Could not create file." << endl;
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
}