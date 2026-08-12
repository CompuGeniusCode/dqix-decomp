#include <globaldefs.h>

extern "C" void func_ov003_02169594(void* obj);
extern "C" int func_ov003_0216950c(void* obj);
extern "C" void func_ov003_0216a974(void* obj, int mode, int flag);
extern "C" void func_ov003_0216aa28(void* obj);

void SetChannelAFlag0205cef8(void* obj);
void SetChannelBFlag0205cf04(void* obj);
void ClearChannelAFlag0205cf10(void* obj);

struct Struct0205cf1c;
void ClearFlagByte0205cf1c(struct Struct0205cf1c* s);

struct Struct_0205c570;
int GetActiveScaledSum0205d794(struct Struct_0205c570* s);

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);

int CheckFlagOrThreshold_02169554(void* obj);

extern int data_02108760;

// USA: func_ov003_02169b30  (semantic: StepStateMachine02169b30)
extern "C" ARM int func_ov003_02169b30(void* p) {
    char* obj = (char*)p;
    unsigned char state = *(unsigned char*)(obj + 0x4e9);
    if (state == 0) {
        func_ov003_02169594(obj);
        SetChannelAFlag0205cef8(obj + 0xe4);
        SetChannelBFlag0205cf04(obj + 0xe4);
        *(unsigned char*)(obj + 0x4e9) = *(unsigned char*)(obj + 0x4e9) + 1;
    } else if (state == 1) {
        *(unsigned char*)(obj + 0x59f) |= 1;
        int e = GetActiveScaledSum0205d794((struct Struct_0205c570*)(obj + 0xe4));
        *(unsigned char*)(obj + 0x4ed) = (unsigned char)e;
        if (func_ov003_0216950c(obj) != 0) {
            func_ov003_0216a974(obj, 1, 1);
            *(unsigned char*)(obj + 0x59f) &= ~1;
            func_ov003_0216aa28(obj);
            *(unsigned char*)(obj + 0x4ea) = 0;
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);
            ClearChannelAFlag0205cf10(obj + 0xe4);
            ClearFlagByte0205cf1c((struct Struct0205cf1c*)(obj + 0xe4));
            *(unsigned char*)(obj + 0x4e9) = 0;
            return *(signed char*)(obj + 0x4ed);
        } else {
            if (CheckFlagOrThreshold_02169554(obj) != 0) {
                *(unsigned char*)(obj + 0x59f) &= ~1;
                ClearChannelAFlag0205cf10(obj + 0xe4);
                ClearFlagByte0205cf1c((struct Struct0205cf1c*)(obj + 0xe4));
                *(unsigned char*)(obj + 0x4e9) = 0;
                return -2;
            }
        }
    }
    return -1;
}
