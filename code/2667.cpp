#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N;
bool map[26][26], visit[26][26];
int index[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

bool valid(int i, int j){
    if (i<1 || N<i) return false;
    if (j<1 || N<j) return false;
    if (map[i][j] && !visit[i][j]) return true;
    return false;
}

int BFS(int i, int j){
    int count = 1;
    queue<pair<int,int>> q;
    q.push(pair<int,int>(i,j));
    visit[i][j] = true;
    while(!q.empty()){
        auto entry = q.front();
        q.pop();
        
        for (int k=0;k<4;k++){
            if (valid(entry.first+index[k][0],entry.second+index[k][1])){
                count++;
                q.push(pair<int,int>(entry.first+index[k][0],entry.second+index[k][1]));
                visit[entry.first+index[k][0]][entry.second+index[k][1]] = true;
            }
        }
    }
    return count;
}

int main(){
    cin>>N;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            char input;
            cin>>input;
            if (input == '1') map[i][j] = true;
        }
    }
    int count = 0;
    int houseCount[400];
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            if (map[i][j] && !visit[i][j]){
                houseCount[count++] = BFS(i,j);
            }
        }
    }

    cout<<count<<endl;
    sort(houseCount, houseCount+count);
    for (int i=0;i<count;i++) cout<<houseCount[i]<<endl;
    
    return 0;
}
