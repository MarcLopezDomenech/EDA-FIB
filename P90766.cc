#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> FILA;
typedef vector<FILA> Matriu;

int n,m;

int pos(Matriu& mapa,int x,int y){
	if(x>=n or y>=m or x<0 or y<0){
		return 0;
	}
	else if(mapa[x][y]=='X'){
		return 0;
	}
	else if(mapa[x][y]=='t'){
		mapa[x][y]='X';
		return 1+pos(mapa,x+1,y) + pos(mapa,x,y+1) + pos(mapa,x-1,y) + pos(mapa,x,y-1);
	}
	mapa[x][y]='X';
	return pos(mapa,x+1,y) + pos(mapa,x,y+1) + pos(mapa,x-1,y) + pos(mapa,x,y-1);

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
	cout<<pos(mapa,x-1,y-1)<<endl;
}