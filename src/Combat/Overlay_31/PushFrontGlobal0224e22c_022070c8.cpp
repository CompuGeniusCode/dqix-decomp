#include <globaldefs.h>

struct Node022070e0;
struct Item022070e0;
void PushFront022070e0(Node022070e0* head, Item022070e0* item);

extern Node022070e0 data_ov031_0224e22c;

// USA: func_ov031_022070c8  (semantic: PushFrontGlobal0224e22c_022070c8)
extern "C" ARM void func_ov031_022070c8(Item022070e0* item) {
    PushFront022070e0(&data_ov031_0224e22c, item);
}
