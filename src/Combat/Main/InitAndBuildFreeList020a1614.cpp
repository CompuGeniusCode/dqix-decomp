#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* func_020a171c(void* obj, int type, void* arg);

struct Obj020a1614 {
    unsigned int unk0;
    unsigned short unk4;
    unsigned short pad6;
    void* unk8;
    unsigned char* unkc;
    unsigned char unk10;
};

// USA: func_020a1614  (semantic: InitAndBuildFreeList020a1614)
extern "C" ARM void func_020a1614(struct Obj020a1614* obj) {
    obj->unk8 = NULL;
    memset(obj->unkc, 0, (obj->unk4 - 1) / 8 + 1);

    obj->unk8 = func_020a171c(obj, 1, NULL);
    void* node = obj->unk8;
    if (node != NULL) {
        while (node != NULL) {
            void* next = func_020a171c(obj, 1, NULL);
            *(void**)((char*)node + 8) = next;
            node = next;
        }
    }
    obj->unk10 = 1;
}
