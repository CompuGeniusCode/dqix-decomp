#include <globaldefs.h>
#include "std_library_functions.h"

int StringLength(const char* s);

// USA: func_ov000_0217aa08
ARM void TrimTrailingLetterCode_0217aa08(char* src, char* dst) {
    if (src == NULL || dst == NULL) return;
    if (src[0] == 0) return;
    sprintf(dst, src);
    int len = StringLength(dst);
    if (len <= 0) return;
    if (dst[len - 1] < 'A') return;
    if (dst[len - 1] > 'Q') return;
    dst[len - 1] = 0;
    if (dst[len - 2] == ' ') dst[len - 2] = 0;
}
