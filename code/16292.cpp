#include <iostream>
using namespace std;
int N, M;
char dots[51][51];
bool visit[51][51];
bool found;
int index[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

void DFS(int x, int y, int xPrev, int yPrev){
    visit[x][y] = true;
    for (int i=0;i<4;i++){
        if (x+index[i][0] == xPrev && y+index[i][1] == yPrev) continue;
        if (visit[x+index[i][0]][y+index[i][1]] &&
            dots[x][y] == dots[x+index[i][0]][y+index[i][1]]){
                cout<<"Yes"<<endl;
                exit(0);
        }
        if (!visit[x+index[i][0]][y+index[i][1]] &&
            dots[x][y] == dots[x+index[i][0]][y+index[i][1]]){
                DFS(x+index[i][0],y+index[i][1],x,y);
        }
    }
}

int main(){
    cin>>N>>M;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=M;j++){
            cin>>dots[i][j];
        }
    }

    for (int i=1;i<=N;i++){
        for (int j=1;j<=M;j++){
            if (!visit[i][j]) DFS(i,j,0,0);
        }
    }

    cout<<"No"<<endl;

    return 0;
}
