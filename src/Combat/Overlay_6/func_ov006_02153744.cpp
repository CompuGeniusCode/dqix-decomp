#include <globaldefs.h>

struct List02071d60;
struct Elem02071d60;
Elem02071d60* FindEntryByKey02071d60(List02071d60* list, int key);

struct ArrEntry02153744 {
    short key;
    unsigned short bit0 : 1;
    unsigned short bit1 : 1;
    unsigned short : 14;
};

struct EntryView02153744 {
    char pad[0x10];
    unsigned int lowbits : 22;
    unsigned int flagBit : 1;
    unsigned int highbits : 9;
};

// USA: func_ov006_02153744
extern "C" ARM void func_ov006_02153744(void* unused, List02071d60* list, ArrEntry02153744* arr, int count) {
    int i;
    for (i = 0; i < count; i++, arr++) {
        Elem02071d60* e = FindEntryByKey02071d60(list, arr->key);
        if (e == 0) continue;
        EntryView02153744* entry = (EntryView02153744*)e;
        entry->flagBit = arr->bit0 || arr->bit1;
    }
}
