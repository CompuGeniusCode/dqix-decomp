#include <globaldefs.h>

extern "C" void* func_02012fe4(void);
extern "C" void func_02018300(void* a, void* b, int c, int d, int e);
void* FindNthType2Entry02018c20(unsigned char* obj, int n);
struct Entry_02028bd0;
struct Entry_02028bd0* GetEntryTableBase(void);
struct Entry_02028bd0* FindInlineEntryById(struct Entry_02028bd0* base, int key);

struct Obj02028c64;
void SetFlagBit02028c64(struct Obj02028c64* obj, int index);

struct Rec021d19b0 {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned short field6;
    unsigned int field8;
};

// USA: func_ov017_021d19b0
ARM void HandleType2OrEntry_021d19b0(int unused, struct Rec021d19b0* rec) {
    unsigned short* p = (unsigned short*)func_02012fe4();
    if (rec->field4 == *p) {
        void* e = FindNthType2Entry02018c20((unsigned char*)p, rec->field6);
        if (e == NULL)
            return;
        func_02018300(p, e, rec->field8, 0, 0);
    } else {
        struct Entry_02028bd0* table = GetEntryTableBase();
        struct Entry_02028bd0* entry = FindInlineEntryById(table, rec->field4);
        if (entry == NULL)
            return;
        SetFlagBit02028c64((struct Obj02028c64*)entry, rec->field6);
    }
}
