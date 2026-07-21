#include <globaldefs.h>

struct Header_0223bd28;
void ExtractPackedHiLo_0223bd28(Header_0223bd28* h, int index, unsigned int* outHi, unsigned int* outLo);

struct TableEntry_02236a08 { unsigned short lo; unsigned short hi; };
extern TableEntry_02236a08 data_ov031_0224926a[];

struct Mid_02236a08 { void* items[5]; int f14; };
struct Base_02236a08 { char pad[4]; Mid_02236a08* p; };
extern Base_02236a08 data_ov031_02290d04;

extern "C" void func_ov031_0223bbd8(void*, int, int, int);
extern "C" void func_ov031_0223e2b8(void*, int);
extern "C" void func_ov031_02236aec(void*);

// USA: func_ov031_02236a08
#pragma optimize_for_size off
extern "C" ARM void func_ov031_02236a08(void* obj) {
    int hi;
    unsigned int lo;
    ExtractPackedHiLo_0223bd28((Header_0223bd28*)data_ov031_02290d04.p->items[0], 0, (unsigned int*)&hi, &lo);
    hi += 8;
    if (hi < 0x20 || hi > 0x100) {
        int i = 0;
        do {
            TableEntry_02236a08* p = &data_ov031_0224926a[i];
            void* item = data_ov031_02290d04.p->items[i];
            unsigned short v = p->hi;
            func_ov031_0223bbd8(item, -1, hi, v);
            i++;
        } while (i < 5);
        return;
    }
    hi = 0x20;
    int i = 0;
    do {
        TableEntry_02236a08* p = &data_ov031_0224926a[i];
        void* item = data_ov031_02290d04.p->items[i];
        unsigned short v = p->hi;
        func_ov031_0223bbd8(item, -1, hi, v);
        i++;
    } while (i < 5);
    func_ov031_0223e2b8(obj, (int)func_ov031_02236aec);
}
