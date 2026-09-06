#include <globaldefs.h>

extern "C" int func_02001aec(void*, int, int);

// USA: func_ov012_02185634
ARM int AnyMatchInRange_02185634(void *unused, void *p1, int p2, int p3, int count) {
	int i = 0;
	while (i < count) {
		if (func_02001aec(p1, p2, p3) == 0) {
			return 1;
		}
		i++;
		p2++;
	}
	return 0;
}
