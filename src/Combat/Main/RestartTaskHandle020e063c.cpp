#include <globaldefs.h>

int GetData02104304Field4();
void ReleaseHandle02022b90(void* owner, int* handle);
int CallFunc0202fa38Mode2(int a, int b, int c, int d);

struct Obj020e063c {
    unsigned char pad0[0x9c5];
    unsigned char flag_9c5;
    unsigned char pad1[0xa0c - 0x9c6];
    int handle_a0c;
};

// USA: func_020e063c
ARM void RestartTaskHandle020e063c(struct Obj020e063c* self, int b, int c) {
    int h = GetData02104304Field4();
    self->flag_9c5 = 1;
    ReleaseHandle02022b90(self, &self->handle_a0c);
    self->handle_a0c = CallFunc0202fa38Mode2(h, b, c, 0);
}
