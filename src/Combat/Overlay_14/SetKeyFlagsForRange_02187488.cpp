#include <globaldefs.h>

struct BufferField8_02097418;
struct Field4Low12_02097420;
void* GetBufferField8(struct BufferField8_02097418* obj);
int GetField4Low12(struct Field4Low12_02097420* obj);

struct ObjStruct_02187450;
struct KeyStruct_02187450;
int* GetArrayEntryByField1a_02187450(struct ObjStruct_02187450* obj, struct KeyStruct_02187450* key);

struct ValueLow10_02187488 {
    unsigned int low10 : 10;
};

// USA: func_ov014_02187488  (semantic: SetKeyFlagsForRange_02187488)
extern "C" ARM void func_ov014_02187488(struct ObjStruct_02187450* obj) {
    unsigned char* base = (unsigned char*)GetBufferField8((struct BufferField8_02097418*)((char*)obj + 0xa4));
    unsigned short count = (unsigned short)GetField4Low12((struct Field4Low12_02097420*)((char*)obj + 0xa4));
    unsigned short i = 0;
    while (i < count) {
        unsigned char* entry = base + i * 0x20;
        int* v = GetArrayEntryByField1a_02187450(obj, (struct KeyStruct_02187450*)entry);
        if (v != 0) {
            if (((struct ValueLow10_02187488*)v)->low10) {
                entry[0x13] |= 2;
            }
        }
        i++;
    }
}
