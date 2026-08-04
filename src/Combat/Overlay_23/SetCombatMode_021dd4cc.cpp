#include <globaldefs.h>

int GetData02104304Field4(void);
extern "C" void func_020301c8(int a, int b);
int CallFunc0202fa38Mode2(int a, int b, int c, int d);

extern int data_ov023_021fdb40;
extern int data_ov023_021fdb52;
extern int data_ov023_021fdb60;
extern int data_ov023_021fdb72;

// USA: func_ov023_021dd4cc  (semantic: SetCombatMode_021dd4cc)
extern "C" ARM void func_ov023_021dd4cc(void* objRaw, int mode) {
    char* obj = (char*)objRaw;
    int dataResult = GetData02104304Field4();
    signed char scratchVal = *(signed char*)(obj + 0x77d);
    if (mode == scratchVal) {
        if (*(int*)(obj + 0x780) < 0) return;
        func_020301c8(dataResult, *(int*)(obj + 0x780));
        *(int*)(obj + 0x780) = -1;
        obj[0x77e] = *(signed char*)(obj + 0x700 + 0x7d);
        return;
    }
    signed char other = *(signed char*)(obj + 0x77e);
    if (mode == other) return;
    if (*(int*)(obj + 0x780) >= 0) {
        func_020301c8(dataResult, *(int*)(obj + 0x780));
        *(int*)(obj + 0x780) = -1;
        obj[0x77e] = -1;
    }
    int result;
    if (mode == 2) {
        result = CallFunc0202fa38Mode2(dataResult, (int)&data_ov023_021fdb40, (int)&data_ov023_021fdb52, 0);
    } else {
        result = CallFunc0202fa38Mode2(dataResult, (int)&data_ov023_021fdb60, (int)&data_ov023_021fdb72, 0);
    }
    *(int*)(obj + 0x780) = result;
    *(unsigned short*)(obj + 0x774) |= 8;
    obj[0x77e] = (char)mode;
}
