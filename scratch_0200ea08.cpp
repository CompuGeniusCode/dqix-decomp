#include <globaldefs.h>

extern "C" void func_0200df80(void* obj, void* p1, int p3a, int p3b);
extern "C" void func_0200f2ec(void* obj, void* p1, int val);

// USA: func_0200ea08
ARM void RegisterListEntry0200ea08(char* obj, int* p1, char* p2, int p3) {
    int p3v = p3;
    char* p2v = p2;
    int arg3 = p3v;
    char* objv = obj;
    int* p1v = p1;
    func_0200df80(objv, p1v, arg3, p3v);
    char* listHead = *(char**)(objv + 0x18);
    int off = *(int*)(p2v + 0x8);
    char* entry = listHead + off;
    *(int*)(listHead + off) = *(int*)(objv + 0x4);
    *(int*)(entry + 0x4) = *(int*)(objv + 0x0);
    *(int*)(entry + 0x8) = *(int*)(objv + 0x8);
    *(int*)(entry + 0x14) = p3v;
    int combined = *p1v + *(int*)(p2v + 0x4);
    func_0200f2ec(objv, p1v, combined);
}
