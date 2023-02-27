#include<iostream>
#include<queue>
using namespace std;
int N, visit[2001][2001];

int BFS(){
    int count = 0;
    queue<pair<int,int>> q;
    q.push(pair<int,int>(1,0));
    visit[1][0] = true;
    while(!q.empty()){
        int size = q.size();
        for (int i=0;i<size;i++){
            auto front = q.front();
            q.pop();
            if (front.first == N){
                return count;
            }
            if (!visit[front.first][front.first]){ // 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
                q.push(pair<int,int>(front.first,front.first));
                visit[front.first][front.first] = true;
            }
            if (!visit[front.first-1][front.second]){ // 화면에 있는 이모티콘 중 하나를 삭제한다.
                q.push(pair<int,int>(front.first-1,front.second));
                visit[front.first-1][front.second] = true;
            }
            if (front.first+front.second<=2000 && !visit[front.first+front.second][front.second]){ // 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
                q.push(pair<int,int>(front.first+front.second,front.second));
                visit[front.first+front.second][front.second] = true;
            }
        }
        count++;
    }
    return count;
}

int main(){
    cin>>N;
    cout<<BFS()<<endl;
    return 0;
}
