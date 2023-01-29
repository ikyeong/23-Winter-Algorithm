#include <iostream>
#include <queue>
using namespace std;
int N, M, V;
bool edge[1001][1001];
bool visit[1001];

void DFS(int pos){
    if (!visit[pos]){
        cout<<pos<<" ";
        visit[pos] = true;
        for (int i=1;i<=N;i++){
            if (edge[pos][i]){
                DFS(i);
            }
        }
    }
}

void BFS(int pos){
    queue<int> q;
    q.push(pos);
    visit[pos] = true;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for (int i=1;i<=N;i++){
            if (edge[node][i] && !visit[i]){
                q.push(i);
                visit[i] = true;
            } 
        }
    }
}

int main(){
    cin>>N>>M>>V;
    for (int i=0;i<M;i++){
        int a, b;
        cin>>a>>b;
        edge[a][b] = true;
        edge[b][a] = true;
    }

    DFS(V);
    fill_n(visit, sizeof(visit), false);
    cout<<endl;
    BFS(V);

    return 0;
}
