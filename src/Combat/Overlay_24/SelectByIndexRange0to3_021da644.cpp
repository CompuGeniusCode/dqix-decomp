#include <globaldefs.h>

// USA: func_ov024_021da644
ARM unsigned short SelectByIndexRange0to3_021da644(int idx, int a, int b) {
	int inRange = (idx >= 0 && idx <= 3);
	return inRange ? (unsigned short)a : (unsigned short)b;
}
