#include <globaldefs.h>

unsigned long long GetFields04AsPacked64_0221170c(unsigned int* p);
long long GetPair_02212d20(void);

// USA: func_ov031_02211608
ARM int CompareField10PairOrZero_02211608(void* obj) {
	unsigned long long a = GetFields04AsPacked64_0221170c((unsigned int*)((char*)obj + 0x10));
	if (a == 0) return 1;
	unsigned long long b = (unsigned long long)GetPair_02212d20();
	return a == b;
}
