#include <globaldefs.h>

struct Args0223bf2c { int a, b, c, d; };
extern "C" void func_ov031_0223cf70(Args0223bf2c* args);

// USA: func_ov031_0223bf2c
ARM void ForwardFourArgsAsStruct_0223bf2c(Args0223bf2c args) {
	func_ov031_0223cf70(&args);
}
