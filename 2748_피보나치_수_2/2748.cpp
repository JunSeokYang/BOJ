#include <bits/stdc++.h>

using namespace std;

long fibo(long *lst, int N){
    if(!N)
        return N;
    else if(lst[N])
        return lst[N];
    lst[N] = fibo(lst, N-1) + fibo(lst, N-2);
    return lst[N];
}

int main(void){
    long a[91] = {0,1,0,};
    int N;
    cin>>N;
    cout<<fibo(a,N)<<'\n';

    return 0;
}
