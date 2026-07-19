#include <globaldefs.h>

struct GlobalStruct0224e5ac {
	void* field0;
	void* field4;
};

extern GlobalStruct0224e5ac data_ov031_0224e5ac;

void* SubtractOffset20_02211b20(void*);

typedef void (*Callback02211b98)(void*, void*, int);

// USA: func_ov031_02211b98  (semantic: InvokeStoredCallback_02211b98)
extern "C" ARM void func_ov031_02211b98(void* a, void* b) {
	if (b == NULL) return;
	void* obj = SubtractOffset20_02211b20(b);
	int off = *(int*)((char*)obj + 4) + 0x20;
	Callback02211b98 fn = (Callback02211b98)data_ov031_0224e5ac.field0;
	fn(a, obj, off);
}
