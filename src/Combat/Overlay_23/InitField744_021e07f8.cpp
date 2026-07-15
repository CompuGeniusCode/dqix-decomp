#include <globaldefs.h>

int GetData02104304Field4();
void ClearStruct16(void* p);
int CallFunc0202fa38Mode2(int a, int b, int c, int d);

extern int data_020f2a1c;
extern int data_020f2b68;

// USA: func_ov023_021e07f8
ARM int InitField744_021e07f8(void* obj) {
    int listPtr = GetData02104304Field4();
    ClearStruct16((char*)obj + 0x6c);
    *(int*)((char*)obj + 0x744) = CallFunc0202fa38Mode2(listPtr, data_020f2a1c, data_020f2b68, 0);
    return 0xa;
}
