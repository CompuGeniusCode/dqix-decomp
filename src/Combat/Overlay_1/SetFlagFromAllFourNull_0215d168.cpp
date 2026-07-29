#include <globaldefs.h>

struct FourWords02158ab8;
int AllFourPtrFieldsAreNull_02158ab8(struct FourWords02158ab8* obj);
extern "C" void func_ov017_021d6134(void*, int);

struct DataOv001_0215d168 { char pad[0x24]; struct FourWords02158ab8* p; };
extern struct DataOv001_0215d168 data_ov001_02165880;

// USA: func_ov001_0215d168  (semantic: SetFlagFromAllFourNull_0215d168)
extern "C" ARM int func_ov001_0215d168(void* obj) {
    int r = AllFourPtrFieldsAreNull_02158ab8(data_ov001_02165880.p);
    func_ov017_021d6134(obj, r == 0 ? 1 : 0);
    return 1;
}
