#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
extern "C" void func_ov023_021dcae0(void* obj, int val);
void ResetIfNonNeg_021db2e4(volatile int* p);
struct DispatchEntry_021fdaa8 { int handler; int offsetFlag; };
extern DispatchEntry_021fdaa8 data_ov023_021fdaa8[];

// USA: func_ov023_021dfb4c  (semantic: RunSubStateDispatch_021dfb4c)
extern "C" ARM void func_ov023_021dfb4c(void* obj) {
    short field772 = *(short*)((char*)obj + 0x772);
    short field770 = *(short*)((char*)obj + 0x770);
    if (field770 != field772) {
        func_ov023_021dcae0(obj, field772);
    }

    if ((*(unsigned short*)((char*)obj + 0x774) & 1) == 0) {
        return;
    }

    if (*(signed char*)((char*)obj + 0x77b) == 1) {
        struct Flags79b_021dfb4c { unsigned char bit0 : 1; unsigned char bit1 : 1; unsigned char rest : 6; };
        if (((Flags79b_021dfb4c*)((char*)obj + 0x79b))->bit1 == 0) {
            ResetIfNonNeg_021db2e4((volatile int*)((char*)obj + 0x734));
            for (int i = 0; i < 7; i++) {
                ResetIfNonNeg_021db2e4((volatile int*)((char*)obj + 0x738 + i * 4));
            }
            *(unsigned short*)((char*)obj + 0x774) |= 1;
            *(int*)((char*)obj + 0x754) = 0;
            return;
        }
    }

    (int)BackgroundLoader::GetInstance();
    DispatchEntry_021fdaa8* table = data_ov023_021fdaa8;

    while (*(int*)((char*)obj + 0x754) >= 0 &&
           table[*(int*)((char*)obj + 0x754)].handler != 0) {
        int idx = *(int*)((char*)obj + 0x754);
        DispatchEntry_021fdaa8* entry = &table[idx];
        int offsetFlag = entry->offsetFlag;
        int oldIdx = *(int*)((char*)obj + 0x754);

        char* arg = (char*)obj + (offsetFlag >> 1);
        int (*fn)(void*);
        if (offsetFlag & 1) {
            void* vtab = *(void**)arg;
            fn = *(int(**)(void*))((char*)vtab + entry->handler);
        } else {
            fn = (int(*)(void*))entry->handler;
        }

        int result = fn(arg);
        *(int*)((char*)obj + 0x754) = result;
        if (result < 0) {
            *(unsigned short*)((char*)obj + 0x774) &= ~1;
            ResetIfNonNeg_021db2e4((volatile int*)((char*)obj + 0x734));
            for (int i = 0; i < 7; i++) {
                ResetIfNonNeg_021db2e4((volatile int*)((char*)obj + 0x738 + i * 4));
            }
            return;
        }
        if (oldIdx == result) {
            return;
        }
    }
}
