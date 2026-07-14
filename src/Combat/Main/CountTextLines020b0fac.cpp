#include <globaldefs.h>

struct TextMeasurer020b0fac {
    void* field0;
    int (*getChar)(const char** cursor);
};

struct ReaderContext020b0fac {
    int reserved0;
    int reserved1;
    const char* cursor;
};

// USA: func_020b0fac
ARM int CountTextLines020b0fac(struct TextMeasurer020b0fac* obj, int width, const char* text) {
    struct ReaderContext020b0fac ctx;
    int* zeroFields = (int*)&ctx;
    ctx.cursor = text;
    zeroFields[0] = 0;
    zeroFields[1] = 0;

    int lineCount = 1;
    int (*getChar)(const char**) = obj->getChar;
    int ch = getChar(&ctx.cursor);
    if (ch != 0) {
        do {
            if (ch == 0xa) lineCount++;
            ch = getChar(&ctx.cursor);
        } while (ch != 0);
    }

    signed char extra = ((signed char*)obj->field0)[1];
    return lineCount * (width + extra) - width;
}
