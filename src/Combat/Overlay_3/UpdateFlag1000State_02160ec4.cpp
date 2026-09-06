#include <globaldefs.h>

int GetGlobal02109400(void);
extern "C" void _Z21BlankFunction02094b34v(int, int, int, int, int);
int AlwaysTrue02094b4c(void);

// USA: func_ov003_02160ec4  (semantic: UpdateFlag1000State_02160ec4)
extern "C" ARM void func_ov003_02160ec4(void* p) {
    char* obj = (char*)p;
    if (!(*(int*)(obj + 0x464) & 0x1000)) return;
    unsigned char state = *(unsigned char*)(obj + 0x4a7);
    if (state == 0) {
        int g = GetGlobal02109400();
        _Z21BlankFunction02094b34v(g, 0x1f5, 0x66, 0, 0);
        *(unsigned char*)(obj + 0x4a7) = *(unsigned char*)(obj + 0x4a7) + 1;
    } else if (state == 1) {
        GetGlobal02109400();
        if (AlwaysTrue02094b4c() != 0) {
            *(int*)(obj + 0x464) &= ~0x1000;
            *(unsigned char*)(obj + 0x4a7) = *(unsigned char*)(obj + 0x4a7) + 1;
        }
    }
}
