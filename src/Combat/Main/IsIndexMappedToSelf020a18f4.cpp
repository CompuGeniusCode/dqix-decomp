#include <globaldefs.h>

extern int data_01ffd348;
extern signed char data_01ffd364;

struct Entry020e8f20 {
    int col;
    int pad;
};
extern struct Entry020e8f20 data_020e8f20[];

// USA: func_020a18f4
ARM int IsIndexMappedToSelf020a18f4(unsigned int idx) {
    int result = 0;
    if (idx < 0x23) {
        signed char* row = &data_01ffd364 + data_01ffd348 * 6;
        result = ((int)idx == row[data_020e8f20[idx].col]);
    }
    return result;
}
