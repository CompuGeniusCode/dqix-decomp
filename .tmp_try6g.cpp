#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov006_021547c8(void*);
ARM int GetData02104304Field4();
extern "C" void func_020301c8(int);
extern "C" void* func_ov006_02153730(void*);
extern "C" void* func_020421a0(void*);

// USA: func_ov006_02157cc0
ARM void CleanupCombatEntry_02157cc0(char* obj) {
	if (*(void**)(obj + 0x10) != NULL) {
		func_ov006_021547c8(*(void**)(obj + 0x10));
		*(void**)(obj + 0x10) = NULL;
	}
	{
		int val = GetData02104304Field4();
		if (*(int*)(obj + 0x354) >= 0) {
			func_020301c8(val);
			*(int*)(obj + 0x354) = -1;
		}
		if (*(int*)(obj + 0x358) >= 0) {
			func_020301c8(val);
			*(int*)(obj + 0x358) = -1;
		}
	}
	{
		void* p = func_ov006_02153730(obj + 0x74);
		void* q = func_020421a0(p);
		*(int*)((char*)q + 0x2d8) = 0;
	}
	if (*(void**)(obj + 0xc) != NULL) {
		SafeAllocator* arr = *(SafeAllocator**)(obj + 0xc);
		unsigned char i;
		for (i = 0; i < 10; i++) {
			if (arr[i].GetSignedAllocator() != NULL) {
				arr[i].Destroy();
			}
		}
	}
}
