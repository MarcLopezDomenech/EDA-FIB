#include<iostream>
#include <queue>

using namespace std;

int main(){
    int num;
    char inst;
    priority_queue<int> cua;
    while(cin>>inst){
        if(inst=='A'){
             if(cua.size()==0){
                cout<<"error!"<<endl;
             }
             else{
                cout<<cua.top()<<endl;
             }
        }
        else if(inst=='S'){
            cin>>num;
            cua.push(num);
        }
        else if(inst=='R'){
            if(cua.size()==0){
                cout<<"error!"<<endl;
            }
            else{
                cua.pop();
            }
        }
        else if(inst=='I'){
            if(cua.size()==0){
                cout<<"error!"<<endl;
            }
            else{
                int x;
                cin>>x;
                int val=cua.top();
                cua.pop();
                cua.push(val+x);
            }
        }
        else if(inst=='D'){
            if(cua.size()==0){
                cout<<"error!"<<endl;
            }
            else{
                int x;
                cin>>x;
                int val=cua.top();
                cua.pop();
                cua.push(val-x);
            }
        }
    }
}