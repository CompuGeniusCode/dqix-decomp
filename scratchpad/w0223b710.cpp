#include <globaldefs.h>

struct Args0223b710 { int a, b, c, d; };
struct Inner0223b710 { unsigned char pad[0x84]; void* field84; };

extern "C" void func_ov031_0223cf70(Args0223b710* args);
extern "C" void func_ov031_0223bf48(void*, int);
extern Inner0223b710* data_ov031_02290d24;

// USA: func_ov031_0223b710
ARM void ForwardArgsAndNotify_0223b710(Args0223b710 args) {
	func_ov031_0223cf70(&args);
	func_ov031_0223bf48(data_ov031_02290d24->field84, args.a);
}
