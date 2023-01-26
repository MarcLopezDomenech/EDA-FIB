#include<iostream>
#include<vector>

using namespace std;
bool pos_ok(vector<string>sol){
	int tam=sol.size();
	if(tam>1){
		char let=sol[tam-1][0];

		int tam1=sol[tam-2].size();
		char let1=sol[tam-2][tam1-1];

		if(let1==let){
			return false;
		}
	}
	return true;
}
void comb(vector<string>& par,vector<string>& sol){
	if(par.size()==sol.size()){
		for(int i=0;i<sol.size();++i){
			cout<<sol[i];
		}
		cout<<endl;
	}
	else{
		for(int i=0;i<par.size();++i){
			if(par[i]!="-1"){
				string a = par[i];
				par[i]="-1";
				sol.push_back(a);

				if(pos_ok(sol)){
					comb(par,sol);
				}
				par[i]=a;
				sol.pop_back();
			}
		}
	}
}

int main(){
	int n;
	cin>>n;
	vector<string> par(n);
	vector<string> sol;
	for(int i=0;i<n;++i){
		cin>>par[i];
	}
	comb(par,sol);
}