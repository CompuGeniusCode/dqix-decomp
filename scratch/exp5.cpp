extern "C" int g(int);
extern "C" void h(int,int);
// param p dies early (used only to make 'a'); a and loop live after
extern "C" int t(int p, int x){
    int a = g(x);
    int b = g(p);     // last use of p here (dies before loop)
    for(int i=0;i<a;i++) h(i,b);   // a,b,i live in loop
    return a+b;
}
