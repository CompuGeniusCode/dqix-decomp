#include <globaldefs.h>
struct Inner0205111c { unsigned int v[3]; };
struct Foo0205111c { unsigned short a; struct Inner0205111c mid; unsigned char e; };
// USA: func_0205111c
ARM struct Foo0205111c* CopyStruct0205111c(struct Foo0205111c* dst, struct Foo0205111c* src) {
    dst->a = src->a;
    dst->mid = src->mid;
    dst->e = src->e;
    return dst;
}
