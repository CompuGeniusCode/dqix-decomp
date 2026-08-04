#include <globaldefs.h>

struct Header020b3284 { unsigned short len; };
struct Node020b3284 { char pad0; unsigned char count; char pad2[4]; unsigned short off; };
struct Entry020b3284 { char pad[3]; unsigned char flags; };
struct Obj020b3284 { char pad[8]; int field8; };

extern "C" void func_020b30cc(void*);

// USA: func_020b3284  (semantic: RunFlaggedEntries020b3284)
extern "C" ARM int func_020b3284(struct Obj020b3284* obj) {
    struct Header020b3284* hdr = (obj != NULL && obj->field8 != 0) ? (struct Header020b3284*)((char*)obj + obj->field8) : NULL;
    struct Node020b3284* node = (struct Node020b3284*)((char*)hdr + hdr->len);
    unsigned char count = node->count;
    unsigned int i = 0;
    if (i >= count) return count;
    do {
        struct Entry020b3284* entry;
        if (node != NULL && i < *(volatile unsigned char*)&node->count) {
            unsigned short off = node->off;
            unsigned short elemSize = *(unsigned short*)((char*)node + off);
            entry = (struct Entry020b3284*)((char*)node + off + 4 + elemSize * i);
        } else {
            entry = NULL;
        }
        if (entry->flags & 1) {
            func_020b30cc(hdr);
        }
        i++;
    } while (i < node->count);
    return node->count;
}
