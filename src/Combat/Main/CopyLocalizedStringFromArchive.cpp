#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" int func_020e0574(void* path, int* outSize, int unused, int gp2Path);
extern "C" int func_020e046c(int dest, int fileData, int fileSize, int index);

// Copies one string out of a localized string file into the caller's buffer. func_020e0574 replaces
// path's .bin extension with .nat, which is what makes this the localized read, and then either
// loads that file into the scratch buffer at data_0211e33c or, when gp2Path is given, extracts it
// from that GP2 archive; func_020e046c walks the loaded data and strcpys the entry at index into
// dest, leaving dest empty and returning 0 when there is no such entry. The lock is
// BackgroundLoader's global one, held only across the load, so a caller already holding it passes 0.
// The fourth argument reaches func_020e0574 and is never read there, so what it was for is not
// established.
extern "C" ARM int CopyLocalizedStringFromArchive(int dest, void* path, int index, int unused, unsigned char lockBackgroundLoader, int gp2Path) {
    int fileSize;
    int result;
    int fileData;

    if (dest == 0 || path == NULL || index < 0) {
        return 0;
    }
    if (lockBackgroundLoader != 0) {
        BackgroundLoader::AddLockGlobal();
    }
    fileData = func_020e0574(path, &fileSize, unused, gp2Path);
    result = func_020e046c(dest, fileData, fileSize, index);
    if (lockBackgroundLoader != 0) {
        BackgroundLoader::RemoveLockGlobal();
    }
    return result;
}
