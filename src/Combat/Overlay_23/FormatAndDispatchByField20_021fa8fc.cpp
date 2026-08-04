#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* func_ov011_021849c8(int a);
extern "C" int func_ov023_021f6bb8(void* thing);
extern "C" void func_ov023_021f6bb0(void* thing, int v);
int GetData02104304Field4();
int CallFunc0202fa38Mode2(int a, int b, int c, int d);
int CallFunc0202fa38ZeroPad(int a, int b, int c);
extern char data_ov023_021fec3c;

// USA: func_ov023_021fa8fc  (semantic: FormatAndDispatchByField20_021fa8fc)
extern "C" ARM int func_ov023_021fa8fc(void* obj, int a) {
    void* thing = func_ov011_021849c8(a);
    int state = func_ov023_021f6bb8(thing);
    if (state < 0) {
        int val5 = GetData02104304Field4();
        char buf[0x50];
        if (*(int*)((char*)obj + 0x20) != 0) {
            sprintf(buf, &data_ov023_021fec3c, *(int*)((char*)obj + 0x20));
        } else {
            sprintf(buf, &data_ov023_021fec3c, *(int*)((char*)obj + 0x10));
        }
        int result;
        if (*(int*)((char*)obj + 0x20) != 0) {
            result = CallFunc0202fa38Mode2(val5, (int)buf, *(int*)((char*)obj + 0x10), 0);
        } else {
            result = CallFunc0202fa38ZeroPad(val5, (int)buf, 0);
        }
        func_ov023_021f6bb0(thing, result);
        return 1;
    }
    return *(int*)((char*)obj + 0x1c);
}
