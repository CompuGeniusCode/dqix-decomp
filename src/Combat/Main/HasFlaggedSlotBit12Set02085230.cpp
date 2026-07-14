#include <globaldefs.h>

extern signed char data_020e8b25[];
extern signed char data_020e8b24[];

// USA: func_02085230
ARM int HasFlaggedSlotBit12Set02085230(unsigned char* actor) {
    int i = 0;
    signed char term;
    while ((term = data_020e8b24[i * 2]) != -1) {
        signed char id = data_020e8b25[i + i];
        if (*(short*)(actor + (id << 5) + 0x1ac) > 0) {
            int v = *(int*)(actor + term * 0x2c + 0x2f4);
            if ((unsigned int)(v << 19) >> 31) {
                return 1;
            }
        }
        i++;
    }
    return 0;
}
