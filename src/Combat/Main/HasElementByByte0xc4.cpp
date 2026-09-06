#include <globaldefs.h>

struct Obj2081;
struct Elem2081;

struct Elem2081* FindElementByByte0xc4(struct Obj2081* obj, int key);

// USA: func_020811d0
ARM int HasElementByByte0xc4(struct Obj2081* obj, int key) {
    return FindElementByByte0xc4(obj, key) != NULL;
}
