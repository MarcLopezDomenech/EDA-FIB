#include<iostream>
#include<vector>

using namespace std;

bool pos_ok(vector<int>& Seq,int k){
	int tam=Seq.size();
	if(tam>1){
		int sol;
		if(Seq[tam-1]-Seq[tam-2]<0){
			sol=Seq[tam-2]-Seq[tam-1];
		}
		else{
			sol=Seq[tam-1]-Seq[tam-2];
		}
		return k>=sol;
	}
	return true;
}

void Compl(int n,int k,vector<int>& Seq,vector<bool>& B){
	if(Seq.size()==n){
		cout<<'(';
		for(int i=0;i<Seq.size();++i){
			cout<<Seq[i];
			if(i!=Seq.size()-1){
				cout<<',';
			}
		}
		cout<<')'<<endl;
	}
	else{
		for(int i=0;i<n;++i){
			if(B[i]){
				B[i]=false;
				Seq.push_back(i+1);
				if(pos_ok(Seq,k)){
					Compl(n,k,Seq,B);
				}
				Seq.pop_back();
				B[i]=true;
			}
		}
	}
}

int main(){
	int n,k;
	while(cin>>n>>k){
		vector<int> Seq;
		vector<bool> B(n,true);
		Compl(n,k,Seq,B);
	}
}