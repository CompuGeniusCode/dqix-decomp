#include <globaldefs.h>

struct Block0x30 { unsigned int v[12]; };

struct Node02037bf8 {
    unsigned short field0;
    char pad2[2];
    Block0x30 block;           // +0x4
    struct Node02037bf8* next; // +0x34
};

struct Head02104b18 {
    char pad0[0x14];
    Node02037bf8* head; // +0x14
};

struct Obj02037bf8 {
    char pad0[8];
    int flags8;              // +0x8
    char pad12[0xae - 0xc];
    unsigned char field_ae;   // +0xae
};

extern Head02104b18 data_02104b18;
extern Block0x30 data_02104b30;

void SubmitPendingCommandBlocks(void* r6, void* r5);
void* GetOrInitObject0210a110(void);
extern "C" void func_020c1d60(void* a, void* b, void* c);

// USA: func_02037bf8  (semantic: DispatchMatchingCommandBlockFromList)
extern "C" ARM void func_02037bf8(Obj02037bf8* obj) {
    Node02037bf8* node = data_02104b18.head;
    while (node != 0) {
        if ((obj->flags8 & 0x10) && obj->field_ae == node->field0) {
            SubmitPendingCommandBlocks(&node->block, 0);
            data_02104b30 = node->block;
            void* o = GetOrInitObject0210a110();
            func_020c1d60(&node->block, o, &node->block);
        }
        node = node->next;
    }
}
