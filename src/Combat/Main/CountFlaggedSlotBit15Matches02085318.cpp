#include <globaldefs.h>

extern signed char data_020e8b5b[];
extern signed char data_020e8b5a[];

// USA: func_02085318
ARM int CountFlaggedSlotBit15Matches02085318(unsigned char* actor) {
    int total;
    int i = 0;
    total = i;
    signed char term;
    while ((term = data_020e8b5a[i * 2]) != -1) {
        signed char id = data_020e8b5b[i + i];
        if (*(short*)(actor + (id << 5) + 0x1ac) > 0) {
            int v = *(int*)(actor + term * 0x2c + 0x2f4);
            if ((unsigned int)(v << 16) >> 31) {
                total++;
            }
        }
        i++;
    }
    return total;
}
