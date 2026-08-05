#include <globaldefs.h>

struct Entry0x10_02159a74 { int type; char pad[8]; void* fieldC; };
extern "C" int func_ov001_02164624(Entry0x10_02159a74* arr, int idx);
extern "C" int func_ov001_02164578(Entry0x10_02159a74* table, int index, void* arg2, int arg3, float arg4);
extern Entry0x10_02159a74* data_ov001_02165884;

struct Self02159a74 {
    char pad0[0x10];
    int f10;
    int f14;
    int f18;
    int f1c;
    char pad2[0x3c - 0x20];
    int* f3c;
};

struct Obj02159a74 {
    char pad0[0x70];
    int f70;
};

// USA: func_ov001_02159a74
extern "C" ARM int func_ov001_02159a74(struct Self02159a74* self, struct Obj02159a74* obj) {
    if (self->f18 == 0) {
        if (func_ov001_02164624(data_ov001_02165884, obj->f70) != 0) {
            float f = (float)self->f14;
            func_ov001_02164578(data_ov001_02165884, obj->f70, &self->f1c, self->f10, f);
            if (self->f3c != NULL) {
                if (*self->f3c == 0xd) {
                    return 0;
                }
            }
            self->f18 = 1;
            return 1;
        }
        return 1;
    }
    return 0;
}
