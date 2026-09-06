#include <globaldefs.h>

extern "C" void* func_ov023_021e1bac(void* a, int b, int c, int d);

// USA: func_ov023_021e1b0c
ARM void BuildChain_021e1b0c(void* a, int b, int c, int d) {
	void* node = func_ov023_021e1bac(a, b, c, d);
	if (node == 0) return;
	*(void**)a = node;
	while (node != 0) {
		void* next = func_ov023_021e1bac(a, b, c, d);
		*(void**)node = next;
		node = next;
	}
}
