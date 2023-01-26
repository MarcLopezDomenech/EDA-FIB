#include<iostream>
#include<vector>

using namespace std;
bool pos_ok(vector<int>& V,int i ){
	return i>=0 and i<V.size();
}
bool cumple(vector<int>& V){
	int n=V.size();
	if(pos_ok(V,n-3) and (V[n-3]+V[n-1]>2*V[n-2])){
		return false;
	}
	return true;
}

void completar(vector<int>& V,vector<bool>& Us,int n){
	if(n==V.size()){
		cout<<'(';
		for(int i=0;i<n;++i){
			cout<<V[i];
			if(i!=n-1){
				cout<<',';
			}
		}
		cout<<')'<<endl;
	}
	else{
		for(int i=1;i<=n;++i){
			if(not Us[i]){
				Us[i]=true;
				V.push_back(i);
				if(not cumple(V)){
					V.pop_back();
				}
				else{
					completar(V,Us,n);
					V.pop_back();
				}
				Us[i]=false;
			}
		}
	}
}
int main(){
	int n;
	cin>>n;
	vector<int> V;
	vector<bool> Us(n,false);
	completar(V,Us,n);

}