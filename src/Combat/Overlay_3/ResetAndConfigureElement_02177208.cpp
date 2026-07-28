#include <globaldefs.h>

struct Obj2081;
void ClearElementFlag0x20(struct Obj2081* obj, int key);
void SetEntryLowNibbleAndElement02080c68(void* obj, int id, int value);
struct Container02080fa8;
void SetEntryFirstField02080fa8(struct Container02080fa8* obj, int id, int value);
int SetEntryFlagById02080b2c(void* obj, int id);
extern "C" void func_020813ec(void* obj, int key);

// USA: func_ov003_02177208  (semantic: ResetAndConfigureElement_02177208)
extern "C" ARM void func_ov003_02177208(char* obj) {
    struct Obj2081* elemObj = *(struct Obj2081**)(obj + 0x89c);
    ClearElementFlag0x20(elemObj, 9);
    SetEntryLowNibbleAndElement02080c68(elemObj, 9, 0);
    SetEntryFirstField02080fa8((struct Container02080fa8*)elemObj, 0x57, *(unsigned char*)(obj + 0x1000 + 0x3c));
    SetEntryFlagById02080b2c(elemObj, 0x58);
    SetEntryFlagById02080b2c(elemObj, 0x59);
    func_020813ec(elemObj, 9);
}
