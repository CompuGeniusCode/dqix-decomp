#include <globaldefs.h>

struct Rec020467f0;
ARM void* FindRecordByIndex(struct Rec020467f0* rec, int index, void** out, int* out44);

struct ActiveEntry02046900;
ARM int CountActiveEntries(struct ActiveEntry02046900* entry);

struct List0204af64 {
    char pad0[0xc];
    unsigned char b0c;
    unsigned char pad0d;
    unsigned short h0e;
    int w10;
    int w14;
    int w18;
    unsigned char b1c_lo : 4;
    unsigned char b1c_hi : 4;
    unsigned char b1d;
    unsigned char b1e;
    unsigned char b1f;
};
ARM void ResetList0204af64(struct List0204af64* obj);

ARM void DispatchByTag0204b2e0(void* obj, char* str);

struct SelfTag0204b3a0 {
    unsigned char pad[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
};
ARM void DispatchByTagLookup0204b3a0(struct SelfTag0204b3a0* self, char* str);

struct CtxObj_021f7b98 {
    char pad[0x44];
    unsigned char lo : 4;
    unsigned char hi : 4;
};

// USA: func_ov023_021f7b98
extern "C" ARM void func_ov023_021f7b98(struct CtxObj_021f7b98* ctx, void* unused1, int mode,
                                         struct Rec020467f0* rec, int enable) {
    if (rec && enable) {
        int count = CountActiveEntries((struct ActiveEntry02046900*)rec);
        int out44;
        void* found_out;
        int j;
        for (j = 0; j < count; j++) {
            void* found = FindRecordByIndex(rec, j, &found_out, &out44);
            if (found) {
                struct List0204af64 list;
                ResetList0204af64(&list);
                list.b1c_lo = ctx->lo;
                list.b1c_hi = ctx->hi;
                if (mode) {
                    DispatchByTag0204b2e0(&list, (char*)found);
                } else {
                    DispatchByTagLookup0204b3a0((struct SelfTag0204b3a0*)&list, (char*)found);
                }
            }
        }
    }
}
