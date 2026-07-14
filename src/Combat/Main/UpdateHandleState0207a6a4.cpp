#include <globaldefs.h>

int GetData02104304Field4();

struct List0202fe68;
int LookupListValueByKey(struct List0202fe68* obj, int key);

struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);

extern "C" {
    int func_0202fdd0(int a, int b);
    void func_020301c8(int a, int b);
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
    int listPtr = GetData02104304Field4();

    if (obj->state == 1) {
        if (func_0202fdd0(listPtr, obj->field4)) {
            if (LookupListValueByKey((struct List0202fe68*)listPtr, obj->field4) != 2) {
                func_020301c8(listPtr, obj->field4);
                obj->field4 = -1;
                obj->state = 2;
                return 1;
            }
            GetListEntryValues0202fec8((struct List0202fec8*)listPtr, obj->field4, &obj->field8, &obj->fieldc);
            obj->state = 2;
        }
        return 0;
    }

    return obj->state == 2;
}
