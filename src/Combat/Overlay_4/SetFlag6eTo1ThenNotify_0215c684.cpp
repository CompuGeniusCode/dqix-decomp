#include <globaldefs.h>

struct Struct021707d8_0215c684 { char pad[0x8]; unsigned char* ptr; };
extern Struct021707d8_0215c684 data_ov004_021707d8;

typedef void (*FuncPtr0215c684)(void*, int);
struct Handler0215c684 { char pad[0xe0]; FuncPtr0215c684 func; };
struct Node0215c684 { Handler0215c684* handler; };

extern "C" Node0215c684* func_ov004_02156f38(void* obj, int eventId);
extern "C" int func_ov004_02156f6c(void* obj, int flag);
extern "C" void func_ov023_021f809c(int result, void* obj);

// USA: func_ov004_0215c684
ARM int SetFlag6eTo1ThenNotify_0215c684(void* obj) {
    if (data_ov004_021707d8.ptr[0x6e] > 1) {
        data_ov004_021707d8.ptr[0x6e] = 1;
        Node0215c684* node = func_ov004_02156f38(obj, 0x25a);
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
