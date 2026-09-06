#include <globaldefs.h>

extern "C" int func_ov003_021765b4(void* self);
extern "C" int func_ov003_021766e8(void* self);

int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);

struct Obj2081;
void CallFunc0204c804OnMatchingKey(struct Obj2081* obj, int key);

struct Obj0208203c;
void ResetWithSub0208203c(struct Obj0208203c* obj);

struct Obj020e25e8;
void ResetSelectionState020e25e8(struct Obj020e25e8* obj);

extern unsigned short data_02114e30;
extern struct Obj0205eaa0 data_02108760;

// USA: func_ov003_021764f4  (semantic: RunTurnCheck_021764f4)
extern "C" ARM int func_ov003_021764f4(unsigned char* self) {
    *(void**)(self + 0xff8) = self + 0x2 + 0x1000;
    int result = 0;
    if (func_ov003_021765b4(self) != 0) {
        goto dispatch;
    }
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x200) == 0) {
        goto alt;
    }
dispatch:
    DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
    result = -1;
    if (*(short*)(self + 0x1002) == 2) {
        result = 1;
    }
    goto merge;
alt:
    if (func_ov003_021766e8(self) != 0) {
        result = -1;
    }
merge:
    if (result != 0) {
        short key = *(short*)(self + 0xffe);
        CallFunc0204c804OnMatchingKey(*(struct Obj2081**)(self + 0x89c), key);
        ResetWithSub0208203c((struct Obj0208203c*)(self + 0x88c));
        *(void**)(self + 0xff8) = 0;
    }
    if (*(void**)self != 0 && result != 0) {
        ResetSelectionState020e25e8(*(struct Obj020e25e8**)self);
    }
    return result;
}
