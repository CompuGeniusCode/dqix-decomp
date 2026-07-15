#include <globaldefs.h>

// USA: func_ov017_021b1fd4
ARM int GetFieldromField_021b1fd4_021b1fd4(void* obj) {
    void* p = *(void**)((char*)obj + 0x24);
    return p ? *(int*)((char*)p + 0x384) : 0;
}
