#include <globaldefs.h>

struct Obj0205eaa0;
extern "C" void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern "C" int func_ov017_0218b5b0(void);
extern "C" void InitObjState_021b2174(unsigned char* obj);
struct S021b2ba0;
extern "C" void SetNameChecked_021b2ba0(S021b2ba0* obj, char* src);
extern "C" void SetFields30And34_021b2bd0(void* obj, int a, int b);
extern "C" void AllocateAndCopyStruct60_021633ac(void* a, void* obj);

struct Node02046a3c;
struct List02046a3c;
extern "C" void InsertNodeAfterHead(struct List02046a3c* list, struct Node02046a3c* node);

extern struct Obj0205eaa0 data_02108760;
extern char data_020f233d;

// USA: func_020d79e0
ARM void InitAndRegisterNode020d79e0(void* unused, char* name) {
    char* base = (char*)func_ov017_0218b5b0() + 0x3000;
    struct List02046a3c* list = *(struct List02046a3c**)(base + 0x6fc);
    unsigned char* obj = *(unsigned char**)(base + 0xb4c);
    DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
    InitObjState_021b2174(obj);
    *(char**)(obj + 0x4c) = name;
    SetNameChecked_021b2ba0((S021b2ba0*)obj, &data_020f233d);
    SetFields30And34_021b2bd0(obj, (int)&AllocateAndCopyStruct60_021633ac, 4);
    InsertNodeAfterHead(list, (struct Node02046a3c*)obj);
}
