#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* func_020a171c(void* obj, int type, void* arg);

struct FooA1698 {
    unsigned int unk0;
    unsigned short unk4;
    unsigned short pad6;
    void* unk8;
    unsigned char* unkc;
    unsigned char unk10;
};

// USA: func_020a1698
ARM void InitAndBuildList020a1698(FooA1698* obj, void* arg1) {
    obj->unk8 = NULL;
    memset(obj->unkc, 0, (obj->unk4 - 1) / 8 + 1);

    int type = 2;
    obj->unk8 = func_020a171c(obj, type, arg1);
    void* node = obj->unk8;
    if (node != NULL) {
        while (node != NULL) {
            void* next = func_020a171c(obj, type, arg1);
            *(void**)((char*)node + 8) = next;
            node = next;
        }
    }
    obj->unk10 = 2;
}
