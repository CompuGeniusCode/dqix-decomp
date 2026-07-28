#include <globaldefs.h>

int HasCombatantWithFlag_0215f74c_0215f74c(int unused, int combatantId);
extern "C" void func_ov004_0215fdfc(void*);
extern "C" int func_ov004_0215e9dc(void*, void*, int, int);
extern "C" void func_ov004_0216033c(void*);
extern "C" void func_ov004_02161514(void*);
extern "C" void func_ov004_02161c18(void*);
extern "C" void func_ov004_02162108(void*);
extern "C" void func_ov004_0215ef9c(int);

struct Obj021f809c;
extern "C" void func_ov023_021f809c(struct Obj021f809c*, void*);
void* CheckNodeState6_0215e4c0(void* a, int key);

extern unsigned char data_ov004_021707e8;

#define D021707e8 ((char*)&data_ov004_021707e8)

// USA: func_ov004_021613f8  (semantic: SetupNextFieldOrDispatch_021613f8)
extern "C" ARM int func_ov004_021613f8(void* a) {
    if (*(signed char*)(D021707e8 + 6) <= 1) return 0;

    void* combatant = *(void**)(D021707e8 + 0x1c);
    if (!HasCombatantWithFlag_0215f74c_0215f74c((int)a, (int)combatant)) {
        func_ov004_0215fdfc(a);
        return 0;
    }

    *(signed char*)(D021707e8 + 0xb) = *(signed char*)(D021707e8 + 0xb) - 1;
    if (*(signed char*)(D021707e8 + 0xb) < 0) {
        *(signed char*)(D021707e8 + 0xb) = *(signed char*)(D021707e8 + 6) - 1;
    }

    switch (*(unsigned char*)(D021707e8 + 7) - 0x64) {
    case 0:
        *(unsigned char*)(D021707e8 + 8) = (unsigned char)func_ov004_0215e9dc(a, *(void**)(D021707e8 + 0x1c), *(unsigned char*)(D021707e8 + 8), 0);
        func_ov004_0216033c(a);
        break;
    case 1:
        *(unsigned char*)(D021707e8 + 8) = (unsigned char)func_ov004_0215e9dc(a, *(void**)(D021707e8 + 0x1c), *(unsigned char*)(D021707e8 + 8), 0);
        func_ov004_02161514(a);
        break;
    case 2:
        func_ov004_0215ef9c(1);
        func_ov004_02161c18(a);
        break;
    case 3:
        func_ov004_0215ef9c(0);
        func_ov004_02162108(a);
        break;
    }

    func_ov023_021f809c((struct Obj021f809c*)CheckNodeState6_0215e4c0(a, 3), a);
    return 0;
}
