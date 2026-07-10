#include <globaldefs.h>

struct SqrtRegs020c2eb8 {
    volatile unsigned short cnt;
    unsigned char pad[6];
    volatile long long param;
};

// USA: func_020c2eb8
ARM int Vec3LengthRounded(int* v) {
    struct SqrtRegs020c2eb8* sq = (struct SqrtRegs020c2eb8*)0x40002b0;
    long long sum = (long long)v[0] * v[0];
    sum = (long long)v[1] * v[1] + sum + (long long)v[2] * v[2];
    sq->cnt = 1;
    sq->param = sum << 2;
    while (sq->cnt & 0x8000) {}
    return (*(volatile int*)0x40002b4 + 1) >> 1;
}
