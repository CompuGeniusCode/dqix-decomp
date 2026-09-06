#include <globaldefs.h>

struct Struct02222eb0_arr {
	int arr[1];
	unsigned char pad[19];
	unsigned char type;
};
extern Struct02222eb0_arr* data_ov031_02250ba8;

extern "C" void func_ov031_0223bbd8(void* a, int b, int c, int d);
extern unsigned char data_ov031_02248940[];
extern unsigned char data_ov031_02248932[];
extern unsigned short data_ov031_0224891c[];

// USA: func_ov031_02222eb0  (semantic: DispatchAllEntries_02222eb0)
extern "C" ARM void func_ov031_02222eb0(void* obj) {
	Struct02222eb0_arr* p = data_ov031_02250ba8;
	int count = data_ov031_02248940[p->type];
	func_ov031_0223bbd8((void*)p->arr[2], -1, 0, (int)obj);
	int i = 0;
	if (count <= 0) return;
	int negOne = -1;
	do {
		p = data_ov031_02250ba8;
		void* item = (void*)((int*)p)[i];
		unsigned char itemType = p->type;
		unsigned char* row = data_ov031_02248932 + itemType * 2;
		unsigned char idx = row[i];
		unsigned short val = data_ov031_0224891c[idx * 2];
		func_ov031_0223bbd8(item, negOne, val, (int)obj + 4);
		i++;
	} while (i < count);
}
