#include <globaldefs.h>

struct Shorts5c_374e0 { char unk0[0x5c]; short a; short b; short c; };
extern "C" void _ZN8Object3D8SetScaleEiii(Shorts5c_374e0* obj, short a, short b, short c);
typedef void (*SetShorts0x5cTo0x60WideFn_02164754)(Shorts5c_374e0*, short, short, int);

struct Entry_02164754 { int type; char pad[8]; void* field_c; };

// USA: func_ov001_02164754  (semantic: DispatchEntrySetShorts_02164754)
extern "C" ARM int func_ov001_02164754(Entry_02164754* table, int index, short arg2, short arg3, int arg4) {
    Entry_02164754* entry;
    void* member;
    if (index < 0 || index >= 0x20) return 0;
    entry = &table[index];
    switch (entry->type) {
        case 0:
        case 1:
        case 4:
        case 5:
            member = entry->field_c;
            if (member == 0) return 0;
            ((SetShorts0x5cTo0x60WideFn_02164754)_ZN8Object3D8SetScaleEiii)((Shorts5c_374e0*)member, arg2, arg3, arg4);
            return 1;
        case 6:
            member = entry->field_c;
            if (member == 0) return 0;
            member = *(void**)((char*)member + 0x18);
            if (member == 0) return 0;
            ((SetShorts0x5cTo0x60WideFn_02164754)_ZN8Object3D8SetScaleEiii)((Shorts5c_374e0*)member, arg2, arg3, arg4);
            return 1;
        default:
            return 0;
    }
}
