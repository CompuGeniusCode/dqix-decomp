#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" int func_ov017_0218b5b0(void);
int GetField4334_021bdbc0(unsigned char* base);
extern "C" int func_ov017_021bdbcc(void*);
extern "C" void _Z23ClearFlag0x1InField0x6cPh(void*);
extern "C" void _Z15SetFlag0x6cBit0Ph(void*);

// USA: func_ov001_02162174
ARM int SetOrClearFlag6cForFields_02162174(void* self, int mode) {
	int flagWord = func_ov017_021d60f4(self);
	if (mode >= 2) {
		mode = func_ov017_021d60f4((char*)self + 0x8);
	} else {
		mode = 0;
	}
	unsigned char* base = (unsigned char*)func_ov017_0218b5b0();
	if (mode == 0 || (mode & 1)) {
		int f1 = GetField4334_021bdbc0(base);
		if (f1 != 0) {
			if (flagWord != 0) _Z23ClearFlag0x1InField0x6cPh((void*)f1);
			else _Z15SetFlag0x6cBit0Ph((void*)f1);
		}
	}
	if (mode & 2) {
		int f2 = func_ov017_021bdbcc(base);
		if (f2 != 0) {
			if (flagWord != 0) _Z23ClearFlag0x1InField0x6cPh((void*)f2);
			else _Z15SetFlag0x6cBit0Ph((void*)f2);
		}
	}
	return 1;
}
