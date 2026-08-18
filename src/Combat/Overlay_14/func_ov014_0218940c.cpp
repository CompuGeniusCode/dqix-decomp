#include <globaldefs.h>

struct ArrayStruct021893e4;
struct KeyStruct021893e4;
extern int* GetIndexedSlotOrNull_021893e4(struct ArrayStruct021893e4* a, struct KeyStruct021893e4* b);

// USA: func_ov014_0218940c
extern "C" ARM int* func_ov014_0218940c(struct ArrayStruct021893e4* table, int index, struct KeyStruct021893e4* key) {
    if (!key) return 0;
    int* slot = GetIndexedSlotOrNull_021893e4(table, key);
    return slot + index;
}
