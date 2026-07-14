#include <globaldefs.h>

struct FormatObj0202f760 {
    char pad0[0x33];
    unsigned char field33;
};

extern const char* data_020ef8a4[];
extern char data_020ef908;
extern char data_020ef90f;
extern "C" int sprintf(char* dst, const char* fmt, ...);

// USA: func_0202f760
ARM int FormatPathWithTableEntry_0202f760(struct FormatObj0202f760* obj, char* dst) {
    sprintf(dst, &data_020ef908, &data_020ef90f,
                  data_020ef8a4[obj->field33], obj);
    return 1;
}
