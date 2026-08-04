#include <globaldefs.h>

struct List_020347b4;

struct EntryData_020370a0 {
    char pad[0x10];
    int f10;
    int f14;
};

EntryData_020370a0* GetEntryFromList020347b4(List_020347b4* list, int index);

struct Obj020370a0 {
    char pad0[0x8];
    int field8;
    void* fieldC;
    void* field10;
    EntryData_020370a0* field14;
    unsigned char field18;
    unsigned char field19;
    char pad1[0x1c - 0x1a];
    int field1c;
    int field20;
    int field24;
    int field28;
    char pad2[0x40 - 0x2c];
    unsigned char field40;
    char pad3[0x6c - 0x41];
    unsigned int field6c;
};

// USA: func_020370a0  (semantic: InitEntryFromList_020370a0)
extern "C" ARM int func_020370a0(Obj020370a0* obj, int id, int flags) {
    if (!obj->fieldC) return 0;
    if (!obj->field8) return 0;
    EntryData_020370a0* entry = GetEntryFromList020347b4((List_020347b4*)((char*)obj->fieldC + 4), id);
    if (!entry) return 0;
    int v;
    if (flags & 4) v = entry->f14;
    else v = entry->f10;
    obj->field18 = (unsigned char)id;
    obj->field1c = v;
    obj->field20 = v;
    obj->field19 = (unsigned char)flags;
    obj->field24 = obj->field28 = 0;
    obj->field40 |= 2;
    obj->field14 = entry;
    obj->field10 = obj->fieldC;
    obj->field6c &= ~0x40000u;
    return 1;
}
