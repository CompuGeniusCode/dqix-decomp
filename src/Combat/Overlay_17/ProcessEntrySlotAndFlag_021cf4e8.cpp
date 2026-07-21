#include <globaldefs.h>

struct Entry_02028bd0;
extern "C" unsigned short* func_02012fe4(void);
struct Entry_02028bd0* GetEntryTableBase(void);
struct Entry_02028bd0* FindInlineEntryById(struct Entry_02028bd0* base, int key);

struct Bits021cf4e8 { unsigned short low4:4; unsigned short high12:12; };

// USA: func_ov017_021cf4e8  (semantic: ProcessEntrySlotAndFlag_021cf4e8)
#pragma optimize_for_size off
extern "C" ARM void func_ov017_021cf4e8(void* unusedArg0, unsigned char* entry, unsigned char* table, unsigned char* ctx) {
    int inRange = entry[4] <= 3;
    if (inRange) {
        unsigned char* p = table + entry[4] + 0x7000;
        p[0xf76] = entry[5];
        if (entry[5] == 2) {
            unsigned char* dst = ctx + 0xb4 + 0x4400;
            unsigned short* zone = func_02012fe4();
            struct Entry_02028bd0* found = FindInlineEntryById(GetEntryTableBase(), *zone);
            if (found != 0) {
                *(unsigned short*)dst = *zone;
                *(unsigned short*)(dst + 2) = ((struct Bits021cf4e8*)((char*)found + 2))->high12;
            }
        }
    } else {
        unsigned char* p = table + entry[4] + 0x7000;
        p[0xf76] = 5;
    }
    table[0x7000 + 0xf7a] = table[0x7000 + 0xf7a] | (1 << entry[4]);
}
