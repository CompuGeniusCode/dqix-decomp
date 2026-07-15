#include <globaldefs.h>

struct Words021e60c4 { unsigned int a, b, c; };
void SetWords_021e60c4_021e60c4(void* obj, struct Words021e60c4* src);

// USA: func_ov023_021e6088
ARM void SetFourWordBlocks_021e6088(void* obj, struct Words021e60c4* src) {
    SetWords_021e60c4_021e60c4(obj, src);
    SetWords_021e60c4_021e60c4((char*)obj + 0x408, src);
    SetWords_021e60c4_021e60c4((char*)obj + 0xac, src);
    SetWords_021e60c4_021e60c4((char*)obj + 0x35c, src);
}
