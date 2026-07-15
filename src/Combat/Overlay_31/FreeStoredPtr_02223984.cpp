#include <globaldefs.h>

extern "C" int func_ov031_0223cf70(void*);
extern void* data_ov031_02250bf4;

// USA: func_ov031_02223984
ARM int FreeStoredPtr_02223984(void) {
    return func_ov031_0223cf70(&data_ov031_02250bf4);
}
