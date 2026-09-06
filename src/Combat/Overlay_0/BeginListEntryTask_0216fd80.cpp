#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct List0202fec8;

extern "C" int func_020e0028(void* p, int b, int out1, int out2, void* p2, int field84);

struct EntryTask0216fd80 {
    int id;
    char pad4[0x84 - 0x4];
    int field84;
    char pad88[0xa1 - 0x88];
    unsigned char byteA1;
};

// USA: func_ov000_0216fd80
ARM void BeginListEntryTask_0216fd80(struct EntryTask0216fd80* obj, int b) {
    int handle = (int)BackgroundLoader::GetInstance();
    int out1, out2;
    ((BackgroundLoader*)((struct List0202fec8*)handle))->GetLoadedFileByID((int)(obj->id), (void**)(&out1), (unsigned int*)(&out2));
    func_020e0028((char*)obj + 0x88, b, out1, out2, &obj->pad4, (unsigned short)obj->field84);
    ((BackgroundLoader*)(handle))->RemoveTask((int)(obj->id));
    obj->id = -1;
    obj->byteA1 = 1;
}
