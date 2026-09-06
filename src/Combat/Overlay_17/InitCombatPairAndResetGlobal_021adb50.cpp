#include <globaldefs.h>

struct ResetObj020d7a5c;
struct ResetObj020d7a5c* GetGlobalResetObj020d7a50();
struct Obj020d7aa0;
void TeardownAndResetState020d7aa0(struct Obj020d7aa0* obj);
int GetGlobalField0x1c020421a0(void);
void ReinitController02043204(char* obj);
void InitBigStruct0205c790(char* obj);

struct Struct_0205ba68;
void SetupPointerTable0205ba68(struct Struct_0205ba68* s, int a, int b, int mode);
struct Node0205bacc;
void SetField0AndPropagate0205bacc(struct Node0205bacc* s, int val);
int CallFunc020e0434With02153694(int value);
void ProcessCombatEntry0205cb74(char* obj, int value);
extern "C" void func_0205cc50(void* obj, int a, int b);
struct ResetBytesAndSetByte0x16Data;
void ResetBytesAndSetByte0x16(struct ResetBytesAndSetByte0x16Data* p, int val);
void SetupGlobalObjType1AndInitSelfPointer(unsigned char* obj);

// USA: func_ov017_021adb50
ARM void InitCombatPairAndResetGlobal_021adb50(char* self) {
    TeardownAndResetState020d7aa0((struct Obj020d7aa0*)GetGlobalResetObj020d7a50());
    ReinitController02043204((char*)GetGlobalField0x1c020421a0());
    InitBigStruct0205c790(self + 0x44);
    SetupPointerTable0205ba68((struct Struct_0205ba68*)(self + 0x64), 1, 1, 0);
    SetupPointerTable0205ba68((struct Struct_0205ba68*)(self + 0xb4), 1, 1, 0);
    SetField0AndPropagate0205bacc((struct Node0205bacc*)(self + 0x64), 1);
    SetField0AndPropagate0205bacc((struct Node0205bacc*)(self + 0xb4), 1);
    int val = CallFunc020e0434With02153694(0x1f);
    ProcessCombatEntry0205cb74(self + 0x44, val);
    *(short*)(self + 0xf8) = 8;
    *(short*)(self + 0xfa) = 0x40;
    func_0205cc50(self + 0x44, 0, -4);
    self[0x278] = 1;
    ResetBytesAndSetByte0x16((struct ResetBytesAndSetByte0x16Data*)(self + 0x48), 1);
    self[0x277] = 1;
    self[0x278] = 1;
    ResetBytesAndSetByte0x16((struct ResetBytesAndSetByte0x16Data*)(self + 0x48), 1);
    short v = *(short*)(self + 0xfc);
    *(short*)(self + 0xf8) = (0x100 - v) / 2;
    *(short*)(self + 0xfa) = 0x40;
    SetupGlobalObjType1AndInitSelfPointer((unsigned char*)(self + 0x44));
}
