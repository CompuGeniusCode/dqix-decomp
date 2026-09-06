#include <globaldefs.h>

struct RangeHolder020b0e6c;
struct Holder020b0eb4;
struct ParamA020b1d70;

struct Elem0223c8d4 { void* p0; unsigned short f2; unsigned short pad; };

extern char* data_ov031_02290d38;

int FindValueInRangeList(RangeHolder020b0e6c* obj, unsigned int key);
void* LookupRangeEntry020b0eb4(Holder020b0eb4** slot, unsigned int key);
int DispatchRangeDeltaCallback_0223c898(ParamA020b1d70* paramA, int accA, int accB, int paramE, unsigned short paramF, int index);

#pragma optimize_for_size off
// USA: func_ov031_0223c8d4
extern "C" ARM void func_ov031_0223c8d4(ParamA020b1d70* a, int b, int c, int d, int e, unsigned short* counts, int idx) {
	if (counts[0] == 0) return;
	do {
		Elem0223c8d4* elem = (Elem0223c8d4*)(data_ov031_02290d38 + idx * 8);
		unsigned int found = FindValueInRangeList((RangeHolder020b0e6c*)elem, counts[0]);
		unsigned int val = found;
		if (found == 0xffff) {
			val = *(unsigned short*)((char*)elem->p0 + 2);
		}
		void* entry = LookupRangeEntry020b0eb4((Holder020b0eb4**)elem, val);
		unsigned short cnt = counts[0];
		signed char f2 = *((signed char*)entry + 2);
		int offset = b + ((e - f2) >> 1);
		DispatchRangeDeltaCallback_0223c898(a, offset, c, d, cnt, idx);
		counts++;
		b += e;
	} while (*counts != 0);
}
