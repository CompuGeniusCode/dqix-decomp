#include <globaldefs.h>

int GetData02104304Field4();

struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);

extern "C" int func_020e0028(void* p, int b, int out1, int out2, void* p2, int field84);
extern "C" int func_020301c8(int handle, int id);

struct EntryTask0216fd80 {
    int id;
    char pad4[0x84 - 0x4];
    int field84;
    char pad88[0xa1 - 0x88];
    unsigned char byteA1;
};

// USA: func_ov000_0216fd80
ARM void BeginListEntryTask_0216fd80(struct EntryTask0216fd80* obj, int b) {
    int handle = GetData02104304Field4();
    int out1, out2;
    GetListEntryValues0202fec8((struct List0202fec8*)handle, obj->id, &out1, &out2);
    func_020e0028((char*)obj + 0x88, b, out1, out2, &obj->pad4, (unsigned short)obj->field84);
    func_020301c8(handle, obj->id);
    obj->id = -1;
    obj->byteA1 = 1;
}
