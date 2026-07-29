#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* func_ov017_021d612c(void* obj);
int GetData02104304Field4();
struct SearchObj0202ff34;
int FindTableEntryByFormattedName(SearchObj0202ff34*, char*, int*, int*);
void ShiftInBitOnGlobalObject(void);
void HalveGlobalObjectCounter(void);
unsigned int LoadResourceIntoGlobalBuffer_0215a750(const char* path, void** outPtr);
extern "C" void func_ov001_021537b0(void* p0, int p1, int p2, int p3);

extern const char data_ov001_02165745[];

struct Global021658b8 {
    int field0;
    char pad[0x8c - 0x4];
    unsigned char field8c;
};
extern Global021658b8 data_ov001_021658b8;
extern int data_ov001_021658d8;

// USA: func_ov001_0215e1cc  (semantic: DispatchAndLoadTableResource_0215e1cc)
extern "C" ARM int func_ov001_0215e1cc(void* param0) {
    char buf[0x28];
    int out1;
    int out2;
    int flag;

    sprintf(buf, data_ov001_02165745, func_ov017_021d612c(param0));
    flag = 0;
    FindTableEntryByFormattedName((SearchObj0202ff34*)GetData02104304Field4(), buf, &out1, &out2);
    if (out1 == 0) {
        ShiftInBitOnGlobalObject();
        flag = 1;
        if (LoadResourceIntoGlobalBuffer_0215a750(buf, (void**)&out1) == 0) {
            HalveGlobalObjectCounter();
            return 0;
        }
    }
    func_ov001_021537b0(&data_ov001_021658d8, data_ov001_021658b8.field0, out1, out2);
    if (flag != 0) {
        HalveGlobalObjectCounter();
    }
    data_ov001_021658b8.field8c = 0;
    return 1;
}
