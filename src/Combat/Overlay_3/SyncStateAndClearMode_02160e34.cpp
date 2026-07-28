#include <globaldefs.h>

void* GetDataPtr02114e04_020d6c00(void);
extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_0203b19c(int, int, int);
int CheckField0x20Positive(int* obj);
extern "C" void func_ov003_02167370(void* obj);
struct FlagWord020466f4;
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);
void SetCombatModeFromCase020dc2d0(int);

struct Self02160e34 {
	char pad0[0x318];
	void* field318; // 0x318
	char pad31c[0x464 - 0x31c];
	int field464; // 0x464
	char pad468[0x4a8 - 0x468];
	unsigned char field4a8; // 0x4a8
};

// USA: func_ov003_02160e34  (semantic: SyncStateAndClearMode_02160e34)
extern "C" ARM int func_ov003_02160e34(struct Self02160e34* self) {
	int result = 0;
	void* dataPtr = GetDataPtr02114e04_020d6c00();
	int w = func_ov017_0218b5b0();
	unsigned char state = self->field4a8;

	if (state == 0) {
		func_0203b19c(w, -16, 8);
		self->field4a8 = self->field4a8 + 1;
		goto end;
	}
	if (state != 1) {
		goto end;
	}
	if (CheckField0x20Positive((int*)w) != 0) {
		goto end;
	}

	func_ov003_02167370(self->field318);
	self->field4a8 = 0;
	result = 1;
	ClearFlags020466f4((struct FlagWord020466f4*)dataPtr, 0x41);
	SetCombatModeFromCase020dc2d0(0);
	self->field464 &= ~0x800;
end:
	return result;
}
