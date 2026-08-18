#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" int func_ov025_021eb0f4(int a);
extern int data_ov025_021ef988;

// USA: func_ov025_021e413c  (semantic: Func_021e413c)
extern "C" ARM int func_ov025_021e413c(void) {
    if (((BackgroundLoader*)((unsigned char*)(int)BackgroundLoader::GetInstance()))->GetFlag0() == 0) {
        return 0;
    }
    return func_ov025_021eb0f4(*(int*)((char*)&data_ov025_021ef988 + 0xc));
}
