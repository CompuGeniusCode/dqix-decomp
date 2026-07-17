extern "C" int g(int);
extern "C" int t1(int s){ int a=g(s); g(0); return a; }        // one saved var
extern "C" int t2(int s){ int a=g(s); int b=g(a); g(0); return a+b; } // two saved
