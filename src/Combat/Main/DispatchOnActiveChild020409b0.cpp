#include <globaldefs.h>

extern "C" int func_0203ce14(void* obj, int arg);
extern "C" int func_02041470(void* obj, int arg);

struct Node020409b0 {
    char pad[0x14];
    void* f14;
    void* f18;
};

// USA: func_020409b0
ARM int DispatchOnActiveChild020409b0(struct Node020409b0* obj, int arg) {
    if (obj->f14 != NULL) {
        return func_0203ce14(obj->f14, arg);
    }
    {
        void* b = obj->f18;
        if (b != NULL) {
            return func_02041470(b, arg);
        }
        return (int)b;
    }
}
