#include<iostream>
#include <queue>
#include <map>
#include <map>

using namespace std;

int main(){
 map<string,int> jugad;
 map<string,int> :: iterator it;
 string nom,fet;
 while(cin>>nom>>fet){
    if(fet=="enters"){
        it=jugad.find(nom);
        if(it!=jugad.end()){
            cout<<nom<<" is already in the casino"<<endl;
        }
        else{
            pair<string,int> b= make_pair(nom,0);
            jugad.insert(b);
        }

    }
    else if(fet=="leaves"){
        it=jugad.find(nom);
        if(it!=jugad.end()){
            cout<<nom<<" has won "<<it->second<<endl;
            jugad.erase(nom);
        }
        else{
            cout<<nom<<" is not in the casino"<<endl;
        }
    }
    else if(fet=="wins"){
        int cant;
        cin>>cant;
        it=jugad.find(nom);
        if(it!=jugad.end()){
            it->second= it->second+cant;
        }
        else{
            cout<<nom<<" is not in the casino"<<endl;
        }
    }
 }
 cout<<"----------"<<endl;
 for(it=jugad.begin();it!=jugad.end();++it){
    cout<<it->first<<" is winning "<<it->second<<endl;
 }
}