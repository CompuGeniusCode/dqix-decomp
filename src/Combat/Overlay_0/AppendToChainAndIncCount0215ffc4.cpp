#include <globaldefs.h>

// USA: func_ov000_0215ffc4
ARM void AppendToChainAndIncCount0215ffc4(void* obj, void* node, int idx) {
	void** slot = (void**)((char*)obj + idx * 4);
	while (*slot != 0) {
		slot = (void**)((char*)(*slot) + 0x20);
	}
	*slot = node;
	{
		unsigned char* cnt = (unsigned char*)obj + 0x18;
		cnt[idx]++;
	}
}
