#include <globaldefs.h>

extern "C" void func_0204c804(void* p);

struct Elem2081;

struct Obj2081 {
    char pad0[0x30];
    struct Elem2081* elems;
};

extern struct Elem2081* FindElementByByte0xc4(struct Obj2081* obj, int key);

// USA: func_0207fdcc
ARM void CallFunc0204c804OnMatchingKey(struct Obj2081* obj, int key) {
    struct Elem2081* e;
    if (obj->elems == NULL) return;
    e = FindElementByByte0xc4(obj, key);
    if (e == NULL) return;
    func_0204c804(e);
}
