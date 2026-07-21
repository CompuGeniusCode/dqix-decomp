#include <globaldefs.h>

extern void* (*data_ov031_02290dac)(int size, int align);
extern int data_ov031_02290dbc;
extern void (*data_ov031_02290dc0)(void*);
extern int data_ov031_02249424;
extern int data_ov031_0224c748;
extern int data_ov031_0224c750;

extern "C" int func_ov031_0223fb98(void* dst, int src);
int DivBy3Times4_0223e438(int x);
extern "C" int func_ov031_0223e454(void* dst, void* src, int len);
extern "C" int func_ov031_0223ede0(void** out0, void** out1, void* a2, void* a3, int a4, int a5);
extern "C" int func_ov031_02240074(void* self, void* key, void* c);
struct Obj02240df4;
extern "C" int func_ov031_0223f188(void* p0, struct Obj02240df4* p1);
void CleanupAndNotify_0223edb4(void* p0, struct Obj02240df4* p1);

struct Container0223f264 {
    unsigned char pad0[4];
    int field4;
    unsigned char pad1[8];
    void* field10;
    void* field14;
    void* field18;
    void* field1c;
    void* field20;
};

// USA: func_ov031_0223f264
#pragma optimize_for_size off
extern "C" ARM int AllocAndRegisterNames_0223f264(void* p0, int p1, int p2) {
    int size = p2 << 8;
    if (size < 0x80) size = 0x80;
    void* buf1 = data_ov031_02290dac(size, 4);
    if (buf1 == 0) {
        data_ov031_02290dbc = 1;
        return 0;
    }

    char nameBuf[12];
    int len1 = func_ov031_0223fb98(nameBuf, p1);
    void* buf2 = data_ov031_02290dac(DivBy3Times4_0223e438(len1) + 1, 4);
    if (buf2 == 0) {
        data_ov031_02290dc0(buf1);
        data_ov031_02290dbc = 1;
        return 0;
    }
    int idx1 = func_ov031_0223e454(buf2, nameBuf, len1);
    ((char*)buf2)[idx1] = 0;

    int len2 = func_ov031_0223fb98(nameBuf, p2);
    void* buf3 = data_ov031_02290dac(DivBy3Times4_0223e438(len2) + 1, 4);
    if (buf3 == 0) {
        data_ov031_02290dc0(buf2);
        data_ov031_02290dc0(buf1);
        data_ov031_02290dbc = 1;
        return 0;
    }
    int idx2 = func_ov031_0223e454(buf3, nameBuf, len2);
    ((char*)buf3)[idx2] = 0;

    void* outContainer;
    void* outObj;
    if (func_ov031_0223ede0((void**)&outContainer, (void**)&outObj, &data_ov031_02249424, buf1, size, 0) == 0) {
        data_ov031_02290dc0(buf3);
        data_ov031_02290dc0(buf2);
        data_ov031_02290dc0(buf1);
        return 0;
    }

    if (func_ov031_02240074(outObj, &data_ov031_0224c748, buf2) != 0 &&
        func_ov031_02240074(outObj, &data_ov031_0224c750, buf3) != 0) {
        ((struct Container0223f264*)outContainer)->field4 = 2;
        ((struct Container0223f264*)outContainer)->field10 = p0;
        ((struct Container0223f264*)outContainer)->field1c = buf2;
        ((struct Container0223f264*)outContainer)->field20 = buf3;
        ((struct Container0223f264*)outContainer)->field14 = (void*)p2;
        ((struct Container0223f264*)outContainer)->field18 = buf1;
        int r = func_ov031_0223f188(outContainer, (struct Obj02240df4*)outObj);
        if (r != 0) return 1;
        data_ov031_02290dc0(buf3);
        data_ov031_02290dc0(buf2);
        data_ov031_02290dc0(buf1);
        return 0;
    }
    data_ov031_02290dc0(buf3);
    data_ov031_02290dc0(buf2);
    data_ov031_02290dc0(buf1);
    CleanupAndNotify_0223edb4(outContainer, (struct Obj02240df4*)outObj);
    data_ov031_02290dbc = 1;
    return 0;
}
