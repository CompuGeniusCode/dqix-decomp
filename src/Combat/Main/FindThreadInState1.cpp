#include <globaldefs.h>

struct ThreadNode7978 {
    char pad[0x64];
    int state;             // 0x64
    ThreadNode7978* next;  // 0x68
};
extern int data_021112e0;

// USA: func_020c7978
ARM ThreadNode7978* FindThreadInState1(void) {
    ThreadNode7978* p = *(ThreadNode7978**)((char*)&data_021112e0 + 0x2c);
    while (p != NULL && p->state != 1) {
        p = p->next;
    }
    return p;
}
