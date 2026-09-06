#include <globaldefs.h>
#include "std_library_functions.h"
struct S { char* namePtr; char pad4[8]; int fieldC; int field10; int field14; };
extern S data_ov031_02249b54;
extern char data_ov031_02249bb8[];
struct Glob { char pad[8]; char* base; };
extern Glob data_ov031_0224e5e8;
extern "C" int callee(void* p);
ARM int PragmaTest(void) {
    if (strcmp(data_ov031_02249b54.namePtr, data_ov031_02249bb8) != 0) {
        data_ov031_02249b54.field14 = 1;
    }
    data_ov031_02249b54.fieldC = *(int*)(data_ov031_0224e5e8.base + 0x1000 + 0x20c);
    data_ov031_02249b54.field10 = *(int*)(data_ov031_0224e5e8.base + 0x1000 + 0x210);
    return callee(*(void**)(data_ov031_0224e5e8.base + 0x1000 + 0x314));
}
