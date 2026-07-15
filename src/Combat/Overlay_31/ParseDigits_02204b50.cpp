#include <globaldefs.h>

// USA: func_ov031_02204b50
ARM int ParseDigits_02204b50(char* str, char** endptr) {
    *endptr = str;
    unsigned int result = 0;
    unsigned int digit;
    do {
        digit = ((unsigned char)*str - 0x30) & 0xff;
        if (digit > 9) break;
        result = result * 10 + digit;
        str++;
        *endptr = str;
    } while (1);
    return result;
}
