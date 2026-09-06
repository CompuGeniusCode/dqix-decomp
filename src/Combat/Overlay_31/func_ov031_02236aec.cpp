#include <globaldefs.h>

struct Header_0223bd28;
void ExtractPackedHiLo_0223bd28(Header_0223bd28* h, int index, unsigned int* outHi, unsigned int* outLo);

struct TableEntry_02236aec { unsigned short lo; unsigned short hi; };
extern TableEntry_02236aec data_ov031_0224926a[];

struct Mid_02236aec { void* items[5]; int f14; };
struct Base_02236aec { char pad[4]; Mid_02236aec* p; };
extern Base_02236aec data_ov031_02290d04;

extern "C" void func_ov031_0223bbd8(void*, int, int, int);
extern "C" void func_ov031_0223e2b8(void*, int);
extern "C" void func_ov031_02236bd0(void*);

// USA: func_ov031_02236aec
#pragma optimize_for_size off
extern "C" ARM void func_ov031_02236aec(void* obj) {
    int hi;
    unsigned int lo;
    ExtractPackedHiLo_0223bd28((Header_0223bd28*)data_ov031_02290d04.p->items[1], 0, (unsigned int*)&hi, &lo);
    hi += 8;
    if (hi < 0x50 || hi > 0x100) {
        int i = 1;
        do {
            TableEntry_02236aec* p = &data_ov031_0224926a[i];
            void* item = data_ov031_02290d04.p->items[i];
            unsigned short v = p->hi;
            func_ov031_0223bbd8(item, -1, hi, v);
            i++;
        } while (i < 5);
        return;
    }
    hi = 0x50;
    int i = 1;
    do {
        TableEntry_02236aec* p = &data_ov031_0224926a[i];
        void* item = data_ov031_02290d04.p->items[i];
        unsigned short v = p->hi;
        func_ov031_0223bbd8(item, -1, hi, v);
        i++;
    } while (i < 5);
    func_ov031_0223e2b8(obj, (int)func_ov031_02236bd0);
}
