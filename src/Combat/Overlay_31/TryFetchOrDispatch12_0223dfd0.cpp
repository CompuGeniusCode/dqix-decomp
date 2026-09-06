#include <globaldefs.h>

int FetchHalfword0xF6(int*);
int DispatchType0x12(int);

// USA: func_ov031_0223dfd0
ARM int TryFetchOrDispatch12_0223dfd0(void) {
	int local;
	int result = FetchHalfword0xF6(&local);
	if (result != 0) {
		return result;
	}
	if (local == 0xf) {
		return local;
	}
	return DispatchType0x12(0xf);
}
