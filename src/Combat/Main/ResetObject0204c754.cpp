#include <globaldefs.h>

extern "C" void func_0204acd0(void*);
extern "C" void func_0204c684(void*);

struct Obj0204c754 {
    char pad0[0xc8];
    char fieldc8;
};

// USA: func_0204c754
ARM void ResetObject0204c754(struct Obj0204c754* obj) {
    func_0204acd0(&obj->fieldc8);
    func_0204c684(obj);
}
