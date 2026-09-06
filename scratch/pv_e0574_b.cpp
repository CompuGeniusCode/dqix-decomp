#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int ReplaceBinExtensionWithNat020e05f8(char* dst, const char* fmt);
extern "C" void* LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outSize);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);

extern char data_0211e33c[];

// USA: func_020e0574
ARM void* GetFileDataMaybeGp020e0574(const char* path, unsigned int* outSize, void* unused, const char* gp2Path) {
    char buf[0x40];
    void* result;
    if (path == 0) return 0;
    *outSize = 0;
    ReplaceBinExtensionWithNat020e05f8(buf, path);
    if (gp2Path == 0) {
        LoadFileIntoMemory(buf, data_0211e33c, outSize);
        if (*outSize != 0) return data_0211e33c;
    } else {
        result = ExtractFileFromGP2(gp2Path, buf, outSize);
        if (result != 0) return result;
    }
    return 0;
}
