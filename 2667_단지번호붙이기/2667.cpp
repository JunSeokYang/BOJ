#include <bits/stdc++.h>

using namespace std;

int N;

int BFS(vector<vector<int> > &arr, int p, int q){
    queue<int> bfsx, bfsy;
    int i,j,x[] = {-1,0,1,0}, y[] = {0,1,0,-1}, mbuf=0;
    bfsx.push(p);
    bfsy.push(q);
    while(!bfsx.empty()){
        i = bfsx.front();
        j = bfsy.front();
        bfsx.pop();
        bfsy.pop();
        if(arr[i][j]){
            arr[i][j] = 0;
            mbuf++;
            for(int k=0; k<4; k++)
                if( (i+x[k] >=0) && (i+x[k] < N) && (j+y[k] >=0) && (j+y[k] < N) )
                    if(arr[i+x[k]][j+y[k]]){
                        bfsx.push(i+x[k]);
                        bfsy.push(j+y[k]);
                    }
        }
    }
    return mbuf;
}

int main(void){
    vector<int> lst;
    int w=0,mbuf=0,sz;
    char buf;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    vector<vector<int> > arr(N,vector<int>(N,0));

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            cin>>buf;
            arr[i][j] = buf-48;
        }

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
                mbuf = BFS(arr, i, j);
                if(mbuf){
                    lst.push_back(mbuf);
                    w++;
                }
        }
    sort(lst.begin(), lst.end());
    cout<<w<<'\n';
    sz = lst.size();
    for(int i=0; i<sz; i++)
        cout<<lst[i]<<'\n';
    return 0;
}
