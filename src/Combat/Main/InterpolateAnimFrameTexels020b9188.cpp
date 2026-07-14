#include <globaldefs.h>

extern "C" int func_020b8e60(void* a, int b, int c);
extern "C" int func_020b8fc8(void* a, int b, int c);

struct InnerStruct020b9188 {
    char pad0[9];
    unsigned char field9;
    char pad2[4];
    unsigned short fieldE;
};

struct InfoStruct020b9188 {
    int field0;
    int field4;
    void* field8;
};

struct RecordStruct020b9188 {
    int v0;
    int v4;
    int v8;
    int vC;
    int v10;
};

struct ObjStruct020b9188 {
    int field0;
    int field4;
    int field8;
    int fieldC;
};

#pragma optimize_for_size off
// USA: func_020b9188
ARM void InterpolateAnimFrameTexels020b9188(struct ObjStruct020b9188* obj, struct InfoStruct020b9188* info, int scale) {
    struct InnerStruct020b9188* inner = (struct InnerStruct020b9188*)info->field8;
    int shift = info->field0 >> 12;
    unsigned char* table = (unsigned char*)inner + 8;
    struct RecordStruct020b9188* rec;
    int a, b, bit;
    unsigned int v;

    if (table != 0 && (unsigned int)inner->field9 > (unsigned int)(unsigned short)scale) {
        unsigned short off = inner->fieldE;
        unsigned short stride = *(unsigned short*)(table + off);
        rec = (struct RecordStruct020b9188*)(table + off + 4 + stride * (unsigned short)scale);
    } else {
        rec = 0;
    }

    a = func_020b8e60(inner, rec->v0, shift);
    b = func_020b8e60(inner, rec->v4, shift);
    v = a | (b << 16);
    bit = (obj->field4 & 0x8000) != 0;
    v |= bit << 15;
    obj->field4 = v;

    a = func_020b8e60(inner, rec->vC, shift);
    b = func_020b8e60(inner, rec->v8, shift);
    v = b | (a << 16);
    bit = (obj->field8 & 0x8000) != 0;
    v |= bit << 15;
    obj->field8 = v;

    a = func_020b8fc8(inner, rec->v10, shift);
    v = (obj->fieldC & ~0x1f0000) | (a << 16);
    obj->fieldC = v;
}
