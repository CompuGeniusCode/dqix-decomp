#include <globaldefs.h>

struct Buffer02188ba0 {
	int unused0;
	int unused4;
	int unused8;
	int unusedc;
	char* buf;
};

// USA: func_ov014_02188ba0
extern "C" ARM char* func_ov014_02188ba0(struct Buffer02188ba0* s, char* key, char* fallback) {
	int missing = 1;
	int offset = (int)(key - (char*)0);
	if (offset != -1 && s->buf != NULL) {
		missing = 0;
	}
	if (missing == 0) {
		fallback = s->buf + offset;
	}
	return fallback;
}
