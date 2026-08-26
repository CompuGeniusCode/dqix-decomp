#include <globaldefs.h>

struct Entry020df77c {
    int key;
    int value;
};

struct Table020df77c {
    unsigned short first;
    unsigned char pad0[6];
    Entry020df77c *entries;
    int add;
};

struct Cursor020df77c {
    short pad0;
    short count;
    int cur;
};

// USA: func_020df77c
extern "C" ARM int func_020df77c(Table020df77c *table, Cursor020df77c *cursor) {
    int off = cursor->cur;
    if (off == -1) {
        cursor->cur = 0;
    } else {
        int count;
        Entry020df77c *p = table->entries + table->first + off;
        cursor->cur = (int)p;
        count = cursor->count;
        for (int i = 0; i < count; i++) {
            int flag = 1;
            int v = (int)((char *)p->value - (char *)0);
            if (v != -1) {
                if (table->add != 0) {
                    flag = 0;
                }
            }
            p->value = flag ? 0 : table->add + v;
            p++;
        }
    }
    return 1;
}
