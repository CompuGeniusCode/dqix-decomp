#include <globaldefs.h>

void* FindNodeById02057f8c(void* list, int id);
extern "C" void func_02057fd8(void* a1, void* node, int a3);

// USA: func_02057fb4
ARM void FindNodeAndProcess02057fb4(void* list, int id, int a3) {
    void* node = FindNodeById02057f8c(list, id);
    func_02057fd8(list, node, a3);
}
