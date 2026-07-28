#include <globaldefs.h>

int InvokeWithTempHandlerOverride020ce704(int a, int b);
extern "C" void func_020ce234(int value, int* ptr);
extern "C" void _Z35WaitWhileInterruptsDisabled020ce188v(void);
extern "C" void _Z33WaitForCallbackCompletion020ce148v(void);
extern void (*data_020f2298)(void);

// USA: func_020ce758  (semantic: InvokeAndAwaitCallback020ce758)
extern "C" ARM int func_020ce758(void) {
    int local;
    int result = InvokeWithTempHandlerOverride020ce704((int)func_020ce234, (int)&local);
    if (result != 0) {
        return result;
    }
    data_020f2298 = _Z35WaitWhileInterruptsDisabled020ce188v;
    data_020f2298();
    data_020f2298 = _Z33WaitForCallbackCompletion020ce148v;
    return local;
}
