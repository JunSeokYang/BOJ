#include <bits/stdc++.h>

using namespace std;

int N,M;

int BFS(vector<vector<int> > &arr, vector<int> &visit){
    queue<int> nodelist;
    int m,sum=0;
    nodelist.push(0);
    while(!nodelist.empty()){
        m = nodelist.front();
        nodelist.pop();
        for(auto i=arr[m].begin(); i != arr[m].end(); ++i)
            if(!visit[*i]){
                visit[*i] = 1;
                sum++;
                nodelist.push(*i);
            }
    }
    return sum;
}


int main(void){
    int p,q, sum=0;

    cin>>N>>M;

    vector<vector<int> > arr(N);
    vector<int> visit(N,0);

    for(int i=0; i<M; ++i){
        cin>>p>>q;
        arr[p-1].push_back(q-1);
        arr[q-1].push_back(p-1);
    }
    cout<<BFS(arr, visit)-1<<endl;
    return 0;
}
