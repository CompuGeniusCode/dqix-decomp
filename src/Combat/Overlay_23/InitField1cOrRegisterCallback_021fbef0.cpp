#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" int func_ov023_021f6bb8(void*);
extern "C" void func_ov023_021f6bb0(void*, int);
int GetData02104304Field4();
int CallFunc0202fa38Mode2(int a, int b, int c, int d);

extern int data_020f2a38;
extern int data_020f2a30;

// USA: func_ov023_021fbef0
ARM int InitField1cOrRegisterCallback_021fbef0(void* a, void* b) {
    void* sub = func_ov011_021849c8(b);
    if (func_ov023_021f6bb8(sub) >= 0) {
        return *(int*)((char*)a + 0x1c);
    }
    int result = CallFunc0202fa38Mode2(GetData02104304Field4(), data_020f2a38, data_020f2a30, 0);
    func_ov023_021f6bb0(sub, result);
    return 1;
}
