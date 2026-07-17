#include <globaldefs.h>

int GetData0224e53c_0220d60c(void);
int TryLock_0220f2e0(void*);
int ReleaseLock_0220f330(void*);
int TailCallReleaseGlobal_0220f2cc(void);
int SubmitBattleContextEntry020d5bfc(int a0, void* a1, void* a2, unsigned int a3);

extern int data_ov031_0224e54c;

// USA: func_ov031_0220efd0
ARM void SubmitOrRelease_0220efd0(void) {
    int base = GetData0224e53c_0220d60c();
    if (base == 0) {
        return;
    }
    char *p = (char*)base + 0x2000;
    if (*(int*)(p + 0x260) != 9) {
        return;
    }
    if (*(unsigned char*)(p + 0x26b) == 1) {
        return;
    }
    if (TryLock_0220f2e0(&data_ov031_0224e54c) == 0) {
        return;
    }
    int rc = SubmitBattleContextEntry020d5bfc((int)TailCallReleaseGlobal_0220f2cc, (char*)base + 0x144 + 0x2000, (char*)base + 0xf00, 0);
    if (rc == 2) {
        return;
    }
    ReleaseLock_0220f330(&data_ov031_0224e54c);
}
