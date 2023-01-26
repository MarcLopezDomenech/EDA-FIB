#include<iostream>
#include<queue>

using namespace std;

bool pos_ok(vector<vector<char>> &Mat,int y,int x){
	int f=Mat.size();
	int c=Mat[0].size();
	return x>=0 and y>=0 and y<f and x<c and Mat[y][x]!='#';
}
void bfs(vector<vector<char>> &Mat){
	int f=Mat.size();
	int c=Mat[0].size();

	int min=10000;
	int perso=-1;
	bool enc=false;

	queue<int> q;
	vector<int> dist(f*c,-1);
	vector<int> pers(f*c,-1);

	if(Mat[0][0]=='T'){
		cout<<0<<" "<<0<<endl;
	}
	else{
		pers[0]=0;
		dist[0]=0;
		if(Mat[0][0]=='P'){
			pers[0]=1;
		}
		q.push(0);
		while(not q.empty()){
			int val=q.front();
			q.pop();
			int y=val/c;
			int x=val%c;
			for(int i=-1;i<=1;++i){
				if(i!=0){
					if(pos_ok(Mat,y,x+i) and (dist[val+i]==-1 or (dist[val]==(dist[val+i]-1) and pers[val]>=pers[val+i]))){
						dist[val+i]=dist[val]+1;

						//cout<<y<<" "<<x+i<<" "<<dist[val+i]<<endl;

						if(Mat[y][x+i]=='P'){
							pers[val+i]=pers[val]+1;
						}
						else{
							pers[val+i]=pers[val];
						}
						if(Mat[y][x+i]=='T'){
							enc=true;
							if(min>dist[val+i]){
								min=dist[val+i];
								perso=pers[val+i];
							}
							else if(min==dist[val+i] and perso<pers[val+i]){
								perso=pers[val+i];
							}
						}
						else{
							q.push(val+i);
						}
					}
					if(pos_ok(Mat,y+i,x) and (dist[val+i*c]==-1 or (dist[val]==dist[val+i*c]-1 and pers[val]>=pers[val+i*c]))){

						dist[val+i*c]=dist[val]+1;

						//cout<<y+i<<" "<<x<<" "<<dist[val+i]<<endl;

						if(Mat[y+i][x]=='P'){
							pers[val+i*c]=pers[val]+1;
						}
						else{
							pers[val+i*c]=pers[val];
						}
						if(Mat[y+i][x]=='T'){
							enc=true;
							if(min>dist[val+i*c]){
								min=dist[val+i*c];
								perso=pers[val+i*c];
							}
							else if(min==dist[val+i*c] and perso<pers[val+i*c]){
								perso=pers[val+i*c];
							}
						}
						else{
							q.push(val+i*c);
						}
					}
				}
			}
		}

		if(enc){
			cout<<min<<" "<<perso<<endl;
		}
		else{
			cout<<"El telecos esta amagat."<<endl;
		}
	}

}

int main(){
	int n,m;
	while(cin>>n>>m){
		bool telecos=false;
		vector<vector<char>> Mat (n,vector<char>(m));
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				char a;
				cin>>a;
				Mat[i][j]=a;
				if(not telecos and a=='T'){
					telecos=true;
				}

			}
		}

		if(not telecos){
			cout<<"El telecos ha fugit."<<endl;
		}
		else{
			bfs(Mat);
		}
	}
}