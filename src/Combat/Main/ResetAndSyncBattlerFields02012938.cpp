#include <globaldefs.h>

void StoreValueWithInterruptsDisabled020cdac4(int value);
void ResetBattlerState0201289c(unsigned char* obj);
extern "C" void func_020cdae4(int a, int b, int c, int d);
void WaitWhileFlagsSet(int mask);
int GetMaskedStatus(int mask);
void ClearByte0x62IfArg0x10(int arg);

// USA: func_02012938  (semantic: ResetAndSyncBattlerFields02012938)
extern "C" ARM void func_02012938(unsigned char* obj) {
    StoreValueWithInterruptsDisabled020cdac4((int)ClearByte0x62IfArg0x10);
    obj[0x62] = 1;
    ResetBattlerState0201289c(obj);
    func_020cdae4(0, 1, (int)obj, 4);
    WaitWhileFlagsSet(2);
    GetMaskedStatus(2);
    obj[0x60] = 0;
    obj[0x5f] = obj[0x63];
    *(int*)(obj + 0x40) = *(int*)(obj + 0x64);
    int t1 = *(int*)(obj + 0x68);
    if (t1 >= 0) *(int*)(obj + 0x30) = t1;
    int t2 = *(int*)(obj + 0x6c);
    if (t2 >= 0) *(int*)(obj + 0x34) = t2;
}
