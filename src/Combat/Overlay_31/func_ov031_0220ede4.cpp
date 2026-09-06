#include <globaldefs.h>

int GetData0224e53c_0220d60c(void);
int CompareBytes6_0220f368(unsigned char *a, unsigned char *b);

struct Node0220ede4 {
    unsigned char pad0[0xc];
    Node0220ede4 *next;
    unsigned char pad10[4];
};

struct ListHeader0220ede4 {
    unsigned char pad0[4];
    Node0220ede4 *head;
};

// USA: func_ov031_0220ede4
extern "C" ARM Node0220ede4 *func_ov031_0220ede4(unsigned char *key) {
    char *base = (char *)GetData0224e53c_0220d60c() + 0x2000;
    Node0220ede4 *node = NULL;
    ListHeader0220ede4 *lh = *(ListHeader0220ede4 **)(base + 0x270);
    if (key == NULL) return node;
    if (lh != NULL) {
        unsigned int cnt = *(unsigned int *)(base + 0x274);
        if (cnt > 0xc) {
            node = lh->head;
            if (node != NULL) {
                do {
                    if (CompareBytes6_0220f368((unsigned char *)node + 0x14, key) != 0) break;
                    node = node->next;
                } while (node != NULL);
            }
        }
    }
    return node;
}
