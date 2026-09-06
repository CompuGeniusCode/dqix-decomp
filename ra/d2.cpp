#include <globaldefs.h>
extern "C" void* ctorA(void*);
extern "C" void* dtorA(void*);
extern "C" int condA(void*);
struct LocA { char b[0xac]; LocA() { ctorA(this); } ~LocA() { dtorA(this); } };
extern "C" int td2(void* obj) {
    if (!condA(obj)) return 0;
    LocA l;
    if (!condA(&l)) return 0;
    condA(obj);
    return 0;
}
