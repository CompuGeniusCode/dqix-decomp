#include <globaldefs.h>

extern "C" void func_020ca408(void* dst, void* src, int size);
extern void* data_02110370;

struct TableEntry020bd368 {
    int rawOffset;    // +0x0
    char pad4[4];
    void* resolved;   // +0x8
    char padc[4];
};

struct Container020bd368 {
    char pad0[8];
    unsigned int count;        // +0x8
    struct TableEntry020bd368 entries[1]; // +0xc
};

struct Obj020bd368 {
    char pad0[0x10];
    int f10;               // +0x10
    char pad14[4];
    int f18;                // +0x18
    char pad1c[4];
    int f20;                 // +0x20
    char pad24[0xc];
    int f30;                  // +0x30
    char pad34[0x50];
    struct Container020bd368* f84; // +0x84
    void* f88;                      // +0x88
    void* f8c;                       // +0x8c
    int f90;                          // +0x90
};

// USA: func_020bd368  (semantic: InitPointerTableFromBase_020bd368)
extern "C" ARM void func_020bd368(struct Obj020bd368* obj, char* base) {
    func_020ca408(base, obj, 0x30);
    obj->f8c = obj->f18 == 0 ? 0 : base + obj->f18;
    obj->f84 = (struct Container020bd368*)(obj->f20 == 0 ? 0 : base + obj->f20);
    obj->f88 = obj->f10 == 0 ? 0 : base + obj->f10;
    obj->f90 = 0;
    unsigned int i = 0;
    if (i < obj->f84->count) {
        int off = 0;
        do {
            struct TableEntry020bd368* entry = (struct TableEntry020bd368*)((char*)obj->f84 + 0xc + off);
            int raw = entry->rawOffset;
            entry->resolved = raw == 0 ? 0 : base + raw;
            off += 0x10;
            i++;
        } while (i < obj->f84->count);
    }
    obj->f30 = 0;
    data_02110370 = obj;
}
