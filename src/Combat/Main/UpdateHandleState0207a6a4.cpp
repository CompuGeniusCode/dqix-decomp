#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct List0202fe68;

struct List0202fec8;

extern "C" {
}

struct Obj0207a6a4 {
    int unk0;
    int field4;
    int field8;
    int fieldc;
    unsigned char state;
};

// USA: func_0207a6a4
ARM int UpdateHandleState0207a6a4(struct Obj0207a6a4* obj) {
    int listPtr = (int)BackgroundLoader::GetInstance();

    if (obj->state == 1) {
        if (((BackgroundLoader*)(listPtr))->GetTaskStatus((int)(obj->field4))) {
            if (((BackgroundLoader*)((struct List0202fe68*)listPtr))->GetDetailedTaskStatus((int)(obj->field4)) != 2) {
                ((BackgroundLoader*)(listPtr))->RemoveTask((int)(obj->field4));
                obj->field4 = -1;
                obj->state = 2;
                return 1;
            }
            ((BackgroundLoader*)((struct List0202fec8*)listPtr))->GetLoadedFileByID((int)(obj->field4), (void**)(&obj->field8), (unsigned int*)(&obj->fieldc));
            obj->state = 2;
        }
        return 0;
    }

    return obj->state == 2;
}
