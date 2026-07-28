#include <globaldefs.h>

class Node021f69bc {
public:
    virtual void Dummy0();
    virtual void Dummy1();
    virtual void Method();
    char pad[0x14];
    Node021f69bc* next;
};
struct ListHead021f69bc { Node021f69bc* first; };

// USA: func_ov023_021f69bc  (semantic: CallVTableFnAt8Loop_021f69bc)
extern "C" ARM void func_ov023_021f69bc(struct ListHead021f69bc* head) {
    Node021f69bc* node = head->first;
    while (node != NULL) {
        node->Method();
        node = node->next;
    }
}
