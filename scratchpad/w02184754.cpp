#include <globaldefs.h>

struct BattleStruct;
struct BattleStruct* GetBattleStruct();
unsigned int GetBattleScaleCount(struct BattleStruct* battleStruct);

extern "C" void func_ov008_02188ef0(void* obj);
extern "C" void func_0205d0e0(void* obj, int count);
extern "C" void func_ov008_02186e4c(void* obj, int count);
extern "C" void func_02034d20(void* obj);
struct Obj021870e4;
void ClearFlagIfDone_021870e4_021870e4(struct Obj021870e4* obj, int count);
extern "C" void func_ov008_0218747c(void* obj, int flag);
struct TaskState0209ff6c;
ARM void PollOv017Task0209ff6c(TaskState0209ff6c* obj);
extern "C" void func_ov023_021eb43c(void* obj);

struct DispatchObj021847c4 { virtual void Run(int); };
typedef void (DispatchObj021847c4::*PMF021847c4)(int);
struct RawTable021847c4 { PMF021847c4 e[15]; };
extern struct RawTable021847c4 data_ov008_0218b340;
extern PMF021847c4 data_020e6d5c;

// USA: func_ov008_02184754
extern "C" ARM int func_ov008_02184754(char* obj) {
    func_ov008_02188ef0(obj);
    unsigned int count = GetBattleScaleCount(GetBattleStruct());
    if (count == 0) count = 1;
    func_0205d0e0(obj + 0x130, count);
    func_ov008_02186e4c(obj, count);
    func_02034d20(obj + 0x790);
    ClearFlagIfDone_021870e4_021870e4((struct Obj021870e4*)obj, count);
    func_ov008_0218747c(obj, 0);
    func_ov008_0218747c(obj, 1);

    struct RawTable021847c4 table;
    table = data_ov008_0218b340;
    table.e[14] = data_020e6d5c;

    signed char idx = *(signed char*)(obj + 0xb10);
    if (table.e[idx] == 0) {
        return 0;
    }
    (((DispatchObj021847c4*)obj)->*table.e[idx])(count);

    void* taskPtr = *(void**)(obj + 0xb04);
    if (taskPtr) {
        PollOv017Task0209ff6c((TaskState0209ff6c*)taskPtr);
    }
    void* p2 = *(void**)(obj + 0xb08);
    if (p2) {
        func_ov023_021eb43c(p2);
    }

    return *(signed char*)(obj + 0xb10) == 0xe;
}
