#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool correct(int x,int y,vector<vector<int>>& Tab){
	int n=Tab.size();
	return x>=0 and y>=0 and y<n and x<n;
}

int  Dijstra(vector<vector<int>>& Tab){
	int n=Tab[0].size();
	int min=-1;

	vector<vector<int>> dist(n,vector<int>(n,-1));

	queue<int> q;

	int in_x=n/2;
	dist[in_x][in_x]=Tab[in_x][in_x];

	q.push(n*in_x+in_x);

	while(not q.empty()){
		int pos=q.front();
		q.pop();

		int pos_x=pos/n;
		int pos_y=pos%n;

		if(pos_x==0 or pos_x==(n-1) or pos_y==0 or pos_y==(n-1)){
			if(min==-1 or dist[pos_x][pos_y]<min){
				min=dist[pos_x][pos_y];
			}
		}
		else{
			if(correct(pos_x+1,pos_y,Tab) and (min==-1 or min>Tab[pos_x+1][pos_y]+dist[pos_x][pos_y])and (dist[pos_x+1][pos_y]==-1 or dist[pos_x+1][pos_y]>Tab[pos_x+1][pos_y]+dist[pos_x][pos_y])){
				dist[pos_x+1][pos_y]=Tab[pos_x+1][pos_y]+dist[pos_x][pos_y];
				q.push(n*(pos_x+1)+pos_y);
			}

			if(correct(pos_x-1,pos_y,Tab) and (min==-1 or min>Tab[pos_x-1][pos_y]+dist[pos_x][pos_y]) and (dist[pos_x-1][pos_y]==-1 or dist[pos_x-1][pos_y]>Tab[pos_x-1][pos_y]+dist[pos_x][pos_y])){
				dist[pos_x-1][pos_y]=Tab[pos_x-1][pos_y]+dist[pos_x][pos_y];
				q.push(n*(pos_x-1)+pos_y);
			}

			if(correct(pos_x,pos_y+1,Tab) and (min==-1 or min>Tab[pos_x][pos_y+1]+dist[pos_x][pos_y]) and (dist[pos_x][pos_y+1]==-1 or dist[pos_x][pos_y+1]>Tab[pos_x][pos_y+1]+dist[pos_x][pos_y])){
				dist[pos_x][pos_y+1]=Tab[pos_x][pos_y+1]+dist[pos_x][pos_y];
				q.push(n*(pos_x)+pos_y+1);
			}
			if(correct(pos_x,pos_y-1,Tab) and (min==-1 or min>Tab[pos_x][pos_y-1]+dist[pos_x][pos_y]) and (dist[pos_x][pos_y-1]==-1 or dist[pos_x][pos_y-1]>Tab[pos_x][pos_y-1]+dist[pos_x][pos_y])){
				dist[pos_x][pos_y-1]=Tab[pos_x][pos_y-1]+dist[pos_x][pos_y];
				q.push(n*(pos_x)+pos_y-1);
			}
		}
	}
	return min;
}

int main(){
	int n;
	while(cin>>n){
		vector<vector<int>> Tab(n,vector<int>(n));
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cin>>Tab[i][j];
			}
		}
		cout<<Dijstra(Tab)<<endl;
	}
}