#include <globaldefs.h>
#include "System/Memory.h"

void PushInterruptDisableState(void);
int GetGlobalField0x10(void);
int CheckDispatchAndUpdateField0x48(int arg);
int TestDefaultFlagBits(int arg);
extern "C" void func_020d8694(void);

// USA: func_0202bf40  (semantic: ResetBattleRecordFlags_0202bf40)
extern "C" ARM void func_0202bf40(void* obj) {
    PushInterruptDisableState();
    if (GetGlobalField0x10() == 5) {
        if (CheckDispatchAndUpdateField0x48((int)((char*)obj + 0x7c0))) {
            char* recs = (char*)obj + 0xbc0;
            for (unsigned short i = 0; i < 4; i++) {
                int r = TestDefaultFlagBits(i);
                int off = i * 0x74;
                if (r != 0) {
                    VectorizedInvertedMemcpy((void*)r, recs + off, 0x74);
                    *(int*)((char*)obj + i * 4 + 0xfc4) = 1;
                } else {
                    *(unsigned short*)(recs + off) &= ~0x18;
                    *(int*)((char*)obj + i * 4 + 0xfc4) = 0;
                }
            }
            *(int*)((char*)obj + 0xfc0) = 0;
        } else {
            for (unsigned short i = 0; i < 4; i++) *(int*)((char*)obj + i * 4 + 0xfc4) = 0;
            *(int*)((char*)obj + 0xfc0) = 1;
        }
    } else {
        for (unsigned short i = 0; i < 4; i++) *(int*)((char*)obj + i * 4 + 0xfc4) = 0;
        *(int*)((char*)obj + 0xfc0) = 0;
    }
    func_020d8694();
}
