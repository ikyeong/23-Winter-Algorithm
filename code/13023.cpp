#include <iostream>
#include <vector>
using namespace std;
int N, M;
bool visit[2000];
vector<vector<int>> friends(2000);
// bool friends[2000][2000];

void DFS(int i, int count){ // 배열 사용시 시간초과
    if (count == 5) {
        cout<<1<<endl;
        exit(0);
    }
    visit[i] = true;
    for (auto x=friends[i].begin();x!=friends[i].end();x++){
        if (!visit[*x]) DFS(*x,count+1);
    }
    // for (int x=0;x<N;x++){
    //     if (friends[i][x] && !visit[x]) DFS(x, count+1);
    // }
    visit[i] = false;
}

int main(){
    cin>>N>>M;
    for (int i=0;i<M;i++){
        int x,y;
        cin>>x>>y;
        // friends[x][y] = true;
        // friends[y][x] = true;
        friends[x].push_back(y);
        friends[y].push_back(x);
    }

    for (int i=0;i<N;i++){
        DFS(i,1);
    }
    
    cout<<0<<endl;

    return 0;
}
