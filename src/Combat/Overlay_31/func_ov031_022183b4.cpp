#include <globaldefs.h>

extern "C" void* VectorizedMemset(void* dst, int val, int n);

struct Entry02218f18;
extern "C" void func_ov031_02218f18(void* obj, Entry02218f18* arr, int count);
void ClearBufferAndNotify_022187fc(int obj, void* buf);

extern int data_ov031_02249e2c;
extern int data_ov031_02249e44;

typedef void (*Notify022183b4)(void*, int, int);

// USA: func_ov031_022183b4
extern "C" ARM void func_ov031_022183b4(void* objv) {
	char* obj = (char*)objv;
	Notify022183b4 fn = *(Notify022183b4*)(obj + 0x1014);
	if (objv == 0) return;

	func_ov031_02218f18(obj, (Entry02218f18*)(obj + 0x1a38), 0x20);
	ClearBufferAndNotify_022187fc((int)obj, obj + 0x1a08);
	ClearBufferAndNotify_022187fc((int)obj, obj + 0x19f8);

	int v0 = *(int*)(obj + 0x19cc);
	if (v0 != 0) {
		fn(&data_ov031_02249e2c, v0, 0);
		*(int*)(obj + 0x19cc) = 0;
	}

	int v1 = *(int*)(obj + 0x19d0);
	if (v1 != 0) {
		fn(&data_ov031_02249e44, v1, 0);
		*(int*)(obj + 0x19d0) = 0;
	}

	VectorizedMemset(obj, 0, 0x1c14);
}
