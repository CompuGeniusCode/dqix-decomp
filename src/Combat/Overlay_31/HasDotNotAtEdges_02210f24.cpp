#include <globaldefs.h>

int StringLength(const char* s);

// USA: func_ov031_02210f24
ARM int HasDotNotAtEdges_02210f24(const char* s) {
	if (s == NULL) goto fail;
	{
		int len = StringLength(s);
		if (len <= 2) goto fail;
		if (len > 0x40) goto fail;
		int last = len - 1;
		if (last <= 1) goto fail;
		int i = 1;
		do {
			if (s[i] == '.') return 1;
			i++;
		} while (i < last);
	}
fail:
	return 0;
}
