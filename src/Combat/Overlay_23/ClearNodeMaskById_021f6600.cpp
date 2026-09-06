#include <globaldefs.h>

struct Node021f6600 { char pad[0xc]; unsigned char byteC; };

extern "C" void* func_ov011_021849c8(void*);
extern "C" Node021f6600* func_ov023_021f6880(void*, int);

// USA: func_ov023_021f6600
ARM void ClearNodeMaskById_021f6600(void* obj, int id, int mask) {
    void* sub = func_ov011_021849c8(obj);
    Node021f6600* node = func_ov023_021f6880(sub, id);
    if (node != NULL) {
        node->byteC &= ~mask;
    }
}
