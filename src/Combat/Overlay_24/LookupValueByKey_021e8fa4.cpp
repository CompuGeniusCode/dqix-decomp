#include <globaldefs.h>

extern "C" int func_ov000_02156068(void* obj, int val, int zero, int one);

struct FieldRefStruct_021e8fa4 {
    char unk[0x10];
    void* field10;
};

struct Entry_021e8fa4 {
    short value;
    short pad;
};

extern struct Entry_021e8fa4 data_ov024_021fe820[];
extern struct Entry_021e8fa4 data_ov024_021fe822[];

// USA: func_ov024_021e8fa4
ARM int LookupValueByKey_021e8fa4(struct FieldRefStruct_021e8fa4* self, int unused, int id) {
    if (id == 2) {
        int result = func_ov000_02156068(self->field10, unused, 0, 2);
        if (result != 0) {
            return 0;
        }
    }
    int idx = 0;
    while (data_ov024_021fe820[idx].value != -1) {
        if (id == data_ov024_021fe820[idx].value) {
            return data_ov024_021fe822[idx].value;
        }
        idx++;
    }
    return 0;
}
