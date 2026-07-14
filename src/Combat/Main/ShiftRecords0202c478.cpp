#include <globaldefs.h>

ARM void PushInterruptDisableState(void);
extern "C" void func_020d8694(void);

struct Record0202ba08;
ARM struct Record0202ba08* CopyRecord0202ba08(struct Record0202ba08* dst, struct Record0202ba08* src);

struct Container0202c478 {
    char pad[0xc];
    int count;
    char pad2[0x790 - 0x10];
    int arr790[0x40];
};

// USA: func_0202c478
ARM void ShiftRecords0202c478(struct Container0202c478* obj) {
    PushInterruptDisableState();
    char* base = (char*)obj;
    int i;
    for (i = 0; i < obj->count; i++) {
        obj->arr790[i] -= 0x10;
        if (obj->arr790[i] > 0) {
            continue;
        }
        int j;
        for (j = i; j < obj->count - 1; j++) {
            CopyRecord0202ba08((struct Record0202ba08*)(base + 0x10 + j * 0xc0),
                                (struct Record0202ba08*)(base + 0x10 + (j + 1) * 0xc0));
        }
        obj->count--;
    }
    func_020d8694();
}
