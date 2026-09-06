#include <globaldefs.h>

struct List0207f0ac;
struct Entry0207f0ac;
Entry0207f0ac* FindEntryByShortId0207f0ac(List0207f0ac* list, int id);

struct List0207f6ac;
struct Entry0207f6ac;
Entry0207f6ac* FindEntryByShortId0207f6ac(List0207f6ac* list, int id);

struct Group02080468 {
    short* memberIds;
    char pad[0x13 - 4];
    unsigned char count;
};

struct CombatEntry02080468 {
    char pad0[4];
    short f4;
    char pad1[0x18 - 6];
    int f18;
    int f1c;
    int f20;
    int f24;
    char pad2[0x2a - 0x28];
    unsigned char flag2a;
};

// USA: func_02080468
ARM short FindMappedMemberId02080468(void* obj, int id) {
    short result = -1;
    Group02080468* group = (Group02080468*)FindEntryByShortId0207f0ac((List0207f0ac*)((char*)obj + 0xc), id);
    if (group != NULL) {
        unsigned char i;
        for (i = 0; i < group->count; i++) {
            result = group->memberIds[i];
            CombatEntry02080468* e = (CombatEntry02080468*)FindEntryByShortId0207f6ac((List0207f6ac*)((char*)obj + 4), result);
            if (e == NULL) continue;
            if (e->flag2a & 2) continue;
            if (e->f18 == 0 && e->f1c == 0 && e->f20 == 0 && e->f24 == 0) continue;
            result = e->f4;
            break;
        }
    }
    return result;
}
