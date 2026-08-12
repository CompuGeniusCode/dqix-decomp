#include <globaldefs.h>

int GetGlobalField0x1c020421a0();
extern "C" void func_ov003_0216d8d4(char* obj, int keyA, int p3, int p4, int p5);
void ReinitController02043204(char* obj);

// USA: func_ov003_0216d3f0  (semantic: AdvanceBattleStateAndReinit_0216d3f0)
extern "C" ARM void func_ov003_0216d3f0(char* obj) {
    char* g = (char*)GetGlobalField0x1c020421a0();
    short state = *(short*)(obj + 6);
    if (state == 0) {
        func_ov003_0216d8d4(obj, 0x1c, -1, -1, -1);
        *(int*)(g + 0x998) = 1;
        *(short*)(obj + 6) = 1;
        return;
    }
    switch (state) {
    case 1:
        if (*(int*)(g + 0x9a0) != 0) break;
        if (*(int*)(g + 0x998) != 0) break;
        ReinitController02043204(g);
        *(short*)(obj + 4) = 7;
        *(short*)(obj + 6) = 0;
        break;
    }
}
