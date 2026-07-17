extern "C" int f(int);
// Each local is defined by a call (so must live in a callee-saved reg across later calls),
// first-used in order a,b,c,d, last-used in reverse so all live simultaneously across calls.
extern "C" int test(int seed) {
    int a = f(seed);
    int b = f(a);
    int c = f(b);
    int d = f(c);
    return a + b*2 + c*3 + d*4;  // force all live to the end
}
