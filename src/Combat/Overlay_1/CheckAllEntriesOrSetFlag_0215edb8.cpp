#include <globaldefs.h>

extern int GetData02104304Field4();
extern "C" int func_0202fdd0(int a, int b);
extern "C" void func_ov017_021d6134(void*, unsigned int);

extern int data_ov001_021658e0[];
struct Count88_edb8 { char pad[0x88]; int count; };
extern Count88_edb8 data_ov001_021658b8;

// USA: func_ov001_0215edb8
ARM int CheckAllEntriesOrSetFlag_0215edb8(void* self) {
    int table = GetData02104304Field4();
    int i;
    for (i = 0; i < data_ov001_021658b8.count; i++) {
        if (func_0202fdd0(table, data_ov001_021658e0[i]) == 0) {
            func_ov017_021d6134(self, 1);
            return 1;
        }
    }
    func_ov017_021d6134(self, 0);
    return 1;
}
