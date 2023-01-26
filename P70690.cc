#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> FILA;
typedef vector<FILA> Matriu;

int n,m;

bool pos(Matriu& mapa,int x,int y){
	if(x>=n or y>=m or x<0 or y<0){
		return false;
	}
	else if(mapa[x][y]=='X'){
		return false;
	}
	else if(mapa[x][y]=='t'){
		return true;
	}
	mapa[x][y]='X';
	return pos(mapa,x+1,y) or pos(mapa,x,y+1) or pos(mapa,x-1,y) or pos(mapa,x,y-1);

}
int main(){
	cin>>n>>m;
	Matriu mapa(n,FILA(m));
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>mapa[i][j];
		}
	}
	int x,y;
	cin>>x>>y;
	if(pos(mapa,x-1,y-1)){
		cout<<"yes"<<endl;
	}
	else{
		cout<<"no"<<endl;
	}
}