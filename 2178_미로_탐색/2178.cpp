#include <bits/stdc++.h>

using namespace std;

int N,M;

void BFS(vector<vector<int> > &arr, vector<vector<int> > &visit){
    if(visit[N-1][M-1])
        return;
    queue<int> nodelist;
    int m,n,x[] = {1,0,-1,0}, y[] = {0,1,0,-1};
    nodelist.push(0);
    while(!nodelist.empty()){
        m = nodelist.front() / 1000;
        n = nodelist.front() % 1000;
        nodelist.pop();
        for(int k=0; k<4; k++)
            if((m+y[k]>=0) && (m+y[k]<N) && (n+x[k]>=0) && (n+x[k]<M))
                if(!visit[m+y[k]][n+x[k]] && arr[m+y[k]][n+x[k]]){
                    visit[m+y[k]][n+x[k]] = visit[m][n] + 1;
                    nodelist.push((m+y[k])*1000 + n+x[k]);
            }
    }
}


int main(void){
    char buf;

    cin>>N>>M;

    vector<vector<int> > arr(N, vector<int>(M,0)), visit(arr);

    for(int i=0; i<N; ++i)
        for(int j=0; j<M; ++j){
            cin>>buf;
            arr[i][j] = buf-48;
        }
    BFS(arr, visit);
    cout<<visit[N-1][M-1]+1<<endl;
    return 0;
}
