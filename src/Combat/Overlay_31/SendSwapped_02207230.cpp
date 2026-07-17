#include <globaldefs.h>

extern "C" void func_ov031_0220572c(void* ctx, unsigned short a, unsigned int b);

struct Packet02207230 {
	char pad0[2];
	unsigned short half;
	unsigned int word;
};

// USA: func_ov031_02207230
ARM void SendSwapped_02207230(void* ctx, Packet02207230* pkt) {
	unsigned short h = pkt->half;
	unsigned int w = pkt->word;
	unsigned short hs = (unsigned short)(((h >> 8) & 0xff) | ((h << 8) & 0xff00));
	unsigned int ws = ((w >> 24) & 0xff) | ((w >> 8) & 0xff00) | ((w << 8) & 0xff0000) | ((w << 24) & 0xff000000);
	func_ov031_0220572c(ctx, hs, ws);
}
