#include <bits/stdc++.h>

using namespace std;

long long fibo(vector<long long> &lst, long long N){
    long long buf;
    if(!N)
        return N;
    N %= 1500000;
    if(lst[N])
        return lst[N];
    lst[N] = (fibo(lst, N-1) + fibo(lst, N-2))%1000000;
    return lst[N];
}

int main(void){
    vector<long long> lst(1500000,0);
    long long buf, N;
    lst[1] = 1;
    cin>>N;
    buf = fibo(lst,N);
    buf %= 1000000;
    cout<<buf<<'\n';

    return 0;
}
