#include <globaldefs.h>

struct Obj2081;
struct Elem2081;
struct Elem2081* FindElementByByte0xc4(struct Obj2081* obj, int key);
int IsElemFlag0x20Clear(struct Obj2081* obj, int key);

// USA: func_ov006_02158080
ARM int CheckElementFlag_02158080_02158080(struct Obj2081* obj, int key) {
    if (FindElementByByte0xc4(obj, key) != NULL) {
        if (IsElemFlag0x20Clear(obj, key) != 0) {
            return 1;
        }
    }
    return 0;
}
