#include <globaldefs.h>

struct DataOv001_0215ab20 { char pad[0x1c]; char* base; };
extern struct DataOv001_0215ab20 data_ov001_02165880;

// USA: func_ov001_0215ab20
ARM int GetTableEntryPtr_0215ab20(int index) {
    if (index < 0 || index >= 0x18) return 0;
    return (int)(data_ov001_02165880.base + index * 0x588);
}
