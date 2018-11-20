#include <bits/stdc++.h>

using namespace std;

int main(void){
    int N,buf;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> lst;
    vector<int> mx;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>buf;
        lst.push_back(buf);
    }
    sort(lst.begin(),lst.end());
    buf = lst.size();
    mx.push_back(lst[buf-1]*lst[buf-2]*lst[buf-3]);
    mx.push_back(lst[buf-1]*lst[0]*lst[1]);
    mx.push_back(lst[buf-1]*lst[buf-2]);
    mx.push_back(lst[0]*lst[1]);
    sort(mx.begin(),mx.end());
    cout<<mx.back()<<endl;
    return 0;
}
