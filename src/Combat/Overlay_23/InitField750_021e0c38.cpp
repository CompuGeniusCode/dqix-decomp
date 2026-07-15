#include <globaldefs.h>

int GetData02104304Field4();

struct Struct020dfc40;
void ResetAndDetach020dfc6c(struct Struct020dfc40*);

int CallFunc0202fa38Mode2(int a, int b, int c, int d);

extern int data_020f2a1c;
extern int data_020f2a20;

// USA: func_ov023_021e0c38
ARM int InitField750_021e0c38(void* obj) {
    int listPtr = GetData02104304Field4();
    ResetAndDetach020dfc6c((struct Struct020dfc40*)((char*)obj + 0xa4));
    *(int*)((char*)obj + 0x750) = CallFunc0202fa38Mode2(listPtr, data_020f2a1c, data_020f2a20, 0);
    return 0x3;
}
