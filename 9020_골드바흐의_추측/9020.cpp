#include <bits/stdc++.h>

using namespace std;

void prime(int n, vector<int> &lst){
    int mx = (int)sqrt(n);
    int start;
    for(int i=0; lst[i]<=mx; i++)
        if(!(n%lst[i]))
            return;
    lst.push_back(n);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> lst;
    int N, buf, mx, bet, a, b;
    lst.push_back(2);
    for(int i=3; i<10001; i++)
        prime(i, lst);
    cin>>N;
    for(int i=0; i<N; i++){
        mx = bet = 10001;
        a = b = 0;
        cin>>buf;
        for(int j=0; lst[j]<buf; j++)
            for(int k=j; lst[k]<buf; k++)
                if(lst[j] + lst[k] == buf){
                    bet = lst[k] < lst[j] ? lst[j] - lst[k] : lst[k] - lst[j];
                    if(mx > bet){
                        mx = bet;
                        a = lst[j];
                        b = lst[k];
                    }
                }
                else if(lst[j] + lst[k] > buf)
                    break;
        cout<<a<<' '<<b<<'\n';
    }

    return 0;
}
