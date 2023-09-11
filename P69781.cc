#include<iostream>
#include<map>

using namespace std;

int main(){
	int x,y,n;
	while(cin>>x>>y>>n){
		int aux=0;
		map<int,int> num;
		while(n<=100000000 and num.find(n)==num.end()){	
				num.insert(make_pair(n,aux));
			++aux;
			if(n%2==0){
				n=n/2+x;
			}
			else{
				n=3*n+y;
			}
		}
		if(n>100000000){
			cout<<n<<endl;
		}
		else{
			cout<<aux-num.find(n)->second<<endl;
		}
	}
}