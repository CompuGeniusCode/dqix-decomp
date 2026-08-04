#include <globaldefs.h>

extern "C" void func_ov017_02195214(void* dst, void* src);

// USA: func_ov017_02195398  (semantic: RemoveEntryByKey_02195398)
extern "C" ARM void func_ov017_02195398(void* obj, unsigned char key) {
	unsigned char* o = (unsigned char*)obj;
	int i = 0;
	while (i < o[0x42f0]) {
		unsigned char* p = o + i * 15;
		p = p + 0x4000;
		if (key == p[0x2f1]) {
			unsigned char* hdr = o + 0x4000;
			hdr[0x2f0] = hdr[0x2f0] - 1;
			while (i < hdr[0x2f0]) {
				func_ov017_02195214(o + 0x42f1 + i * 15, o + 0x42f1 + (i + 1) * 15);
				i++;
			}
			return;
		}
		i++;
	}
}
