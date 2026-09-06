#include <globaldefs.h>

void* GetData02153637(void);
struct Container020e34bc;
int GetEntryStatusForKey020e34bc(struct Container020e34bc* obj, int key);
void Dispatch020e3428(void* a, int b);
void ClearFields0to5_0218d7fc(unsigned char* obj);
struct Entry020e3054;
void ClearEntryIfCurrentArrMatches020e3468(struct Entry020e3054* list, int key);
void SetName56AndFlag_0218d7b0(unsigned char* obj, char* name);

extern "C" void func_ov017_0218d2f0(int a, int b, int c, int d);

// USA: func_ov017_0218d818
ARM void ProcessEntry56_0218d818(unsigned char* obj) {
	if (obj[0x4000 + 0x35b] != 1) return;
	void* ctx = GetData02153637();
	int status = GetEntryStatusForKey020e34bc((struct Container020e34bc*)ctx, 1);
	if (status == 1) {
		func_ov017_0218d2f0(obj[0x4356], obj[0x4357], *(unsigned short*)(obj + 0x4358), obj[0x435a]);
		Dispatch020e3428(ctx, 1);
		ClearFields0to5_0218d7fc(obj + 0x4356);
	} else if ((unsigned int)(status - 3) <= 2) {
		ClearEntryIfCurrentArrMatches020e3468((struct Entry020e3054*)ctx, 1);
		unsigned short buf[3];
		buf[0] = *(unsigned short*)(obj + 0x4356);
		buf[1] = *(unsigned short*)(obj + 0x4358);
		buf[2] = *(unsigned short*)(obj + 0x435a);
		SetName56AndFlag_0218d7b0(obj, (char*)buf);
	}
}
