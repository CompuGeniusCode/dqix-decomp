#include <globaldefs.h>

extern short data_ov003_0217f420[3];

void GetEntryFieldsAt0x602080828(void* obj, int id, short* outX, short* outY);
void SetEntryFieldsAt0x602080854(void* obj, int id, int x, int y);

struct Parent809a0;
ARM void SetEntryPositionById(struct Parent809a0* obj, int id, short x, short y);

// USA: func_ov003_02160794
ARM void RepositionEntriesInRange_02160794(void* self) {
    short* base = *(short**)((char*)self + 0x470);
    if (base == 0) {
        return;
    }
    void* list = *(void**)((char*)self + 0x324);
    for (int i = 0; i < 3; i++) {
        short* basePtr = *(short**)((char*)self + 0x470);
        short id = data_ov003_0217f420[i];
        short baseVal = *basePtr;
        if (id > baseVal) {
            continue;
        }
        if (baseVal >= id + 4) {
            continue;
        }
        for (int j = 0; j < 4; j++) {
            short x, y;
            GetEntryFieldsAt0x602080828(list, id, &x, &y);
            SetEntryFieldsAt0x602080854(list, id, x, y);
            SetEntryPositionById((struct Parent809a0*)list, id, 0xd0, 0xa);
            id = (short)(id + 1);
        }
    }
}
