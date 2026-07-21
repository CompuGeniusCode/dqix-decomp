#include <globaldefs.h>

struct Entry02218f18 {
	int a;
	int b;
};

typedef void (*Notify02218f18)(void*, int, int);

extern int data_ov031_02249fd8;
extern int data_ov031_02249ff4;

// USA: func_ov031_02218f18
extern "C" ARM void func_ov031_02218f18(void* obj, struct Entry02218f18* arr, int count) {
	Notify02218f18 fn = *(Notify02218f18*)((char*)obj + 0x1014);
	int i = 0;
	if (count <= 0) return;

	void* p0 = &data_ov031_02249fd8;
	void* p1 = &data_ov031_02249ff4;
	do {
		int va = arr[i].a;
		if (va != 0) {
			fn(p0, va, 0);
			arr[i].a = 0;
		}
		int vb = arr[i].b;
		if (vb != 0) {
			fn(p1, vb, 0);
			arr[i].b = 0;
		}
		i++;
	} while (i < count);
}
