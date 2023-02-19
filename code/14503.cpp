#include <iostream>
using namespace std;
int N, M, map[50][50], visit[50][50], cleaned;
int x, y, direction;
int fwd[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

bool check(){
    if (x-1>=0 && map[x-1][y] == 0 && !visit[x-1][y])
        return false;
    if (x+1<50 && map[x+1][y] == 0 && !visit[x+1][y])
        return false;
    if (y-1>=0 && map[x][y-1] == 0 && !visit[x][y-1])
        return false;
    if (y+1<50 && map[x][y+1] == 0 && !visit[x][y+1])
        return false;
    return true;
}

bool clean(){
    if (map[x][y] == 0 && !visit[x][y]){ //현재 칸이 아직 청소되지 않은 경우
        visit[x][y] = true;
        cleaned ++;
        return true;
    }
    if (check()){ // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우 
        int back = (direction+2)%4;
        if (map[x+fwd[back][0]][y+fwd[back][1]] == 1) return false;
        x = x + fwd[back][0];
        y = y + fwd[back][1];
        return true;
    }
    //현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
    direction = (direction+3)%4;
    if (map[x+fwd[direction][0]][y+fwd[direction][1]] == 0 && 
        !visit[x+fwd[direction][0]][y+fwd[direction][1]]){
            x = x + fwd[direction][0];
            y = y + fwd[direction][1];
    }
    return true;
}

int main(){
    cin>>N>>M;
    cin>>x>>y>>direction;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++) cin>>map[i][j];
    }

    while (clean()){}

    cout<<cleaned<<endl;
    return 0;
}
