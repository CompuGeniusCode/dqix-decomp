#include <globaldefs.h>

class Node021f698c {
public:
    virtual void Dummy0();
    virtual void Method();
    char pad[0x14];
    Node021f698c* next;
};
struct ListHead021f698c { Node021f698c* first; };

// USA: func_ov023_021f698c  (semantic: CallVTableFnAt4Loop_021f698c)
extern "C" ARM void func_ov023_021f698c(struct ListHead021f698c* head) {
    Node021f698c* node = head->first;
    while (node != NULL) {
        node->Method();
        node = node->next;
    }
}
