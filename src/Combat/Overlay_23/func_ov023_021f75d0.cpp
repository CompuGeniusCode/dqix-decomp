#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* func_ov011_021849c8(void* ctx);
int GetData02104304Field4();
extern "C" int func_ov023_021f6bb8(void* obj);
extern "C" void func_ov023_021f6bb0(void* obj, int v);
int CallFunc0202fa38Mode2(int a, int b, int c, int d);
int CallFunc0202fa38ZeroPad(int a, int b, int c);

extern char data_ov023_021fe5ec;

struct Obj021f75d0 {
    char pad0[0x10];
    char* field10;
    char pad1[8];
    int field1c;
    char pad2[4];
    char* field24;
};

// USA: func_ov023_021f75d0
extern "C" ARM int func_ov023_021f75d0(struct Obj021f75d0* obj, void* ctx) {
    void* node = func_ov011_021849c8(ctx);
    if (obj->field10 == 0) return 1;
    int key = func_ov023_021f6bb8(node);
    if (key < 0) {
        int listPtr = GetData02104304Field4();
        char buf[0x50];
        int result;
        if (obj->field24 != 0) {
            sprintf(buf, &data_ov023_021fe5ec, obj->field24);
        } else {
            sprintf(buf, &data_ov023_021fe5ec, obj->field10);
        }
        if (obj->field24 != 0) {
            result = CallFunc0202fa38Mode2(listPtr, (int)buf, (int)obj->field10, 0);
        } else {
            result = CallFunc0202fa38ZeroPad(listPtr, (int)buf, 0);
        }
        func_ov023_021f6bb0(node, result);
        return 1;
    }
    return obj->field1c;
}
