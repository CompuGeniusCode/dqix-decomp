extern "C" int g(int);
extern "C" void h(int);
// a defined first (outside loop), b is the loop counter used heavily inside loop
extern "C" int t(int s){
    int a=g(s);          // saved, used after loop
    for(int i=0;i<a;i++){ h(i); }   // i is loop var
    return a;
}
