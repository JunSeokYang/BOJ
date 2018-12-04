#include <bits/stdc++.h>

using namespace std;


queue<int> rx;

int M,N,H,w;

void BFS(vector<vector<vector<int> > > &arr){
    int i,j,h,x[] = {-1,0,1,0}, y[] = {0,1,0,-1}, z[] = {1,-1};
    if(rx.size() == 1)
        return;
    while(!rx.empty()){
        i = rx.front() / 1000000;
        j = (rx.front() % 1000000) / 1000;
        h = rx.front() % 1000;
        rx.pop();
        if(h == -1)
            break;
        for(int k=0; k<4; k++)
            if( (j+x[k] >=0) && (j+x[k] < M) && (h+y[k] >=0) && (h+y[k] < N) )
                if(arr[i][j+x[k]][h+y[k]] == 0){
                    arr[i][j+x[k]][h+y[k]]= 1;
                    rx.push(i*1000000 + (j+x[k])*1000 + h+y[k]);
                }
        for(int k=0; k<2; k++)
            if( (i+z[k]>=0) && (i+z[k] <H))
                if(arr[i+z[k]][j][h] == 0){
                    arr[i+z[k]][j][h] = 1;
                    rx.push((i+z[k])*1000000 + j*1000 + h);
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
    cin>>N>>M>>H;
    vector<vector<vector<int> > > arr(H,vector<vector<int>>(M, vector<int>(N,0)));
    for(int i=0; i<H; i++)
        for(int j=0; j<M; j++)
            for(int k=0; k<N; k++){
                cin>>arr[i][j][k];
                if(arr[i][j][k] == 1)
                    rx.push(i*1000000 + j*1000 + k);
            }
    rx.push(-1);
    BFS(arr);
    for(int i=0; i<H; i++)
        for(int j=0; j<M; j++)
            for(int k=0; k<N; k++)
            if(arr[i][j][k] == 0)
                w = 0;
    cout<<--w<<endl;
    return 0;
}
