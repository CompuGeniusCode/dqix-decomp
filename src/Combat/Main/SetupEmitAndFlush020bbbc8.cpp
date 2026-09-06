#include <globaldefs.h>
extern "C" void LoadToSubObjExtendedPalette(int, unsigned int, int);

extern "C" void MemoryMapSubObjExtendedPalette(void);
extern "C" void MemoryUnmapSubObjExtendedPalette(void);

// USA: func_020bbbc8
ARM void SetupEmitAndFlush020bbbc8(int a, int b, int c) {
    MemoryMapSubObjExtendedPalette();
    LoadToSubObjExtendedPalette((int)(a), (unsigned int)(b), (int)(c));
    MemoryUnmapSubObjExtendedPalette();
}
