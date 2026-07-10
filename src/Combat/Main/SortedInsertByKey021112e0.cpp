#include <globaldefs.h>

extern char data_021112e0;

struct Node020c72ec {
    char pad0[0x68];
    struct Node020c72ec *next;   /* 0x68 */
    unsigned int pad1;           /* 0x6c */
    unsigned int key;            /* 0x70 */
};

// USA: func_020c72ec
#pragma optimize_for_size off
ARM void SortedInsertByKey021112e0(struct Node020c72ec *obj) {
    struct Node020c72ec *cur = *(struct Node020c72ec**)(&data_021112e0 + 0x2c);
    struct Node020c72ec *prev = 0;
    while (cur != 0 && cur->key < obj->key) {
        prev = cur;
        cur = cur->next;
    }
    if (prev == 0) {
        obj->next = *(struct Node020c72ec**)(&data_021112e0 + 0x2c);
        *(struct Node020c72ec**)(&data_021112e0 + 0x2c) = obj;
        return;
    }
    obj->next = prev->next;
    prev->next = obj;
}
