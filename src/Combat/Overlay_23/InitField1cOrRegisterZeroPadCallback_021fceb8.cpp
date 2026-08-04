#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" int func_ov023_021f6bb8(void*);
extern "C" void func_ov023_021f6bb0(void*, int);
extern "C" int sprintf(void* dst, void* fmt, int a);
int GetData02104304Field4();
int CallFunc0202fa38ZeroPad(int a, int b, int c);

extern char data_ov023_021ff7b4;

// USA: func_ov023_021fceb8  (semantic: InitField1cOrRegisterZeroPadCallback_021fceb8)
extern "C" ARM int func_ov023_021fceb8(void* a, void* b) {
    void* sub = func_ov011_021849c8(b);
    if (func_ov023_021f6bb8(sub) >= 0) {
        return *(int*)((char*)a + 0x1c);
    }
    char buf[0x50];
    int builder = GetData02104304Field4();
    sprintf(buf, &data_ov023_021ff7b4, *(int*)((char*)a + 0x10));
    int result = CallFunc0202fa38ZeroPad(builder, (int)buf, 0);
    func_ov023_021f6bb0(sub, result);
    return 1;
}
