#include <globaldefs.h>

extern "C" int func_ov031_022056bc(void*, unsigned short);

struct Packet02207204 {
	unsigned short pad0;
	unsigned short field2;
};

// USA: func_ov031_02207204
ARM int SwapField2AndForward02207204(void* obj, struct Packet02207204* pkt) {
	unsigned int v = pkt->field2;
	unsigned int hi = ((int)v >> 8) & 0xff;
	unsigned int lo = (v << 8) & 0xff00;
	unsigned short swapped = (unsigned short)(hi | lo);
	return func_ov031_022056bc(obj, swapped);
}
