#include <globaldefs.h>

struct S02195760 { char pad[0x41c]; unsigned char* p; };

// USA: func_ov017_02195760  (semantic: IsFieldByteZero_02195760)
extern "C" ARM int func_ov017_02195760(unsigned char* base) {
	S02195760* s = (S02195760*)(base + 0x4000);
	return s->p[0] == 0;
}
