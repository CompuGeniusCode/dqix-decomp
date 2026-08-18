#include <globaldefs.h>
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"

extern "C" int func_ov001_0215ad3c(char* path, char* outTag, char* outExt);
extern const char data_ov001_02165745[];

extern int data_ov001_021658e0[];

struct S021658b8 {
    char pad[0x88];
    int counter;
};
extern S021658b8 data_ov001_021658b8;

// USA: func_ov001_0215ec94  (semantic: QueueTaskForPathOrFormatted_0215ec94)
extern "C" ARM void func_ov001_0215ec94(char* path, int index) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    char tag[0x50];
    char ext[0x50];
    if (func_ov001_0215ad3c(path, tag, ext) != 0) {
        data_ov001_021658e0[index] = loader->QueueLoadFileInGP2(ext, tag, NULL);
    } else {
        sprintf(tag, data_ov001_02165745, path);
        data_ov001_021658e0[index] = loader->QueueLoadFile(tag, NULL);
    }
    data_ov001_021658b8.counter += 1;
}
