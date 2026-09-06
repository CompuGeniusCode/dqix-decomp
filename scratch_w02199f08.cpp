#include <globaldefs.h>

struct BattleStruct;
struct CombatantStruct;
struct BitField0203402c;
struct Obj020397cc;
struct Entry_02199684;
struct List0204b0e8;
struct FlagWord02046708;

extern "C" int IsField0Null(void** obj);
struct BattleStruct* GetBattleStruct();
struct CombatantStruct* GetCombatantAtField0x3ac(struct BattleStruct* battleStruct);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
void* GetPtrField0x2a04(struct BattleStruct* battleStruct);
int GetIntField0x260(void* obj);
int CheckField0xc4Low15BitsNonZero(struct BitField0203402c* p);
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
unsigned char GetByteField0x252(void* obj);
int CheckSubstructByte0x7cPositive(signed char* obj);
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);
void* GetDataPtr02114e04_020d6c00(void);
void OrBitsIntoField0(unsigned int* p, unsigned int mask);
extern "C" void func_ov017_021a5bac(void* obj);
void InitFieldArenaListsAndCounters_021996fc(unsigned char* base, int b);
int TestFlagInSecondWord(unsigned short* obj, unsigned int mask);
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
void FillEntriesEncoded_02199684(Entry_02199684* arr, int count, int value);
extern "C" void func_0204bc74(void* entry, int a, int b, int c, int d, int e, int f);
void FlushAndDispatchList0204b0e8(struct List0204b0e8* obj, void* buf);
void ClearAndEncodeEntries_021996bc(Entry_02199684* arr, int count);
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);
extern "C" void func_ov017_021999fc(void);
int TestFlagMask(unsigned short* obj, int mask);
void CancelActionIfHeadIdMatches_02199e98(void* obj);

extern unsigned short data_02114e30;

// USA: func_ov017_02199f08
extern "C" ARM void func_ov017_02199f08(void* obj) {
	if (!IsField0Null((void**)((char*)obj + 0x3000 + 0x6fc))) {
		CancelActionIfHeadIdMatches_02199e98(obj);
		return;
	}

	struct BattleStruct* bs = GetBattleStruct();
	GetCombatantAtField0x3ac(bs);
	struct CombatantStruct* c1 = GetCombatantAtField0x397c(bs);
	void* c2 = GetPtrField0x2a04(bs);
	int v = GetIntField0x260(c1);

	if (v == -1 && !(CheckField0xc4Low15BitsNonZero((struct BitField0203402c*)c1) || *(int*)((char*)obj + 0x4000 + 0x80) != 0)) {
		if (!TestFlag0SetAndFlag1Clear(&data_02114e30, 2)) return;
		if (GetByteField0x252(c1) == 0) return;
		if (*(int*)((char*)c1 + 0x18c) & 1) return;
		if (CheckSubstructByte0x7cPositive((signed char*)c1) != 0 || *(short*)((char*)c1 + 0xac) != 0) return;
		CancelPendingAction020397cc((struct Obj020397cc*)c1, 1);
		*(short*)((char*)c1 + 0xb2) = 0;
		OrBitsIntoField0((unsigned int*)GetDataPtr02114e04_020d6c00(), 0x400);
		func_ov017_021a5bac(obj);

		volatile unsigned short* hw = (volatile unsigned short*)0x0400000a;
		short a = hw[0];
		*(short*)*(int*)((char*)obj + 0x3000 + 0xca8) = a;
		int aWide = a;
		short b = hw[1];
		*(short*)*(int*)((char*)obj + 0x3000 + 0xcac) = b;
		int bWide = b;
		(void)aWide;
		InitFieldArenaListsAndCounters_021996fc((unsigned char*)obj, bWide);
		*(int*)((char*)obj + 0x4000 + 0x80) = 1;
		return;
	}

	if (TestFlagInSecondWord(&data_02114e30, 2) || *(short*)((char*)c1 + 0xac) != 0 || CheckField0xc4Low15BitsNonZero((struct BitField0203402c*)c1)) {
		CancelActionIfHeadIdMatches_02199e98(obj);
		return;
	}

	if (v != -1) {
		for (int i = 0; i < *((unsigned char*)c2 + 0xf7c); i++) {
			unsigned char idx = *((unsigned char*)c2 + i + 0xf78);
			struct CombatantStruct* cc = GetCombatantWithFlag0x800(bs, idx);
			*(short*)((char*)cc + 0xac) = 0;
		}
	}

	if (TestFlags02046708((struct FlagWord02046708*)GetDataPtr02114e04_020d6c00(), 4)) {
		CancelActionIfHeadIdMatches_02199e98(obj);
		return;
	}
	func_ov017_021999fc();

	if (!TestFlagMask(&data_02114e30, 2) || v == -1) return;

	Entry_02199684* arr = (Entry_02199684*)((char*)obj + 0xb4 + 0x3c00);
	FillEntriesEncoded_02199684(arr, 2, 0x800);

	for (int i = 0; i < 2; i++) {
		void* entry = (char*)arr + i * 0x20;
		func_0204bc74(entry, 0, 0, 0, 0x20, 0x19, 0);
		FlushAndDispatchList0204b0e8((struct List0204b0e8*)entry, 0);
	}
	ClearAndEncodeEntries_021996bc(arr, 2);
}
