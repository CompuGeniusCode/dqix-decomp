#include <globaldefs.h>
#include "std_library_functions.h"

struct Variant02030b0c {
    int tag;
    union { int i; float f; } u;
};
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

struct Struct02030b7c {
    int field0;
    void* field4;
};
void* GetField4IfField0Zero(struct Struct02030b7c* s);

int StringLength(const char* s);

struct MsgArgs02071044 {
    struct Variant02030b0c v0;
    struct Variant02030b0c v1;
    struct Variant02030b0c v2;
    struct Variant02030b0c v3;
    struct Variant02030b0c v4;
    struct Variant02030b0c v5;
    struct Variant02030b0c v6;
    struct Struct02030b7c v7;
};

struct MsgEntry02071044 {
    int id;
    char text[0x1e];
    char flag1;
    char flag2;
};

struct MsgQueueState02071044 {
    unsigned char forceFlag;          // 0x0
    char pad1[7];
    struct MsgEntry02071044* entries; // 0x8
    char pad2[4];
    int limit;                        // 0x10
    char pad3[8];
    int targetValue;                  // 0x1c
    char pad4[4];
    int count;                        // 0x24
};
extern struct MsgQueueState02071044 data_02108d70;

// USA: func_02071044  (semantic: AddMessageLogEntry02071044)
extern "C" ARM int func_02071044(struct MsgArgs02071044* args) {
    int v0;
    int key;
    int i;
    void* text;
    int len;

    if (data_02108d70.limit <= data_02108d70.count) {
        return 0;
    }

    v0 = GetIntFromVariant02030b0c(&args->v0);
    GetIntFromVariant02030b0c(&args->v1);

    if (v0 == data_02108d70.targetValue || data_02108d70.forceFlag != 0) {
        GetIntFromVariant02030b0c(&args->v2);
        GetIntFromVariant02030b0c(&args->v3);
        GetIntFromVariant02030b0c(&args->v4);
        key = GetIntFromVariant02030b0c(&args->v5);

        for (i = 0; i < data_02108d70.count; i++) {
            if (data_02108d70.entries[i].id == key) {
                if (key < 0x5208 || key >= 0x9c40) {
                    return 0;
                }
            }
        }

        data_02108d70.entries[data_02108d70.count].id = key;

        GetIntFromVariant02030b0c(&args->v6);
        text = GetField4IfField0Zero(&args->v7);
        if (!text) {
            return 0;
        }

        memset(data_02108d70.entries[data_02108d70.count].text, 0, 0x20);

        len = StringLength((const char*)text);
        if (len < 0x1f) {
            memcpy(data_02108d70.entries[data_02108d70.count].text, text, len);
        } else {
            memcpy(data_02108d70.entries[data_02108d70.count].text, text, 0x1e);
            data_02108d70.entries[data_02108d70.count].flag1 = 0;
        }

        data_02108d70.entries[data_02108d70.count].flag2 = 0;
        data_02108d70.count++;
    }

    return 1;
}
