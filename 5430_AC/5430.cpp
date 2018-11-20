#include <bits/stdc++.h>

using namespace std;

int main(void){
    vector<int> lst;
    string buf;
    int T,N,elem,rflag,it1, it2,c;
    char erase;
    cin>>T;
    for(int i=0; i<T; i++){
        lst.clear();
        buf.clear();
        cin>>buf>>N;
        it1 = rflag = c = 0;
        it2 = N-1;
        //초기화

        if(N)
            for(int j=0; j<2*N+1; j++){
                if(j%2){
                    cin>>elem;
                    lst.push_back(elem);
                }
                else
                    cin>>erase;
            }
        else
            cin>>erase>>erase;
        // 입력부

        for(int j=0; j<buf.length(); j++)
            if(buf[j] == 'R')
                rflag = !rflag;
            else{
                c++;
                if(c>N){
                    cout<<"error\n";
                    break;
                }
                if(rflag)
                    it2--;
                else
                    it1++;
            }

        if(c<=N){
            cout<<'[';
            if(rflag){
                for(int j=it2; j>it1; --j)
                    cout<<lst[j]<<',';
                if(N-c)
                    cout<<lst[it1];
            }
            else{
                for(int j=it1; j<it2; ++j)
                    cout<<lst[j]<<',';
                if(N-c)
                    cout<<lst[it2];
            }
            cout<<"]\n";
        }
    }
    return 0;
}
