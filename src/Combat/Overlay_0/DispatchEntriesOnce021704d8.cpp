#include <globaldefs.h>

struct Struct0203c1c8 {
    int field0;
    int field4;
    int field8;
    int fieldc;
    int field10;
    short field14;
};

void AdjustAndDispatchEntry0203c1c8(struct Struct0203c1c8* obj);

// USA: func_ov000_021704d8
ARM void DispatchEntriesOnce021704d8(struct Struct0203c1c8* obj, int* arr1, int* arr2, int* arr3) {
    obj->fieldc = 2;
    obj->field10 = 1;
    int i;
    for (i = 0; i < 1; i++) {
        int v0 = arr1[i];
        int v4 = arr2[i];
        obj->field0 = v0;
        obj->field4 = v4;
        obj->field8 = arr3[i];
        AdjustAndDispatchEntry0203c1c8(obj);
    }
    obj->field8 = 0;
}
