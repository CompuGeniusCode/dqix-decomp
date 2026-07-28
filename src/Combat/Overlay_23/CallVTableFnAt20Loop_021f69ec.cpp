#include <globaldefs.h>

class Node021f69ec {
public:
    virtual void Dummy0();
    virtual void Dummy1();
    virtual void Dummy2();
    virtual void Dummy3();
    virtual void Dummy4();
    virtual void Method();
    char pad[0x14];
    Node021f69ec* next;
};
struct ListHead021f69ec { Node021f69ec* first; };

// USA: func_ov023_021f69ec  (semantic: CallVTableFnAt20Loop_021f69ec)
extern "C" ARM void func_ov023_021f69ec(struct ListHead021f69ec* head) {
    Node021f69ec* node = head->first;
    while (node != NULL) {
        node->Method();
        node = node->next;
    }
}
