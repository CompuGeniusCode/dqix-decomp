#include <globaldefs.h>
#include "std_library_functions.h"

int GetData02104304Field4();
extern "C" int func_ov001_0215ad3c(void*, void*, void*);
int CallFunc0202fa38Mode2(int a, int b, int c, int d);
int CallFunc0202fa38ZeroPad(int a, int b, int c);

extern const char data_ov001_02165745[];
extern int data_ov001_021658e0[];
struct Count88_ec94 { char pad[0x88]; int count; };
extern Count88_ec94 data_ov001_021658b8;

// USA: func_ov001_0215ec94
extern "C" void func_ov001_0215ec94(void* self, int idx) {
    int data4 = GetData02104304Field4();
    char buf2[0x50];
    char buf0[0x50];
    if (func_ov001_0215ad3c(self, buf2, buf0) != 0) {
        data_ov001_021658e0[idx] = CallFunc0202fa38Mode2(data4, (int)buf0, (int)buf2, 0);
    } else {
        sprintf(buf2, data_ov001_02165745, self);
        data_ov001_021658e0[idx] = CallFunc0202fa38ZeroPad(data4, (int)buf2, 0);
    }
    data_ov001_021658b8.count++;
}
