#include <globaldefs.h>

struct Args0223d884 { int a, b, c, d; };
extern "C" void func_ov031_0223cf70(Args0223d884* args);

// USA: func_ov031_0223d884
ARM void ForwardFourArgsAsStruct_0223d884(Args0223d884 args) {
	func_ov031_0223cf70(&args);
}
