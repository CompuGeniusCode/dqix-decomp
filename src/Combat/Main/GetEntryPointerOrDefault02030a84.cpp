#include <globaldefs.h>

extern char data_020ef918;

struct InnerTable02030a84 {
    int field0;
    int field4;
    int field8;
};

struct Struct02030a84 {
    int field0;
    int field4;
    int field8;
    void* fieldC;
    int field10;
    struct InnerTable02030a84* field14;
    int field18;
    char* field1C;
    char* field20;
};

// USA: func_02030a84
ARM char* GetEntryPointerOrDefault02030a84(struct Struct02030a84* s, int idx) {
    if (!s->fieldC || s->field10 <= 0 || !s->field14 || !s->field1C) {
        return NULL;
    }
    if (idx == -1) {
        return &data_020ef918;
    }
    if (idx == -2 || idx < 0) {
        return NULL;
    }
    if (idx >= s->field14->field8) {
        return NULL;
    }
    return s->field20 ? s->field20 + idx : s->field1C + idx;
}
