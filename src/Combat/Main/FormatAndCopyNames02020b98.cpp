#include <globaldefs.h>
#include "std_library_functions.h"

int GetData02104304Field4();
extern "C" void* func_02012fe4(void);
int CallFunc0202fa38Mode2(int a, int b, int c, int d);
extern int data_020ef460;
extern char data_020ef587;
extern char data_020ef58f;

// USA: func_02020b98
ARM int FormatAndCopyNames02020b98(void* r6) {
    char buf[0x20];
    int val5 = GetData02104304Field4();
    char* ptr4 = (char*)func_02012fe4();
    sprintf(buf, &data_020ef587, (void*)(ptr4 + 0x26));
    int result = CallFunc0202fa38Mode2(val5, *(int*)((char*)&data_020ef460 + 8), (int)buf, 0);
    strcpy((char*)r6 + 0xa35, ptr4 + 0x26);
    strcpy((char*)r6 + 0x548, &data_020ef58f);
    return result;
}
