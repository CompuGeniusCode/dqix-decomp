#include <globaldefs.h>

struct Obj2081;
void ClearElementFlag0x20(struct Obj2081* obj, int key);
void SetEntryLowNibbleAndElement02080c68(void* obj, int id, int value);
void SetSublistEntriesFlag1(void* obj, int id);
void SetSublistEntriesFlag2(void* obj, int id);
void SetOrClearEntryFlag0x102081130(void* obj, int id, int flag);

struct Container020dedd0;
struct Element020de650;
struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
unsigned int ComputeRatio_02175898(char* obj, void* s);

void SetSublistEntryField28_0208077c(void* obj, int id, short value);
int SetEntryFlagById02080b40(void* obj, int id);

struct Arg1_0217818c;
extern "C" void func_ov003_0217818c(char* self, struct Arg1_0217818c* arg1, int id, int value);

void Forward0207f7acObjPlus4Size0x40(void* obj, int value);

struct Container02080f8c;
void SetEntryFirstField02080f8c(struct Container02080f8c* obj, int id, int value);
struct Container02080fa8;
void SetEntryFirstField02080fa8(struct Container02080fa8* obj, int id, int value);

void ClearSublistEntryFlag2_020806c4(void* obj, int id);
extern "C" int func_020813ec(void* obj, int id);

// USA: func_ov003_021767ec
extern "C" ARM int func_ov003_021767ec(char* self) {
    struct Obj2081* o = *(struct Obj2081**)(self + 0x89c);
    short id0 = 7;
    short id1 = 13;
    short id2 = 19;

    ClearElementFlag0x20(o, 3);
    SetEntryLowNibbleAndElement02080c68(o, 3, 0);
    SetSublistEntriesFlag1(o, 3);
    SetSublistEntriesFlag2(o, 3);

    unsigned short flags1046 = *(unsigned short*)(self + 0x1046);
    SetOrClearEntryFlag0x102081130(o, 3, (flags1046 & 0x400) != 0);

    short mult = *(short*)(self + 0x1014);
    unsigned char bound;
    unsigned char idx = mult * 6;
    bound = idx + 6;

    for (; idx < bound; ) {
        int local1 = 0;
        unsigned int local2 = 0;
        unsigned char limit = *(unsigned char*)(self + 0x835);
        if (idx < limit) {
            short key = *(short*)(self + 0x848 + idx * 2);
            struct Element020de650* elem = FindElementByKey020dedd0((struct Container020dedd0*)(self + 0x874), key);
            if (elem != NULL) {
                local1 = *(unsigned int*)((char*)elem + 4);
                local2 = ComputeRatio_02175898(self, elem);
                SetSublistEntryField28_0208077c(o, id0, 0xd);
                SetEntryFlagById02080b40(o, id0);
                SetEntryFlagById02080b40(o, id1);
                SetEntryFlagById02080b40(o, id2);
                func_ov003_0217818c(self, (struct Arg1_0217818c*)elem, id1, id2);
            }
            Forward0207f7acObjPlus4Size0x40(o, id0);
            SetEntryFirstField02080f8c((struct Container02080f8c*)o, id0, local1);
            SetEntryFirstField02080fa8((struct Container02080fa8*)o, id1, local2);
            ClearSublistEntryFlag2_020806c4(o, id0);
        }
        id0 = id0 + 1;
        id1 = id1 + 1;
        id2 = id2 + 1;
        idx = idx + 1;
    }

    SetEntryFlagById02080b40(o, 0x19);
    SetEntryFlagById02080b40(o, 0x1a);
    SetEntryFlagById02080b40(o, 0x1b);
    SetEntryFirstField02080fa8((struct Container02080fa8*)o, 0x19, *(short*)(self + 0x1014) + 1);
    SetEntryFirstField02080fa8((struct Container02080fa8*)o, 0x1a, *(short*)(self + 0x1016));
    return func_020813ec(o, 3);
}
