#include <stdio.h>
#include <inttypes.h> 
#include <iostream>

#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

class Memory {
    private:
        FILE *f;

    public:
        void init   (/*gpio_num_t pinData, gpio_num_t pinClock*/);
        void write  (void *buffer, uint16_t position, uint16_t size);
        void read   (void *buffer, uint16_t position, uint16_t size);
};