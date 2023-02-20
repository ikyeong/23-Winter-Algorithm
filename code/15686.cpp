#include <iostream>
#include <queue>
using namespace std;
int N, M, map[51][51], mapCopy[51][51], ans = 1000000000; 
int chicken[2501], num;
int selected[13];
queue<int> home;

bool valid(int x, int y){
    if (0<=x && x<N && 0<=y && y<N) return true;
    return false;
}

int getDistance(){
    int distance = 0;
    queue<int> q;
    bool visit[51][51] = {false, };
    for (int i=0;i<M;i++){
        int x = selected[i]/N, y = selected[i]%N;
        mapCopy[x][y] = 2;
        q.push(selected[i]);
        visit[x][y] = true;
    }
    int count = 0;
    while(!q.empty()){
        int size = q.size();
        for (int i=0;i<size;i++){
            int loc = q.front();
            q.pop();
            int x = loc/N, y = loc%N;
            if (mapCopy[x][y] == 1){
                distance += count;
            }
            if (valid(x-1,y) && !visit[x-1][y]){
                q.push(loc-N); visit[x-1][y] = true;
            } 
            if (valid(x+1,y) && !visit[x+1][y]){
                q.push(loc+N); visit[x+1][y] = true; 
            } 
            if (valid(x,y-1) && !visit[x][y-1]){
                q.push(loc-1); visit[x][y-1] = true;
            } 
            if (valid(x,y+1) && !visit[x][y+1]){
                q.push(loc+1); visit[x][y+1] = true;
            }
        }
        count++;
    }
    for (int i=0;i<M;i++){
        int x = selected[i]/N, y = selected[i]%N;
        mapCopy[x][y] = 0;
    }
    return distance;
}

void DFS(int pos, int depth){
    if (depth == M){
        ans = min(ans, getDistance());
    }else{
        for (int i=pos;i<num;i++){
            selected[depth] = chicken[i];
            DFS(i+1,depth+1);
        }
    }
}

int main(){
    cin>>N>>M;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin>>map[i][j];
            
            if (map[i][j] == 2) chicken[num++] = i*N+j;
            else mapCopy[i][j] = map[i][j];
            
            if (map[i][j] ==1) home.push(i*N+j);
        }
    }
    DFS(0,0);
    cout<<ans<<endl;
    return 0;
}
