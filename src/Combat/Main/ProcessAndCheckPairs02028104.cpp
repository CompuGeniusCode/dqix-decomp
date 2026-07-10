#include <globaldefs.h>

struct Struct0202811c;
extern "C" void func_02028048(struct Struct0202811c* s, int b, int c, int d);
void CheckAllPairsEqual0202811c(struct Struct0202811c* s);

// USA: func_02028104
ARM void ProcessAndCheckPairs02028104(struct Struct0202811c* s, int b, int c, int d) {
    func_02028048(s, b, c, d);
    CheckAllPairsEqual0202811c(s);
}
