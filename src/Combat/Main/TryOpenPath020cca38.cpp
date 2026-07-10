#include <globaldefs.h>

struct TwoWords020cca38 {
    int a;
    int b;
};

int TryParsePath020cc940(void*, void*);
extern "C" int func_020cc9c8(void* obj, struct TwoWords020cca38 s);

#pragma optimize_for_size off

// USA: func_020cca38
ARM int TryOpenPath020cca38(void* obj, void* path) {
    struct TwoWords020cca38 local;
    if (TryParsePath020cc940(&local, path) != 0) {
        if (func_020cc9c8(obj, local) != 0) {
            return 1;
        }
    }
    return 0;
}
