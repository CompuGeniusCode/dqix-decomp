#include <globaldefs.h>

struct ClearThreeWords02094d00Struct;
struct InitState0208f7ecStruct;
class ActiveGrottoClass {
public:
    void BlankFunction2() const;
};
class FloorMap {
public:
    void Clear2();
};

void ResetBigStruct02013750(void* p, int n);
void ClearThreeWords02094d00(ClearThreeWords02094d00Struct* p);
void InitState0208f7ec(InitState0208f7ecStruct* p);
extern "C" void _Z21BlankFunction020984acv(void* p);
void NotifyThenResetNameTable(void* p);
extern "C" void _ZN7Model3DD1Ev(void* p);
void Init0207b98c(char* p);
extern "C" void _ZN12ZoneFeatures5ResetEv(void* p);

extern "C" void func_0200ef44(void* p, int count, int size, void* fn);

// USA: func_0201c124  (semantic: ResetAllSubsystems_0201c124)
extern "C" ARM void* func_0201c124(void* self) {
    ResetBigStruct02013750(self, 1);
    ClearThreeWords02094d00((ClearThreeWords02094d00Struct*)((char*)self + 0x2724));
    InitState0208f7ec((InitState0208f7ecStruct*)((char*)self + 0x2664));
    ((ActiveGrottoClass*)((char*)self + 0x23ec))->BlankFunction2();
    ((FloorMap*)((char*)self + 0x25b4))->Clear2();
    _Z21BlankFunction020984acv((char*)self + 0x840);
    func_0200ef44((char*)self + 0x600, 4, 0x88, (void*)NotifyThenResetNameTable);
    func_0200ef44((char*)self + 0x498, 2, 0xac, (void*)_ZN7Model3DD1Ev);
    Init0207b98c((char*)self + 0x10c);
    _ZN12ZoneFeatures5ResetEv((char*)self + 0x6c);
    return self;
}
