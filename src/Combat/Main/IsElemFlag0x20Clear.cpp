#include <globaldefs.h>

struct Obj2081;
struct Elem2081 { char pad[0xc5]; unsigned char flags; };
struct Elem2081* FindElementByByte0xc4(struct Obj2081* obj, int key);

// USA: func_02080c3c
ARM int IsElemFlag0x20Clear(struct Obj2081* obj, int key) {
    struct Elem2081* e = FindElementByByte0xc4(obj, key);
    if (e != NULL) {
        return (e->flags & 0x20) == 0;
    }
    return 0;
}
