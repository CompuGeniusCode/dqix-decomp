#include <globaldefs.h>

struct Ring022919bc { int head; int tail; };
extern Ring022919bc data_ov031_022919bc;

struct Entry022919c4 { int id; void* obj; };
extern Entry022919c4 data_ov031_022919c4[8];

extern "C" int func_ov031_022413c8(int unused, int id);
extern "C" void func_ov031_02241720(void* obj);

// USA: func_ov031_022417fc  (semantic: ProcessRing_022417fc)
extern "C" ARM void func_ov031_022417fc(void) {
    if (data_ov031_022919bc.head == data_ov031_022919bc.tail) return;
    do {
        func_ov031_022413c8(0, data_ov031_022919c4[data_ov031_022919bc.tail].id);
        Entry022919c4* e = data_ov031_022919c4 + data_ov031_022919bc.tail;
        func_ov031_02241720(e->obj);
        data_ov031_022919bc.tail = (data_ov031_022919bc.tail + 1) & 7;
    } while (data_ov031_022919bc.head != data_ov031_022919bc.tail);
}
