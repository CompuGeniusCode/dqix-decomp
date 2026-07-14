#include <globaldefs.h>
#include "std_library_functions.h"
int GetGlobalField0x1c020421a0(void);
extern "C" void func_02046608(int, int, void*, int, int, int, int);
// USA: func_02098f70
void AppendFormattedData02098f70(int* cursor, void* data, int size, int advance) {
    char** cur = (char**)cursor;
    int base = GetGlobalField0x1c020421a0();
    memcpy(*cur, (void*)size, advance);
    *cur += advance;
    func_02046608(base, 0xc, data, *(int*)cur, 0xe3, 0, 1);
    *cur += strlen(*cur);
}
