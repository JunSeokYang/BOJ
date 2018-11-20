#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void){
    int N,M,*K,*buf, max;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>M;
        max = 0;
        K = new int[M];
        buf = new int[M];
        for(int j=0; j<M; j++)
            cin>>K[j];
        sort(K,K+M);
        for(int j=0; j<M; j++)
            if(j%2)
                buf[(M+1)/2-1+((j+(j%2))/2)] = K[M-j-1];
            else
                buf[(M+1)/2-1-((j+(j%2))/2)] = K[M-j-1];
        for(int j=0; j<M-1; j++)
            if(abs(buf[j+1]-buf[j]) > max)
                max = abs(buf[j+1] - buf[j]);
        if(abs(buf[0]-buf[M-1])>max)
            max = abs(buf[0]-buf[M-1]);
        cout<<max<<endl;
    }

    return 0;
}
