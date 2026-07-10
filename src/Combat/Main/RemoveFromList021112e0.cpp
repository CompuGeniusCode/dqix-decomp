#include <globaldefs.h>

extern char data_021112e0;

struct Node020c734c {
    char pad0[0x68];
    struct Node020c734c *next;   /* 0x68 */
};

// USA: func_020c734c
#pragma optimize_for_size off
ARM void RemoveFromList021112e0(struct Node020c734c *obj) {
    struct Node020c734c *prev = 0;
    struct Node020c734c *cur = *(struct Node020c734c**)(&data_021112e0 + 0x2c);
    while (cur != 0 && cur != obj) {
        prev = cur;
        cur = cur->next;
    }
    if (prev == 0) {
        *(struct Node020c734c**)(&data_021112e0 + 0x2c) = obj->next;
        return;
    }
    prev->next = obj->next;
}
