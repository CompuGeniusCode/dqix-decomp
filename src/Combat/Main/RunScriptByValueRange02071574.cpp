#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


int LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);

struct StreamHeader;
struct Obj02071488;
int RunScriptAndAdjustObj02071488(struct StreamHeader* buffer, int length, int assetId, struct Obj02071488* obj);

extern char data_020f0c24;
extern char data_020f0c45;
extern char data_020f0c5e;
extern char data_0211e33c;

// USA: func_02071574
ARM struct Obj02071488* RunScriptByValueRange02071574(unsigned int value, struct Obj02071488* obj) {
    unsigned int length;

    BackgroundLoader::AddLockGlobal();

    if (value >= 0x5208 && value < 0x9c40) {
        if (LoadFileIntoMemory(&data_020f0c24, &data_0211e33c, &length) &&
            RunScriptAndAdjustObj02071488((struct StreamHeader*)&data_0211e33c, length, value, obj)) {
            BackgroundLoader::RemoveLockGlobal();
            return obj;
        }
    } else if (value >= 0x9c40) {
        if (LoadFileIntoMemory(&data_020f0c45, &data_0211e33c, &length) &&
            RunScriptAndAdjustObj02071488((struct StreamHeader*)&data_0211e33c, length, value, obj)) {
            BackgroundLoader::RemoveLockGlobal();
            return obj;
        }
    } else {
        if (LoadFileIntoMemory(&data_020f0c5e, &data_0211e33c, &length) &&
            RunScriptAndAdjustObj02071488((struct StreamHeader*)&data_0211e33c, length, value, obj)) {
            BackgroundLoader::RemoveLockGlobal();
            return obj;
        }
    }

    BackgroundLoader::RemoveLockGlobal();
    return NULL;
}
