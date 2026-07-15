#include <globaldefs.h>

// USA: func_ov000_0215fe84
ARM void AppendToChainAndIncCount0215fe84(void* obj, void* node, int idx) {
	void** slot = (void**)((char*)obj + idx * 4);
	while (*slot != 0) {
		slot = (void**)((char*)(*slot) + 0x20);
	}
	*slot = node;
	{
		unsigned char* cnt = (unsigned char*)obj + 0x26;
		cnt[idx]++;
	}
}
