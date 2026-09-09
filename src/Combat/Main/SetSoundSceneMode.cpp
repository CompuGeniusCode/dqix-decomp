#include <globaldefs.h>

extern int strDataSoundSeNormSdat;
extern int strDataSoundSeBtlSdat;
extern int data_ov031_02257180;

extern "C" void OpenFileStreamInRegion(void* obj, int addr, void* ovAddr, int size, int flag);

extern "C" int func_0203aa64(void* obj);
extern "C" int func_0203aa98(void* obj, int index);

// USA: func_0205ea20
// The file paths in this function's literal pool are "data/sound/se_norm.sdat" and
// "data/sound/se_btl.sdat".
extern "C" ARM void SetSoundSceneMode(void* objRaw, int mode) {
    char* obj = (char*)objRaw;
    int addr = 0;
    if (mode == 0x64) {
        addr = (int)&strDataSoundSeNormSdat;
    } else if (mode == 0x65) {
        addr = (int)&strDataSoundSeBtlSdat;
    }
    if (addr != 0) {
        OpenFileStreamInRegion(obj, addr, &data_ov031_02257180, 0x4b000, 0);
    }
    *(int*)(obj + 0xb0) = func_0203aa64(obj);
    *(short*)(obj + 0xb4) = (short)mode;
    func_0203aa98(obj, mode);
    int r = func_0203aa64(obj);
    *(int*)(obj + 0xc0) = r;
    *(int*)(obj + 0xb8) = r;
}
