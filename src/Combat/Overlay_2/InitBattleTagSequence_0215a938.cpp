#include <globaldefs.h>

int ClearPendingFlag0215a8cc(char* p);
void InitBattleTag0215bf34(char* base);
void InitBattleTag0215c028(char* base);
extern "C" void func_ov002_0215c0f8(unsigned char* obj);
extern "C" void func_ov002_02161cf0(char* base);
extern "C" void func_ov002_0215f3a0(char* base);

// USA: func_ov002_0215a938  (semantic: InitBattleTagSequence_0215a938)
extern "C" ARM void func_ov002_0215a938(char* base) {
    if (!ClearPendingFlag0215a8cc(base)) return;

    *(int*)(base + 0x1000 + 0xbb8) = 1;
    InitBattleTag0215bf34(base);
    InitBattleTag0215c028(base);
    func_ov002_02161cf0(base);
    func_ov002_0215c0f8((unsigned char*)base);

    if (*(short*)(base + 0x1b00 + 0xe0) == 5) {
        *(int*)(base + 0x1000 + 0xbb8) = 0x15;
        func_ov002_02161cf0(base);
        func_ov002_0215f3a0(base);
    }

    *(int*)(base + 0x1000 + 0xbc0) = 1;
}
