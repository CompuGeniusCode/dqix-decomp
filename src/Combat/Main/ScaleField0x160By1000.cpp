#include <globaldefs.h>

extern "C" int func_0200cedc(unsigned long long, unsigned short);

// USA: func_020bec98
ARM int ScaleField0x160By1000(void *obj) {
    if (*(int *)obj == 0) return 0;
    {
        void *p = *(void **)obj;
        return func_0200cedc(
            (unsigned long long)*(unsigned int *)((char *)p + 0x160) * 1000,
            *(unsigned short *)((char *)p + 0xc4));
    }
}
