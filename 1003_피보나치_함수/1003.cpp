#include <bits/stdc++.h>

using namespace std;

int fibonacci(int *c0, int *c1, int *lst, int n) {
    if(n == 0 || n == 1)
        return n;
    else if(lst[n]){
        c0[n] = c0[n-1] + c0[n-2];
        c1[n] = c1[n-1] + c1[n-2];
        return n;
    }
    lst[n] = fibonacci(c0,c1,lst, n-1) + fibonacci(c0, c1, lst, n-2);
    c0[n] = c0[n-1] + c0[n-2];
    c1[n] = c1[n-1] + c1[n-2];
    return lst[n];


}

int main(void){
    int N, buf;
    cin>>N;
    for(int i=0; i<N; i++){
        int c0[41] = {1,0,}, c1[41] = {0,1,0,}, lst[41] = {0,1,0,};
        cin>>buf;
        fibonacci(c0, c1, lst, buf);
        cout<<c0[buf]<<' '<<c1[buf]<<'\n';
    }
    return 0;
}
