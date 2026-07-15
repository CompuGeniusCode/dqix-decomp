#include <globaldefs.h>

struct Ctx021e2628 { char pad[0x1c]; unsigned int flags; };
extern struct Ctx021e2628 data_ov025_021ef988;

int GetData02104304Field4();
void AddEntryOrOverflow(unsigned char* obj);
int CallFunc0202fa38Mode2(int a, int b, int c, int d);

// USA: func_ov025_021e2628
ARM int SetFlagAndDispatch_021e2628(int a, int b) {
    int r = GetData02104304Field4();
    if (!(data_ov025_021ef988.flags & 0x2000)) {
        AddEntryOrOverflow((unsigned char*)r);
        data_ov025_021ef988.flags |= 0x2000;
    }
    return CallFunc0202fa38Mode2(r, a, b, 0);
}
