#include <bits/stdc++.h>

using namespace std;

class mydeque{
public:
    mydeque(int capacity=5);
    void push_front(int elem);
    void push_back(int elem);
    int pop_front();
    int pop_back();
    int size(){return elemn;}
    int IsEmpty(){return elemn==0;}
    int front();
    int back(){if(IsEmpty()) return -1; return datalist[backi];}
private:
    int *datalist;
    int sz, fronti, backi, elemn;
};

mydeque::mydeque(int capacity):
    datalist{new int[capacity]}, sz{capacity}, fronti{0}, backi{0}, elemn{0} {}

void mydeque::push_front(int elem){
    if((fronti+1)%sz == backi){
        int *buf = new int[sz];
        copy(datalist, datalist+sz, buf);
        delete datalist;
        datalist = new int[2*sz];
        if(fronti>backi){
            copy(buf+backi, buf+fronti, datalist);
        }
        else{
            copy(buf+backi, buf+sz, datalist);
            copy(buf, buf+fronti, datalist+sz-backi);
        }
        fronti = fronti-backi + (!(fronti>backi))*sz;
        backi = 0;
        sz *= 2;
    }
    datalist[fronti] = elem;
    fronti = (fronti+1)%sz;
    elemn++;
}

void mydeque::push_back(int elem){
    int k=backi-1;
    if(!backi)
        k = sz-1;
    if(k == fronti){
        int *buf = new int[sz];
        copy(datalist, datalist+sz, buf);
        delete datalist;
        datalist = new int[2*sz];
        if(fronti>backi){
            copy(buf+backi, buf+fronti, datalist);
        }
        else{
            copy(buf+backi, buf+sz, datalist);
            copy(buf, buf+fronti, datalist+sz-backi);
        }
        fronti = fronti-backi + (!(fronti>backi))*sz;
        backi = 0;
        sz *= 2;
    }
    if(!backi)
        backi = sz-1;
    else
        backi--;
    datalist[backi] = elem;
    elemn++;
}

int mydeque::pop_front(){
    if(IsEmpty())
        return -1;
    if(!fronti)
        fronti = sz-1;
    else fronti--;
    elemn--;
    return datalist[fronti];
}

int mydeque::pop_back(){
    if(IsEmpty())
        return -1;
    int buf = datalist[backi];
    backi = (backi+1)%sz;
    elemn--;
    return buf;

}

int mydeque::front(){
    if(IsEmpty())
        return -1;
    int k = fronti-1;
    if(!fronti)
        k = sz-1;
    return datalist[k];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    mydeque lst;
    int N, in;
    string buf;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>buf;
        if(buf == "push_front"){
            cin>>in;
            lst.push_front(in);
        }
        else if(buf == "push_back"){
            cin>>in;
            lst.push_back(in);
        }
        else if(buf == "pop_front")
            cout<<lst.pop_front()<<endl;
        else if(buf == "pop_back")
            cout<<lst.pop_back()<<endl;
        else if(buf == "size")
            cout<<lst.size()<<endl;
        else if(buf == "empty")
            cout<<lst.IsEmpty()<<endl;
        else if(buf == "front")
            cout<<lst.front()<<endl;
        else if(buf == "back")
            cout<<lst.back()<<endl;
    }
    return 0;
}
