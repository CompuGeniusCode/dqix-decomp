extern "C" int g(int);
extern "C" void h(int);
// param p preserved across a call, plus a call-defined local a, plus a loop
extern "C" int t(int p, int x){
    int a = g(x);            // local defined by call
    for(int i=0;i<a;i++) h(i);
    return a + p;            // p used at end (preserved across everything)
}
