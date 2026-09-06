#include <globaldefs.h>

ARM int GetData02104304Field4();
extern "C" void func_020301c8(int);
extern "C" void func_ov006_0215479c(void*);
extern "C" void* func_0203bd08(void);
extern "C" void* func_0203be40(void);

// USA: func_ov006_02156e54
ARM void InitCombatEntries_02156e54(char* obj) {
	int val = GetData02104304Field4();
	char* entry = obj + 0x894;
	unsigned char i;
	for (i = 0; i < 4;) {
		int t3;
		void* ptr14;
		int t2;
		int t1;
		unsigned char newI;
		if (*(int*)(entry + 0x70) > 0) {
			func_020301c8(val);
		}
		*(int*)(entry + 0x70) = -1;
		func_ov006_0215479c(entry);
		*(unsigned char*)(entry + 0x5e) = 0;
		func_0203bd08();
		t3 = i * 0x120;
		ptr14 = (char*)func_0203be40() + (i << 6) + 0x100;
		t2 = i + 0xa;
		t1 = i << 5;
		newI = i + 1;
		*(void**)(entry + 0x14) = ptr14;
		*(int*)(entry + 0x38) = t3 + 0x240;
		*(int*)(entry + 0x3c) = t2 & 0xf;
		*(int*)(entry + 0x40) = 0;
		*(short*)(entry + 0x76) = t1 + 0x20;
		*(short*)(entry + 0x78) = 0x80;
		entry += 0x7c;
		i = newI;
	}
}
