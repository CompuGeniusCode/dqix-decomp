#include <globaldefs.h>

struct Packet02207230;
int SendSwapped_02207230(void* ctx, Packet02207230* pkt);

struct Packet02241404 {
	char pad0[2];
	unsigned short half;
	unsigned int word;
};

struct Ctx02241404 { char pad[4]; int flag; };

// USA: func_ov031_02241404  (semantic: SendPacketOrError_02241404)
#pragma optimize_for_size off
extern "C" ARM int func_ov031_02241404(Ctx02241404* self, void* ctx, unsigned int word, unsigned int rawHalf) {
	Packet02241404 pkt;
	pkt.pad0[0] = 8;
	pkt.pad0[1] = 2;
	unsigned short v = (unsigned short)rawHalf;
	pkt.half = (unsigned short)(((v >> 8) & 0xff) | ((v << 8) & 0xff00));
	pkt.word = word;
	int r = SendSwapped_02207230(ctx, (Packet02207230*)&pkt);
	if (r < 0) {
		if (self->flag != 0) return (int)0xfffffc16;
		return ~0x3e8;
	}
	return 0;
}
