#include <globaldefs.h>
#include "std_library_functions.h"

extern const char strCharaP[];
extern const char strCharaP_021656fd[];
extern const char strChara_02165706[];
extern const char strDataPackLv5CharaPcGp2[];
extern const char strMon[];
extern const char strDataPackLv5EnemyGp2_0216572d[];

// Works out which data/pack_lv5 archive a model path lives in and what it is called inside it: a path
// containing "chara/p_" comes from chara_pc.gp2 under the member name starting at the "p_", six
// characters in, and one carrying ".mon" comes from enemy.gp2 under its bare file name.
// func_ov001_0215ec94 feeds both outputs to BackgroundLoader::QueueLoadFileInGP2 and falls back to
// loading "data/<path>" when this returns 0. The second strstr result is discarded, so the backslash
// spelling "chara\p_" can never match. That is how the ROM was built, not a decompilation artefact.
extern "C" ARM int ResolvePackLv5ArchiveForPath(char* path, char* outTag, char* outExt) {
    char* p = strstr(path, strCharaP);
    if (p == NULL) {
        strstr(path, strCharaP_021656fd);
    }
    if (p != NULL) {
        strcpy(outTag, p + strlen(strChara_02165706));
        strcpy(outExt, strDataPackLv5CharaPcGp2);
        return 1;
    }
    if (strstr(path, strMon) != NULL) {
        char* slash = strrchr(path, '/');
        if (!slash) {
            slash = strrchr(path, '\\');
        }
        if (slash) {
            slash = slash + 1;
        } else {
            slash = path;
        }
        strcpy(outTag, slash);
        strcpy(outExt, strDataPackLv5EnemyGp2_0216572d);
        return 1;
    }
    return 0;
}
