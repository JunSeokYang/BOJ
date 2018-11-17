#include <bits/stdc++.h>

using namespace std;

int main(void){
    int N, *lst, f=0,buf,m,M,c=0, it, r1, r2;
    cin>>N;
    lst = new int[N];
    for(int i=0; i<N; i++)
        lst[i] = 0;
    cin>>M;
    for(int i=0; i<M; i++){
        cin>>buf;
        buf--;
        r1 = r2 = 0;
        it = f;
        while(it != buf){
            it = (it+1)%N;
            if(!lst[it])
                r1++;
        }
        it = f;
        while(it != buf){
            if(!it)
                it = N-1;
            else it--;
            if(!lst[it])
                r2++;
        }
        m = r1>r2 ? r2 : r1;
        c += m;
        if(i == M-1)
            break;
        f = buf;
        lst[f] = 1;
        while(lst[f])
            f = (f+1)%N;
    }
    cout<<c<<endl;
    return 0;
}