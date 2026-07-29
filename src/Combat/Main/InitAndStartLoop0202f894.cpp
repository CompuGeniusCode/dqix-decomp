#include <globaldefs.h>

extern "C" void func_0202f808(void*);
struct ProcessorContext;
int ClampAndSubmit020d97a8(int, int, int, int, int, int);
void Forward020d9828(void*);
struct VirtualObject0202f744;
void RunObjectUpdateLoop(struct VirtualObject0202f744*);

extern int data_0210430c;

// USA: func_0202f894  (semantic: InitAndStartLoop0202f894)
extern "C" ARM void func_0202f894(void* obj, int a1, int a2, int a3) {
    func_0202f808(obj);
    *(int*)((char*)obj + 0x110) = a1;
    *(int*)((char*)obj + 0x114) = a2;
    *(int*)((char*)obj + 0x788) = 0;
    volatile int* flagsPtr = (volatile int*)((char*)obj + 0x78c);
    *flagsPtr &= ~2;
    int flags = *flagsPtr;
    flags &= ~1;
    flags |= 1;
    *flagsPtr = flags;
    *flagsPtr |= 4;
    ClampAndSubmit020d97a8((int)((char*)obj + 4), (int)&data_0210430c, 0x800, a3, (int)(void*)RunObjectUpdateLoop, (int)obj);
    Forward020d9828((char*)obj + 4);
}
