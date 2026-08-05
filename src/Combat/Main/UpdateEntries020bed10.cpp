#include <globaldefs.h>

extern "C" void func_020bf1a0(void* entry);
extern "C" void _Z34RegisterActorInGlobalLists020bcb70P13Actor020bcb70(void* actor);
extern "C" void _Z26PostEventsForTypes020bcbe0P11Obj020bcbe0Pv(void* obj, int val);
extern "C" void _Z24AdvanceTweenStep020c0260P13Tween020c0260(void* tween);
extern "C" int _Z21EvaluateTween020c022cP13Tween020c0260(void* tween);
extern "C" int _Z19CheckField8GeFieldCP13State020c0278(void* state);

struct Entry020bed10 { unsigned char _pad[0x174]; };
extern struct Entry020bed10 data_02110a4c[];
extern short data_020ed82c[];

// USA: func_020bed10  (semantic: UpdateEntries020bed10)
extern "C" ARM void func_020bed10(void) {
    int index = 0;
    int a;
    unsigned char* entry = (unsigned char*)data_02110a4c;
LOOP_START:;
    {
        int flags = *(int*)(entry + 0x110);
        if (((flags << 31) >> 31) == 0) {
            goto LOOP_CONTINUE;
        }
        if (*(int*)(entry + 0x114) == 0) {
            func_020bf1a0(entry);
            goto LOOP_CONTINUE;
        }

        if (((flags << 29) >> 31) != 0 && *(int*)(entry + 0x118) != 0) {
            _Z34RegisterActorInGlobalLists020bcb70P13Actor020bcb70(entry);
            int f2 = *(int*)(entry + 0x110);
            f2 = (f2 | 2) & ~4;
            *(int*)(entry + 0x110) = f2;
        }

        int flags2 = *(int*)(entry + 0x110);
        if (((flags2 << 30) >> 31) == 0) {
            goto LOOP_CONTINUE;
        }
        _Z24AdvanceTweenStep020c0260P13Tween020c0260(entry + 0xe8);
        a = data_020ed82c[*(int*)(entry + 0x154)];
        int evalResult = _Z21EvaluateTween020c022cP13Tween020c0260(entry + 0xe8);
        int b = data_020ed82c[evalResult >> 8];
        int c = data_020ed82c[*(int*)(entry + 0x158)];
        int newVal = c + (b + a);
        if (newVal != *(int*)(entry + 0x15c)) {
            _Z26PostEventsForTypes020bcbe0P11Obj020bcbe0Pv(entry, newVal);
            *(int*)(entry + 0x15c) = newVal;
        }

        int flags3 = *(int*)(entry + 0x110);
        if (((flags3 << 28) >> 31) == 0) {
            goto LOOP_CONTINUE;
        }
        if (_Z19CheckField8GeFieldCP13State020c0278(entry + 0xe8) == 0) {
            goto LOOP_CONTINUE;
        }
        func_020bf1a0(entry);
    }
LOOP_CONTINUE:;
    index++;
    entry += 0x174;
    if (index < 4) {
        goto LOOP_START;
    }
}
