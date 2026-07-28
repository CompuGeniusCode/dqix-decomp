#include <globaldefs.h>

extern "C" int func_ov024_021fe698(char* obj, int idx);
extern "C" int func_ov024_021fdf04(void* obj, int idx);
extern "C" int func_ov024_021fd954(void* obj, int idx);

struct Bits8_021fbdb4 { unsigned int low8 : 8; unsigned int mid2 : 2; };

// USA: func_ov024_021fbdb4  (semantic: DispatchByMid2BitfieldSetFlags_021fbdb4)
extern "C" ARM int func_ov024_021fbdb4(void* obj) {
	void* p = *(void**)((char*)obj + 0x64c);
	struct Bits8_021fbdb4* bf = (struct Bits8_021fbdb4*)((char*)p + 8);
	int r;
	if (bf->mid2 == 1) {
		r = func_ov024_021fe698((char*)obj, 2);
		if (!r) {
			return r;
		}
		r = func_ov024_021fe698((char*)obj, 0xe);
		if (!r) {
			return r;
		}
		return func_ov024_021fdf04(obj, 0x12);
	} else {
		r = func_ov024_021fe698((char*)obj, 3);
		if (!r) {
			return r;
		}
		r = func_ov024_021fe698((char*)obj, 6);
		if (!r) {
			return r;
		}
		return func_ov024_021fd954(obj, 0x12);
	}
}
