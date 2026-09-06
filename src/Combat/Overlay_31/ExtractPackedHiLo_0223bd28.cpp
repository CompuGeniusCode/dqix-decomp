#include <globaldefs.h>

struct Elem_0223bd28 { unsigned int packed; unsigned int pad; };
struct Header_0223bd28 { unsigned char pad[8]; struct Elem_0223bd28* arr; };

// USA: func_ov031_0223bd28
ARM void ExtractPackedHiLo_0223bd28(struct Header_0223bd28* h, int index, unsigned int* outHi, unsigned int* outLo) {
	struct Elem_0223bd28* arr = h->arr;
	*outHi = (arr[index].packed & 0x1ff0000) >> 16;
	*outLo = arr[index].packed & 0xff;
}
