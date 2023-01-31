#include <iostream>
#include <queue>
using namespace std;
int N, M, minCount = 10000;
bool maze[101][101], visit[101][101];

int idx[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

void DFS(int i, int j, int count){ //시간초과 오류
    if (i == N && j == M){
        minCount = min(minCount, count);
    }else{
        visit[i][j] = true;
        for (int k=0;k<4;k++){
            if (i+idx[k][0] < 1 && N < i+idx[k][0]) continue;
            if (j+idx[k][1] < 1 && M < j+idx[k][1]) continue;
            if (maze[i+idx[k][0]][j+idx[k][1]] && !visit[i+idx[k][0]][j+idx[k][1]]) 
                DFS(i+idx[k][0],j+idx[k][1],count+1);
        }
        visit[i][j] = false;
    }
}

bool isValid(int i, int j){
    if (i<1 && N<i) return false;
    if (j<1 && M<j) return false;
    if (maze[i][j] && !visit[i][j]) return true;
    return false;
}

void BFS(){ // end index에 처음 도달하는 것이 최단 길이. 모두 탐색할 필요X
    int count = 1;
    bool reached = false;
    queue<pair<int,int>> q;
    q.push(pair<int,int>(1,1));
    visit[1][1] = true;
    while (!q.empty()){
        int size = q.size();
        for (int j=0;j<size;j++){
            auto entry = q.front();
            q.pop();
            if (entry.first == N && entry.second == M){
                reached = true;
                break;
            }
            for (int i=0;i<4;i++){
                if ( isValid(entry.first+idx[i][0], entry.second+idx[i][1])){
                    q.push(pair<int,int>(entry.first+idx[i][0],entry.second+idx[i][1]));
                    visit[entry.first+idx[i][0]][entry.second+idx[i][1]] = true;
                }   
            }
        }
        if (reached) break;
        count++;
    }
    cout<<count<<endl;
}

int main(){
    cin>>N>>M;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=M;j++){
            char c;
            cin>>c;
            if (c == '1') maze[i][j] = true; 
        }
    }

    BFS();

    // DFS(1,1,1);
    // cout<<minCount<<endl;

    return 0;
}
