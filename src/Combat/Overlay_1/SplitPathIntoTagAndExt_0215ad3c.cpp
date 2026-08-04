#include <globaldefs.h>
#include "std_library_functions.h"

extern const char data_ov001_021656f4[];
extern const char data_ov001_021656fd[];
extern const char data_ov001_02165706[];
extern const char data_ov001_0216570d[];
extern const char data_ov001_02165728[];
extern const char data_ov001_0216572d[];

// USA: func_ov001_0215ad3c  (semantic: SplitPathIntoTagAndExt_0215ad3c)
extern "C" ARM int func_ov001_0215ad3c(char* path, char* outTag, char* outExt) {
    char* p = strstr(path, data_ov001_021656f4);
    if (p == NULL) {
        strstr(path, data_ov001_021656fd);
    }
    if (p != NULL) {
        strcpy(outTag, p + strlen(data_ov001_02165706));
        strcpy(outExt, data_ov001_0216570d);
        return 1;
    }
    if (strstr(path, data_ov001_02165728) != NULL) {
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
        strcpy(outExt, data_ov001_0216572d);
        return 1;
    }
    return 0;
}
