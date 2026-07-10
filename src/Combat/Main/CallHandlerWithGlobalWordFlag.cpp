#include <globaldefs.h>

extern "C" int GetGlobalWord02112140(void);
extern "C" int func_020cc6ac(void* obj, int mode);

// USA: func_020cccd4
ARM int CallHandlerWithGlobalWordFlag(void* obj) {
    int mode = GetGlobalWord02112140() != 0 ? 5 : 0;
    return func_020cc6ac(obj, mode);
}
