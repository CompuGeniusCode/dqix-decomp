#include <globaldefs.h>

extern int data_02102be0;
extern int data_02101980;
int TestFlagBitsAndDispatch020d6884(int, unsigned short*, int);

// USA: func_0202dcb4
ARM int TestDefaultFlagBits(int arg) {
    return TestFlagBitsAndDispatch020d6884((int)&data_02102be0, (unsigned short*)&data_02101980, arg);
}
