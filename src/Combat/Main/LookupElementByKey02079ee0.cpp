#include <globaldefs.h>

struct Element02079f20;
struct Container02079f20;
struct S020797f8;
typedef int (*KeyFunc02079f20)(struct Element02079f20*);

extern struct Element02079f20* BinarySearch02079f20(struct Container02079f20* c, int key, KeyFunc02079f20 fn);
extern int GetLow8BitField(struct S020797f8* p);

// USA: func_02079ee0
ARM struct Element02079f20* LookupElementByKey02079ee0(void* obj, int key) {
    struct Element02079f20* r;
    if (key == 0) return NULL;
    r = BinarySearch02079f20((struct Container02079f20*)((char*)obj + 0x18), key, (KeyFunc02079f20)GetLow8BitField);
    if (r != NULL) return r;
    return BinarySearch02079f20((struct Container02079f20*)((char*)obj + 0x24), key, (KeyFunc02079f20)GetLow8BitField);
}
