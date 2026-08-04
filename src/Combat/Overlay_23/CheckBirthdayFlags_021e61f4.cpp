#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int CalculateAge(int birthYear, int birthMonth, int birthDay);

struct DaysTable021e61f4 { int v[12]; };
extern struct DaysTable021e61f4 data_ov023_021fd72c;

// USA: func_ov023_021e61f4  (semantic: CheckBirthdayFlags_021e61f4)
extern "C" ARM void func_ov023_021e61f4(void* obj) {
    struct DaysTable021e61f4 daysInMonth = data_ov023_021fd72c;
    char* base = (char*)obj;
    *(unsigned char*)(base + 0x13ab) = 0;

    GetBattleStruct();

    int age = CalculateAge(*(unsigned short*)(base + 0x13fc), *(unsigned char*)(base + 0x13fe), *(unsigned char*)(base + 0x13ff));
    if (age < 0x82) *(unsigned char*)(base + 0x13ab) |= 0x2;
    if (age > 0) *(unsigned char*)(base + 0x13ab) |= 0x1;

    if (*(unsigned char*)(base + 0x13fe) < 12) {
        int age2 = CalculateAge(*(unsigned short*)(base + 0x13fc), *(unsigned char*)(base + 0x13fe) + 1, *(unsigned char*)(base + 0x13ff));
        if (age2 >= 0) *(unsigned char*)(base + 0x13ab) |= 0x4;
    }
    if (*(unsigned char*)(base + 0x13fe) > 1) {
        int age3 = CalculateAge(*(unsigned short*)(base + 0x13fc), *(unsigned char*)(base + 0x13fe) - 1, *(unsigned char*)(base + 0x13ff));
        if (age3 <= 0x82) *(unsigned char*)(base + 0x13ab) |= 0x8;
    }

    if (*(unsigned short*)(base + 0x13fc) % 4 == 0) daysInMonth.v[1] = 29;
    unsigned char month = *(unsigned char*)(base + 0x13fe);
    unsigned char day = *(unsigned char*)(base + 0x13ff);
    if (day < daysInMonth.v[month - 1]) {
        int age4 = CalculateAge(*(unsigned short*)(base + 0x13fc), month, day + 1);
        if (age4 >= 0) *(unsigned char*)(base + 0x13ab) |= 0x10;
    }

    if (*(unsigned char*)(base + 0x13ff) > 1) {
        int age5 = CalculateAge(*(unsigned short*)(base + 0x13fc), *(unsigned char*)(base + 0x13fe), *(unsigned char*)(base + 0x13ff) - 1);
        if (age5 <= 0x82) *(unsigned char*)(base + 0x13ab) |= 0x20;
    }
}
