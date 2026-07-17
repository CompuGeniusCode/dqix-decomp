#include <globaldefs.h>

extern int data_ov031_02245ff4[];
int DispatchOnZeroPair_0220cdd4(int a, int b, int v);

// USA: func_ov031_022151b0
ARM int DispatchClampedTable_022151b0(int a, int b, int count, int flags) {
	if (count > 0xc) count = 0xc;
	return DispatchOnZeroPair_0220cdd4(a, b, data_ov031_02245ff4[count] | flags);
}
