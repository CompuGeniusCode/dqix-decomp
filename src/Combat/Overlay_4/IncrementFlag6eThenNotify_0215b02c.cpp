#include <globaldefs.h>

struct Struct021707d8_0215b02c { char pad[0x8]; unsigned char* ptr; };
extern Struct021707d8_0215b02c data_ov004_021707d8;

typedef void (*FuncPtr0215b02c)(void*, int);
struct Handler0215b02c { char pad[0xe0]; FuncPtr0215b02c func; };
struct Node0215b02c { Handler0215b02c* handler; };

extern "C" Node0215b02c* func_ov004_02156f38(void* obj, int eventId);
extern "C" int func_ov004_02156f6c(void* obj, int flag);
extern "C" void func_ov023_021f809c(int result, void* obj);

// USA: func_ov004_0215b02c
ARM int IncrementFlag6eThenNotify_0215b02c(void* obj) {
    if (data_ov004_021707d8.ptr[0x6e] < data_ov004_021707d8.ptr[0x6f]) {
        data_ov004_021707d8.ptr[0x6e]++;
        Node0215b02c* node = func_ov004_02156f38(obj, 0x25a);
        if (node) {
            node->handler->func(node, data_ov004_021707d8.ptr[0x6e]);
        }
        int result = func_ov004_02156f6c(obj, 0x19);
        if (result) {
            func_ov023_021f809c(result, obj);
        }
    }
    return 0;
}
