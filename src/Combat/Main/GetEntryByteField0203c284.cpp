#include <globaldefs.h>

extern void* data_02105244;

struct Entry0203c284 {
    char pad[0x21];
    unsigned char field21;
    char pad2[6];
};

// USA: func_0203c284
ARM unsigned char GetEntryByteField0203c284(char* obj) {
    char* data = (char*)data_02105244;
    if (data == NULL) return 0;
    {
        struct Entry0203c284* arr = (struct Entry0203c284*)(data + 4);
        short idx = *(short*)(obj + 0x14);
        if (idx < 0) return 0;
        return arr[idx].field21;
    }
}
