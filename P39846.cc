#include <iostream>
#include <queue>
#include <vector>

using namespace std;


void max_dist(vector<vector<char>>& Mat){
	int max=-1;

	int f1,c1;
	cin>>f1>>c1;
	f1=f1-1;
	c1=c1-1;
	
	queue<int> q;
	int f=Mat.size();
	int c=Mat[0].size();

	vector<int> d (f*c,-1);

	if(Mat[f1][c1]!='X'){
		if(Mat[f1][c1]=='t'){
			max=0;
		}
		d[f1*c+c1]=0;
		q.push(f1*c+c1);
	}
	while(not q.empty()){
		int pos=q.front();
		q.pop();

		int pos_x=pos%c;
		int pos_y=pos/c;
		for(int i=0;i<4;++i){
			int pos_x1=pos_x;
			int pos_y1=pos_y;

			if(i==0){
				pos_x1=pos_x+1;
				pos_y1=pos_y;
			}
			else if(i==1){
				pos_x1=pos_x-1;
				pos_y1=pos_y;
			}
			else if(i==2){
				pos_x1=pos_x;
				pos_y1=pos_y-1;
			}
			else if(i==3){
				pos_x1=pos_x;
				pos_y1=pos_y+1;

			}
			if(pos_y1<f and pos_y1>=0 and pos_x1>=0 and pos_x1<c and d[pos_y1*c+pos_x1]==-1){
				if(Mat[pos_y1][pos_x1]=='X'){

				}
				else{
					d[pos_y1*c+pos_x1]=d[pos]+1;
					q.push(pos_y1*c+pos_x1);

					if(Mat[pos_y1][pos_x1]=='t' and max<d[pos_y1*c+pos_x1]){
						max=d[pos_y1*c+pos_x1];
					}
				}
			}
		}
	}

	if(max==-1){
		cout<<"no treasure can be reached"<<endl;
	}
	else{
		cout<<"maximum distance: "<<max<<endl;
	}
}

int main(){
	int f,c;
	cin>>f>>c;
	vector<vector<char>> Mat(f,vector<char>(c));
	for(int i=0;i<f;++i){
		for(int j=0;j<c;++j){
			cin>>Mat[i][j];
		}
	}
	max_dist(Mat);
}