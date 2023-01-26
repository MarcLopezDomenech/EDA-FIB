#include<iostream>
#include<map>

using namespace std;

int main(){
	int n;
	while(cin>>n){
		int total=n;
		map<string,int> Jocs;
		for(int i=0;i<n;++i){
			string a;
			cin>>a;
			map<string,int>::iterator it;
			it=Jocs.find(a);
			if(it==Jocs.end()){
				Jocs.insert(make_pair(a,1));
			}
			else{
				Jocs[a]=Jocs[a]+1;
			}
		}

		int n2;
		cin>>n2;
		for(int i=0;i<n2;++i){
			string a;
			cin>>a;
			map<string,int>::iterator it;
			it=Jocs.find(a);
			if(it==Jocs.end()){
				Jocs.insert(make_pair(a,1));
				++total;
			}
			else{
				if(Jocs[a]<(total-Jocs[a])){
					Jocs[a]=Jocs[a]+1;
					++total;
				}
			}
		}
		map<string,int>::iterator it=Jocs.begin();
		while(it!=Jocs.end()){
			cout<<it->first<<" "<<it->second<<endl;
			++it;
		}
		cout<<"--------------------"<<endl;
	}
}