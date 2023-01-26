#include<iostream>
#include<vector>

using namespace std;

bool pos_ok(int x,int y,int c,int f){
	return x>=0 and y>=0 and x<c and y<f;
}
void escr(vector<char>& pal){
	int n=pal.size();
	for(int i=0;i<n;++i){
		cout<<pal[i];
	}
	cout<<endl;
}
void camino(vector<vector<char>>& Mat,vector<vector<bool>>& P,int f,int c,int y,int x,int y1,int x1,vector<char>& pal){
	if(y==y1 and x==x1){
		escr(pal);
	}
	else{
		if(pos_ok(x+1,y,c,f) and not P[y][x+1]){
			P[y][x+1]=true;
			pal.push_back(Mat[y][x+1]);
			camino(Mat,P,f,c,y,x+1,y1,x1,pal);
			pal.pop_back();
			P[y][x+1]=false;
		}
		if(pos_ok(x-1,y,c,f) and not P[y][x-1]){
			P[y][x-1]=true;
			pal.push_back(Mat[y][x-1]);
			camino(Mat,P,f,c,y,x-1,y1,x1,pal);
			pal.pop_back();
			P[y][x-1]=false;
		}
		if(pos_ok(x,y+1,c,f) and not P[y+1][x]){
			P[y+1][x]=true;
			pal.push_back(Mat[y+1][x]);
			camino(Mat,P,f,c,y+1,x,y1,x1,pal);
			pal.pop_back();
			P[y+1][x]=false;
		}
		if(pos_ok(x,y-1,c,f) and not P[y-1][x]){
			P[y-1][x]=true;
			pal.push_back(Mat[y-1][x]);
			camino(Mat,P,f,c,y-1,x,y1,x1,pal);
			pal.pop_back();
			P[y-1][x]=false;
		}
	}
}

int main(){
	int f,c;
	cin>>f>>c;
	vector<vector<char>> Mat (f,vector<char>(c));
	vector<vector<bool>> P (f,vector<bool>(c,false));
	vector<char> pal;
	for(int i=0;i<f;++i){
		for(int j=0;j<c;++j){
			cin>>Mat[i][j];
		}
	}
	int y,x;
	cin>>y>>x;
	P[y][x]=true;
	pal.push_back(Mat[y][x]);
	int y1,x1;
	cin>>y1>>x1;
	camino(Mat,P,f,c,y,x,y1,x1,pal);
}