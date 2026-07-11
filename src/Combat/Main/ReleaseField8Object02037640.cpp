#include <globaldefs.h>
void* GetField0x580207ecc4(void*);

extern "C" void func_020dc124(void* p, int a);
extern "C" void func_020dc184(void* p, int a);

struct Obj02037640 {
    unsigned char pad[8];
    void* field8;   // 0x8
};

// USA: func_02037640
ARM void ReleaseField8Object02037640(struct Obj02037640* obj) {
    void* p = obj->field8;
    void* q;
    if (p == NULL) return;
    q = GetField0x580207ecc4((void*)(p));
    if (q == NULL) return;
    func_020dc124(q, 0);
    func_020dc184(q, 0);
}
