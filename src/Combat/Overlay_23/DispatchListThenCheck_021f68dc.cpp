#include <globaldefs.h>

struct Node_021f68dc {
    virtual void v0(void* arg);
    virtual void v1();
    virtual void v2();
    virtual void v3(void* arg);
    virtual void v4(void* arg);
    char pad[0x14];
    Node_021f68dc* next;
};

struct List_021f68dc {
    Node_021f68dc* head;
};

extern "C" int func_ov023_021f6ac8(List_021f68dc* obj, void* arg);
extern "C" void func_ov023_021f6a1c(List_021f68dc* obj, void* arg);

// USA: func_ov023_021f68dc  (semantic: DispatchListThenCheck_021f68dc)
extern "C" ARM void func_ov023_021f68dc(List_021f68dc* obj, void* arg) {
    Node_021f68dc* node;
    for (node = obj->head; node; node = node->next) {
        node->v3(arg);
    }
    for (node = obj->head; node; node = node->next) {
        node->v0(arg);
    }
    for (node = obj->head; node; node = node->next) {
        node->v4(arg);
    }
    if (func_ov023_021f6ac8(obj, arg) != 0) return;
    func_ov023_021f6a1c(obj, arg);
}
