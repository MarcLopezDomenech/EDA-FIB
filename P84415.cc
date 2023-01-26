#include<iostream>
#include<map>

using namespace std;

int main(){
	map<string,int> par;
	map<string,int>::iterator it;
	string a;
	while(cin>>a){
		if(a=="minimum?"){
			if(par.empty()){
				cout<<"indefinite minimum"<<endl;
			}
			else{
				it=par.begin();
				cout<<"minimum: "<<it->first<<", "<<it->second<<" time(s)"<<endl;
			}
		}
		else if(a=="maximum?"){
			if(par.empty()){
				cout<<"indefinite maximum"<<endl;
			}
			else{
				it=par.end();
				--it;
				cout<<"maximum: "<<it->first<<", "<<it->second<<" time(s)"<<endl;
				
			}
		}
		else if(a=="store"){
			string b;
			cin>>b;
			if(par.find(b)==par.end()){
				par.insert(make_pair(b,1));
			}
			else{
				++par.find(b)->second;
			}
		}
		else if(a=="delete"){
			string b;
			cin>>b;
			if(par.find(b)!=par.end()){
				if(par.find(b)->second==1){
					par.erase(b);
				}
				else{
					--par.find(b)->second;
				}
			}
		}

	}
}