#include <globaldefs.h>

struct List0207f6ac;
struct List0207f0ac;
struct TableA68;

extern void* FindEntryByShortId0207f6ac(struct List0207f6ac* list, int id);
struct Entry0207f0ac020806d8;
extern struct Entry0207f0ac020806d8* FindEntryByShortId0207f0ac(struct List0207f0ac* list, int id);
extern void* FindEntryByKey(struct TableA68* table, int key);
extern int IsValueEqual12(int x);
extern "C" int func_020420e8(void* value, int flag);

struct Entry020806d8 {
    char pad0[6];
    short field6;
    char pad8[0xe - 8];
    short fieldE;
    char pad10[0x12 - 0x10];
    unsigned char field12;
    unsigned char field13nibble : 4;
    unsigned char field13rest : 4;
};

struct Entry0207f0ac020806d8 {
    char pad[0xe];
    short fieldE;
};

struct ObjSublist020806d8 {
    struct TableA68* field0;
};

// USA: func_020806d8  (semantic: UpdateSublistEntryField6020806d8)
extern "C" ARM void func_020806d8(struct ObjSublist020806d8* obj, int p1, int p2, int p3, short p5) {
    struct Entry020806d8* e = (struct Entry020806d8*)FindEntryByShortId0207f6ac((struct List0207f6ac*)((char*)obj + 4), p2);
    if (e == NULL) {
        return;
    }
    if (p3 == 0) {
        e->field6 = p5;
        return;
    }
    if (e->field12 != 0) {
        return;
    }
    void* found = FindEntryByKey(obj->field0, e->fieldE);
    if (found == NULL) {
        return;
    }
    int isTwelve = IsValueEqual12(e->field13nibble);
    int adj = func_020420e8(found, isTwelve);
    struct Entry0207f0ac020806d8* fe = FindEntryByShortId0207f0ac((struct List0207f0ac*)((char*)obj + 0xc), p1);
    if (fe == NULL) {
        return;
    }
    short scaled = fe->fieldE << 3;
    e->field6 = scaled - adj - p5;
}
