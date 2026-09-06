#include <globaldefs.h>

struct Word3_020ca568 { unsigned int a, b, c; };
struct Word4_020ca568 { unsigned int a, b, c, d; };

// USA: func_020ca568
ARM void CopyBlock64_020ca568(const Word3_020ca568* src3, Word3_020ca568* dst3) {
    *dst3++ = *src3++;
    *dst3++ = *src3++;
    *dst3++ = *src3++;
    *dst3++ = *src3++;
    const Word4_020ca568* src4 = (const Word4_020ca568*)src3;
    Word4_020ca568* dst4 = (Word4_020ca568*)dst3;
    *dst4 = *src4;
}
