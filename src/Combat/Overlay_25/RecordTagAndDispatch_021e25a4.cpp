#include <globaldefs.h>

int GetData02104304Field4();
void AddEntryOrOverflow(unsigned char* obj);
int FindTagAndCopy_021e24d0(char* s, char* out2, char* out1);
int CallFunc0202fa38Mode2(int a, int b, int c, int d);
void CallFunc0202fa38ZeroPad(int a, int b, int c);

struct Struct021ef988 { char pad[0x1c]; unsigned int flags; };
extern Struct021ef988 data_ov025_021ef988;

// USA: func_ov025_021e25a4  (semantic: RecordTagAndDispatch_021e25a4)
extern "C" ARM void func_ov025_021e25a4(char* s) {
    char buf2[0x50];
    char buf1[0x50];
    int d = GetData02104304Field4();
    if (!(data_ov025_021ef988.flags & 0x2000)) {
        AddEntryOrOverflow((unsigned char*)d);
        data_ov025_021ef988.flags |= 0x2000;
    }
    if (FindTagAndCopy_021e24d0(s, buf2, buf1)) {
        CallFunc0202fa38Mode2(d, (int)buf2, (int)buf1, 0);
    } else {
        CallFunc0202fa38ZeroPad(d, (int)s, 0);
    }
}
