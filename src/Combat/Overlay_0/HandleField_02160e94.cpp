#include <globaldefs.h>

extern int data_ov000_02184220;
int GetData02104304Field4();
extern "C" int func_0202fdd0(int a, int b);
extern "C" void func_020301c8(int a, int b);

// USA: func_ov000_02160e94
ARM void HandleField_02160e94(void* obj) {
    int dataVal = GetData02104304Field4();
    if (func_0202fdd0(dataVal, *(short*)((char*)obj + 0x7700 + 0x30)) >= 0) {
        return;
    }
    func_020301c8(dataVal, *(short*)((char*)obj + 0x7700 + 0x30));
    *(short*)((char*)obj + 0x7700 + 0x30) = -1;
    *(int*)((char*)obj + 0xea8) = 0x8;
    *(int*)((char*)obj + 0xeac) = 0;
    data_ov000_02184220 = 1;
}
