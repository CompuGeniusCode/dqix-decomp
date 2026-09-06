#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Variant02030b0c {
    int tag;
    union { int i; float f; } u;
};
extern "C" int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

struct Struct02030b7c {
    int field0;
    void* field4;
};
extern "C" void* GetField4IfField0Zero(struct Struct02030b7c* s);

extern "C" int StringLength(const char* s);

struct ScriptState_021d83cc {
    char* str0;
    char* str1;
    char* str2;
    unsigned short* arr;
    unsigned short field10;
    short field12;
    unsigned char field14;
    unsigned char field15;
    unsigned char field16;
    unsigned char field17;
};

struct Data_021d83cc {
    SafeAllocator* allocator;
    volatile int field4;
};
extern struct Data_021d83cc data_ov017_021d83cc;

// USA: func_ov017_021aca2c
ARM int InitScriptArgs_021aca2c(struct Variant02030b0c* args, int count) {
    char* text;
    int len;
    int i;
    int v;

    if (GetIntFromVariant02030b0c(&args[0]) != ((struct ScriptState_021d83cc*)data_ov017_021d83cc.field4)->field10) {
        return 1;
    }
    v = GetIntFromVariant02030b0c(&args[1]);
    if (v != ((struct ScriptState_021d83cc*)data_ov017_021d83cc.field4)->field12) {
        return 1;
    }
    if (v < 0) {
        return 1;
    }

    ((struct ScriptState_021d83cc*)data_ov017_021d83cc.field4)->field14 = (unsigned char)GetIntFromVariant02030b0c(&args[2]);
    ((struct ScriptState_021d83cc*)data_ov017_021d83cc.field4)->field15 = (unsigned char)GetIntFromVariant02030b0c(&args[3]);

    text = (char*)GetField4IfField0Zero((struct Struct02030b7c*)&args[4]);
    if (text) {
        len = StringLength(text);
        if (len) {
            ((struct ScriptState_021d83cc*)data_ov017_021d83cc.field4)->str0 = (char*)data_ov017_021d83cc.allocator->Allocate(len + 1);
            memset(((struct ScriptState_021d83cc*)data_ov017_021d83cc.field4)->str0, 0, len + 1);
            memcpy(((struct ScriptState_021d83cc*)data_ov017_021d83cc.field4)->str0, text, len);
            ((struct ScriptState_021d83cc*)data_ov017_021d83cc.field4)->str0[len] = 0;
        }
    }

    text = (char*)GetField4IfField0Zero((struct Struct02030b7c*)&args[5]);
    if (text) {
        len = StringLength(text);
        if (len) {
            ((struct ScriptState_021d83cc*)data_ov017_021d83cc.field4)->str1 = (char*)data_ov017_021d83cc.allocator->Allocate(len + 1);
            memset(((struct ScriptState_021d83cc*)data_ov017_021d83cc.field4)->str1, 0, len + 1);
            memcpy(((struct ScriptState_021d83cc*)data_ov017_021d83cc.field4)->str1, text, len);
            ((struct ScriptState_021d83cc*)data_ov017_021d83cc.field4)->str1[len] = 0;
        }
    }

    {
        struct Variant02030b0c* arg6 = &args[6];
        args += 7;
        text = (char*)GetField4IfField0Zero((struct Struct02030b7c*)arg6);
    }
    if (text) {
        len = StringLength(text);
        if (len) {
            ((struct ScriptState_021d83cc*)data_ov017_021d83cc.field4)->str2 = (char*)data_ov017_021d83cc.allocator->Allocate(len + 1);
            memset(((struct ScriptState_021d83cc*)data_ov017_021d83cc.field4)->str2, 0, len + 1);
            memcpy(((struct ScriptState_021d83cc*)data_ov017_021d83cc.field4)->str2, text, len);
            ((struct ScriptState_021d83cc*)data_ov017_021d83cc.field4)->str2[len] = 0;
        }
    }

    if (count - 7 != 0) {
        ((struct ScriptState_021d83cc*)data_ov017_021d83cc.field4)->field16 = (unsigned char)(count - 7);
        ((struct ScriptState_021d83cc*)data_ov017_021d83cc.field4)->arr = (unsigned short*)data_ov017_021d83cc.allocator->Allocate((count - 7) * 2);
        for (i = 0; i < count - 7; i++) {
            ((struct ScriptState_021d83cc*)data_ov017_021d83cc.field4)->arr[i] = (unsigned short)GetIntFromVariant02030b0c(args);
            args++;
        }
    }

    ((struct ScriptState_021d83cc*)data_ov017_021d83cc.field4)->field17 = 1;
    return 0;
}
