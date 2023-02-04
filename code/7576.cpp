#include <iostream>
#include <queue>
using namespace std;
int N, M;
int box[1001][1001];
int index[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

bool isValid(int i, int j){
    if (i<1 || N<i) return false;
    if (j<1 || M<j) return false;
    if (box[i][j] == 0) return true;
    return false;
}

bool check(){
    for (int i=1;i<=N;i++){
        for (int j=1;j<=M;j++){
            if (box[i][j] == 0) return false;
        }
    }
    return true;
}

int main(){
    cin>>M>>N;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=M;j++) cin>>box[i][j];
    }

    queue<pair<int,int>> q;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=M;j++){
            if (box[i][j] == 1) q.push(pair<int,int>(i,j));
        }
    }
    int count = -1;
    while(!q.empty()){
        int size = q.size();
        for (int i=0;i<size;i++){
            auto entry = q.front();
            q.pop();
            for (int j=0;j<4;j++){
                if (isValid(entry.first+index[j][0], entry.second+index[j][1])){
                    q.push(pair<int,int>(entry.first+index[j][0], entry.second+index[j][1]));
                    box[entry.first+index[j][0]][entry.second+index[j][1]] = 1;
                }
            }
        }
        count++;
    }

    if (check()) cout<<count<<endl;
    else cout<<-1<<endl;

    return 0;
}
