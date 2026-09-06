#include <globaldefs.h>

extern signed char data_020e8b13[];
extern signed char data_020e8b12[];

// USA: func_020855d0
ARM int HasFlaggedSlotBit22Set020855d0(unsigned char* actor) {
    int i = 0;
    signed char term;
    while ((term = data_020e8b12[i * 2]) != -1) {
        signed char id = data_020e8b13[i + i];
        if (*(short*)(actor + (id << 5) + 0x1ac) > 0) {
            int v = *(int*)(actor + term * 0x2c + 0x2f4);
            if ((unsigned int)(v << 9) >> 31) {
                return 1;
            }
        }
        i++;
    }
    return 0;
}
