#include <globaldefs.h>

struct AddEntryList_021f6a1c;
void AddEntryIfUnderLimit16_021f6a1c(struct AddEntryList_021f6a1c* obj, void* src);

struct Inner12_021fd088 { unsigned int w[3]; };

// USA: func_ov024_021fd088  (semantic: AddScaledPercentEntry_021fd088)
extern "C" ARM void func_ov024_021fd088(void* obj, float pct, int a2) {
	char* base = (char*)obj;
	struct Inner12_021fd088 local = *(struct Inner12_021fd088*)(base + 0x65c);
	short v = *(short*)(*(char**)(base + 0x64c) + 0x32);
	*(float*)&local.w[0] = (float)v;
	unsigned char pctBase = ((unsigned char*)&local)[7];
	((unsigned char*)&local)[4] = (unsigned char)a2;
	int scaled = (int)((float)pctBase * pct / 100.0f);
	((unsigned char*)&local)[8] = 5;
	((unsigned char*)&local)[7] = (unsigned char)scaled;
	AddEntryIfUnderLimit16_021f6a1c((struct AddEntryList_021f6a1c*)*(void**)(base + 0x658), &local);
}
