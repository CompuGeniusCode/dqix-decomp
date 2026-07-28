#include <globaldefs.h>
extern "C" void* cleanup(void*);
extern "C" int frc(void* p) {
    cleanup(p);
    return 0;
}
