#include <globaldefs.h>

struct FreeIface02207620 {
    void* unk0;
    void (*free)(void*, void*, unsigned int);
};

extern FreeIface02207620 data_ov031_0224e234;

// USA: func_ov031_02207620
ARM void FreeWithSizeHeader_02207620(void* ptr) {
    if (ptr != NULL) {
        unsigned int header = *((unsigned int*)ptr - 1);
        data_ov031_0224e234.free(0, (unsigned int*)ptr - 1, header);
    }
}
