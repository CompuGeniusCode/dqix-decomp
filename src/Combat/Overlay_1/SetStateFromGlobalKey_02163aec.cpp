#include <globaldefs.h>

extern "C" void* func_02012fe4(void);
extern "C" int func_0209cd50(int key);
struct Actor0209c3b4;
void SetStateAndDispatch0209c3b4(struct Actor0209c3b4* actor, int val);
extern void* data_02109bf4;

// USA: func_ov001_02163aec
ARM int SetStateFromGlobalKey_02163aec(void) {
    unsigned short key = *(unsigned short*)func_02012fe4();
    int v = func_0209cd50(key);
    SetStateAndDispatch0209c3b4((struct Actor0209c3b4*)&data_02109bf4, v);
    return 1;
}
