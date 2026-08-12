#include <globaldefs.h>

struct Obj2081;
struct Elem2081;
Elem2081* FindElementByByte0xc4(Obj2081* obj, int key);

int CheckField0x9cSetWhenField0xd4Present(unsigned char* obj);

struct Outer020e28dc;
int GetInnerFlagBit0020e28dc(struct Outer020e28dc* o);

void GetLookAndTurnOffsets020809c4(void* obj, int id, int id2, short* out1, short* out2);

struct Ctx020e263c;
void UpdateEntryStateAndPosition(struct Ctx020e263c* obj, int value);

struct WinObj020e28f0;
void SetEntryPositionFromObject(struct WinObj020e28f0* obj, short a, short b);

extern "C" void func_0205ae8c(void* obj);

// USA: func_ov003_0215501c
extern "C" ARM void func_ov003_0215501c(unsigned char* self) {
    if (*(void**)(self + 8) == NULL) {
        return;
    }
    if (*(short*)(self + 0x1e6) < 0) {
        return;
    }
    Elem2081* elem = FindElementByByte0xc4(*(Obj2081**)(self + 0x18), *(short*)(self + 0x1e6));
    if (elem == NULL) {
        return;
    }
    if (CheckField0x9cSetWhenField0xd4Present((unsigned char*)elem) == 0 || *(void**)(self + 0x1c) == NULL) {
        return;
    }
    if (GetInnerFlagBit0020e28dc(*(Outer020e28dc**)(self + 0x1c)) != 0) {
        return;
    }
    short valA, valB;
    GetLookAndTurnOffsets020809c4(*(Obj2081**)(self + 0x18), *(short*)(self + 0x1e6), *(short*)*(void**)(self + 8), &valA, &valB);
    UpdateEntryStateAndPosition(*(Ctx020e263c**)(self + 0x1c), *(int*)(self + 0x1dc));
    valA = valA - 0x10;
    valB = valB - 3;
    SetEntryPositionFromObject(*(WinObj020e28f0**)(self + 0x1c), valA, valB);
    func_0205ae8c(self + 0x2c);
}
