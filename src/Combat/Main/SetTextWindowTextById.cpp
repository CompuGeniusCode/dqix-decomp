#include <globaldefs.h>

struct Elem0205d5d0 {
    char pad[0xc4];
    unsigned char fieldC4;
};

struct StructA0205d5d0 {
    char pad0[0x98];
    int field98;
    Elem0205d5d0* field9c;
    char pad2[0x13];
    unsigned char countB3;
};

extern "C" int IsWindowElementActive(unsigned char* obj);
extern "C" void func_0205d904(unsigned char* obj);
extern "C" void func_0204cb20(void* elem, int c, int d, unsigned char e);

// Writes text into the text window with the given id, over the same 0xe0-stride array and +0xc4 id
// byte FindTextWindowById walks, skipping elements IsWindowElementActive rejects; the return is 0
// only when one was found. The scan differs: FindTextWindowById stops at the count in +0xb4, this
// runs the full +0xb3 count, so a window past +0xb4 can be written here yet not be findable.
// Callers pass a buffer they have just formatted; the undecompiled worker at 0x0204cb20 relocates
// to GetMessageWork, FormatMessageText and the markup parser at 0x0204e3e0.
extern "C" ARM int SetTextWindowTextById(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e) {
    Elem0205d5d0* elem;
    unsigned char i;

    if (c == 0) return 1;
    if (a->field98 == 0) return 1;
    if (a->field9c == 0) return 1;

    for (i = 0; i < a->countB3; i++) {
        elem = (Elem0205d5d0*)((char*)a->field9c + i * 0xe0);
        if (!IsWindowElementActive((unsigned char*)elem)) continue;
        if (b != elem->fieldC4) continue;
        func_0204cb20(elem, c, d, e);
        func_0205d904((unsigned char*)a);
        return 0;
    }
    return 1;
}
