#include <globaldefs.h>

struct PackedCombatStat0x194 {
    unsigned int charm : 10;
    unsigned int magicalMight : 10;
    unsigned int magicalMending : 10;
};

// USA: func_02084e78
ARM float AccumulateMagicalMending02084e78(void* param0) {
    float sum = 0.0f;
    int i = 0;
    while (i < 0xb) {
        char* rec = (char*)param0 + (i << 5);
        if (*(short*)(rec + 0x1ac) > 0) {
            char* base = *(char**)(rec + 0x194);
            struct PackedCombatStat0x194* ptr = (struct PackedCombatStat0x194*)(base + 0xc);
            unsigned int comp = ptr->magicalMending;
            sum = sum + ((float)comp / 10.0f);
        }
        i++;
    }
    return sum;
}
