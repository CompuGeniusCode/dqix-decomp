#include <globaldefs.h>

struct Field4Struct022415e0 {
	int unk0;
	int field4;
};

void CopyMemory_022415c8(void* dst, const void* src, unsigned int length);
extern "C" int func_ov031_022414cc(Field4Struct022415e0* obj, int b, int c, int d, int e);
extern char data_ov031_02291a04[0x400];

// USA: func_ov031_022415e0
extern "C" ARM int func_ov031_022415e0(Field4Struct022415e0* a, int b, int* pos, char* buf, int count) {
	int remaining = count;
	if (remaining > 0) {
		int flag = 0;
		do {
			if (a->field4 != 0) {
				return -1;
			}

			int p = *pos;
			int room = 0x400 - p;
			int chunk = (remaining <= room) ? remaining : room;
			CopyMemory_022415c8(data_ov031_02291a04 + p, buf, chunk);

			p = *pos;
			buf += chunk;
			p += chunk;
			*pos = p;
			remaining -= chunk;

			if (p == 0x400) {
				int result = func_ov031_022414cc(a, b, (int)data_ov031_02291a04, 0x400, flag);
				if (result <= 0) {
					return result;
				}
				*pos = *pos - result;
			}
		} while (remaining > 0);
	}

	return count;
}
