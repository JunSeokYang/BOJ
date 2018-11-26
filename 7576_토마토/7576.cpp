#include <bits/stdc++.h>

using namespace std;


queue<int> rx;

int M,N,w;

void BFS(vector<vector<int> > &arr){
    int i,j,x[] = {-1,0,1,0}, y[] = {0,1,0,-1};
    if(rx.size() == 1)
        return;
    while(!rx.empty()){
        i = rx.front() / 10000;
        j = rx.front() % 10000;
        rx.pop();
        if(j == -1)
            break;
        for(int k=0; k<4; k++)
            if( (i+x[k] >=0) && (i+x[k] < M) && (j+y[k] >=0) && (j+y[k] < N) )
                if(arr[i+x[k]][j+y[k]] == 0){
                    arr[i+x[k]][j+y[k]] = 1;
                    rx.push((i+x[k])*10000 + j+y[k]);
                }
    }
    w++;
    rx.push(-1);
    BFS(arr);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    w = 0;
    cin>>N>>M;
    vector<vector<int> > arr(M,vector<int>(N,0));
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 1)
                rx.push(i*10000 + j);
        }
    rx.push(-1);
    BFS(arr);
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++)
            if(arr[i][j] == 0)
                w = 0;
    cout<<--w<<endl;
    return 0;
}
