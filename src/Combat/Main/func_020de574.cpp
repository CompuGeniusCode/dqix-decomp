#include <globaldefs.h>

struct Table020de574 {
    unsigned char pad0[0x10];
    int add;
};

struct Cursor020de574 {
    unsigned char pad0[4];
    int cur;
};

// USA: func_020de574
extern "C" ARM int func_020de574(Table020de574 *table, Cursor020de574 *cursor) {
    int flag = 1;
    int v = (int)((char *)cursor->cur - (char *)0);
    if (v != -1) {
        if (table->add != 0) {
            flag = 0;
        }
    }
    cursor->cur = flag ? 0 : table->add + v;
    return 1;
}
