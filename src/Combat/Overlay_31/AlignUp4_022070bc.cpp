#include <globaldefs.h>

// USA: func_ov031_022070bc
ARM unsigned int AlignUp4_022070bc(unsigned int x) {
	return (x + 3) & ~3;
}
