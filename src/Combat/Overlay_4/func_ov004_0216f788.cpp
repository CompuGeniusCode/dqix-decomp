#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

extern "C" void func_ov011_021848a0(void* obj, int val);
int GetGlobalField0x1c020421a0(void);

struct Struct02171048_0216f788 { char pad[0x4]; unsigned char* ptr; };
extern Struct02171048_0216f788 data_ov004_02171048;

// USA: func_ov004_0216f788  (semantic: CopyAndCheckFlags_0216f788)
extern "C" ARM int func_ov004_0216f788(void* obj) {
    char* p = (char*)GetBattleStruct() + 0x2380 + 0x4000;
    char buf[0x40];
    memcpy(buf, p + 4, 0x40);
    if (data_ov004_02171048.ptr[0x32] == 0) {
        func_ov011_021848a0(obj, 0x65);
        data_ov004_02171048.ptr[0x31] = 1;
    } else if (data_ov004_02171048.ptr[0x33] == 0) {
        func_ov011_021848a0(obj, 0x66);
        *(int*)((char*)GetGlobalField0x1c020421a0() + 0x2c8) = 1;
    } else {
        func_ov011_021848a0(obj, 0xc8);
    }
    return 0;
}
