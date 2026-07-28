#include <globaldefs.h>

struct Obj_0205da38;
extern int IsActiveElementFlag2Set0205da38(struct Obj_0205da38*);
typedef int (*Fn2_0215b328)(void*, int);
extern unsigned short data_02114e30;
int TestFlag0SetAndFlag1Clear(unsigned short*, int);

// USA: func_ov003_0215b328  (semantic: CheckActiveOrFlags_0215b328)
extern "C" ARM int func_ov003_0215b328(char* obj) {
    int a = ((Fn2_0215b328)(void*)&IsActiveElementFlag2Set0205da38)(obj + 0xf4, 0x14);
    int b = TestFlag0SetAndFlag1Clear(&data_02114e30, 1);
    int c = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x400);
    return (a | (b | c)) != 0;
}
