#include <globaldefs.h>

int GetData02104304Field4();
void ClearStruct16(void* p);
int CallFunc0202fa38Mode2(int a, int b, int c, int d);

extern int data_020f2a1c;
extern int data_020f2a28;

// USA: func_ov023_021e0b54
ARM int InitField74c_021e0b54(void* obj) {
    int listPtr = GetData02104304Field4();
    ClearStruct16((char*)obj + 0x7c);
    *(int*)((char*)obj + 0x74c) = CallFunc0202fa38Mode2(listPtr, data_020f2a1c, data_020f2a28, 0);
    return 0xe;
}
