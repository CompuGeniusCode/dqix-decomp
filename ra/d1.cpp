#include <globaldefs.h>
struct L0215c30c { char b[0xac]; L0215c30c(); ~L0215c30c(); };
extern "C" int condA(void*);
extern "C" void* allocA(void*, int);
extern "C" int tdtor(void* obj) {
    L0215c30c l;
    if (!condA(obj)) {
        return 0;
    }
    condA(&l);
    return 0;
}
