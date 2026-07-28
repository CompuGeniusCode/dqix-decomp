#include <globaldefs.h>

int GetData0224e53c_0220d60c(void);
extern "C" void* func_ov031_0220ede4(unsigned char* key);
extern "C" void* func_ov031_0220ece8(void);
int GetField4IfCountAbove12_0220edb4(void);
extern "C" int func_020ca4b4(void* dst, void* src, int size);
extern "C" void func_ov031_0220eea0(void* node);

struct S0220ec5c { char pad[0x3c]; unsigned short field3c; };

// USA: func_ov031_0220ec5c
extern "C" ARM void func_ov031_0220ec5c(S0220ec5c* obj, int param1) {
    int global = GetData0224e53c_0220d60c();
    if (global == 0) return;
    if (*(unsigned char*)((char*)global + 0x2000 + 0x26a) != 0 || obj->field3c != 0) return;

    char* node = (char*)func_ov031_0220ede4((unsigned char*)obj + 4);
    if (node == NULL) {
        node = (char*)func_ov031_0220ece8();
    }
    if (node == NULL && *(int*)((char*)global + 0x2000 + 0x278) == 1) {
        node = (char*)(int)GetField4IfCountAbove12_0220edb4();
    }
    if (node == NULL) return;
    *(short*)(node + 2) = (short)param1;
    func_020ca4b4(obj, node + 0x10, 0xc0);
    func_ov031_0220eea0(node);
}
