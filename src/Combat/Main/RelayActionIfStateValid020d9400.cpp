#include <globaldefs.h>

struct Handle020d9400 {
    unsigned char* w0;
};

int CheckStateByType020d8a68(unsigned char*);
extern "C" int func_020d901c(unsigned char*, int);
extern "C" int func_020d9354(unsigned char*, unsigned char*, int);

// USA: func_020d9400
ARM int RelayActionIfStateValid020d9400(struct Handle020d9400* obj, unsigned char* target, int param) {
    unsigned char* handle;
    int value;
    if (obj->w0 == NULL || CheckStateByType020d8a68(target) == 0) return 0;
    handle = obj->w0;
    value = func_020d901c(handle, param);
    return func_020d9354(target, handle, value);
}
