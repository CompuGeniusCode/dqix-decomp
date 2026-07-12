#include <globaldefs.h>

extern void* data_020fb3cc;

void ResetBattlerState0201289c(unsigned char* obj);

extern "C" {
    void func_020cd890(void);
    int func_020cd908(void* p);
    void func_020c9be0(void);
    void func_020cd99c(void* p);
    void func_02012938(void* p);
}

// USA: func_0201282c
ARM void InitBattlerContext0201282c(unsigned char* obj) {
    data_020fb3cc = obj;
    ResetBattlerState0201289c(obj);
    obj[0x61] = 1;
    func_020cd890();
    if (!func_020cd908(obj + 0x28)) {
        func_020c9be0();
    }
    func_020cd99c(obj + 0x28);
    func_02012938(obj);
    obj[0x60] = 0;
    *(int*)(obj + 0x64) = 0;
    *(int*)(obj + 0x68) = -1;
    *(int*)(obj + 0x6c) = -1;
    obj[0x62] = 0;
    *(int*)(obj + 0x30) = -1;
    *(int*)(obj + 0x34) = -1;
}
