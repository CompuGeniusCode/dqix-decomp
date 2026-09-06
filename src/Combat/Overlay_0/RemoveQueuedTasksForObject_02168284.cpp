#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct TaskPairEntry_02168284 { short field0; short taskA; short taskB; };

// USA: func_ov000_02168284  (semantic: RemoveQueuedTasksForObject_02168284)
extern "C" ARM void func_ov000_02168284(void* obj) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int i = 0;
    while (i < ((unsigned char*)obj)[0x77ee]) {
        struct TaskPairEntry_02168284* entries = (struct TaskPairEntry_02168284*)((unsigned char*)obj + 0x77d6);
        struct TaskPairEntry_02168284* e = &entries[i];
        if (e->taskA >= 0) loader->RemoveTask(e->taskA);
        if (e->taskB >= 0) loader->RemoveTask(e->taskB);
        i++;
    }
}
