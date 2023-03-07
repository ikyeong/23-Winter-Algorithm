#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n,q;
bool visit[5001];
vector<vector<pair<int,int>>> graph(5001);

int main(){
    cin>>n>>q;
    for (int i=1;i<n;i++){
        int a, b, usado;
        cin>>a>>b>>usado;
        graph[a].push_back(pair<int,int>(b,usado));
        graph[b].push_back(pair<int,int>(a,usado));
    }
    for (int i=0;i<q;i++){
        memset(visit,false,sizeof(visit));
        int k, v, count = 0; 
        queue<int> q; // 추천된 영상에서 또 추천되는 영상이 있는지 확인해야됨
        cin>>k>>v;
        q.push(v);
        visit[v] = true;
        while (!q.empty()){
            int entry = q.front();
            q.pop();
            for (int j=0;j<graph[entry].size();j++){
                if (!visit[graph[entry][j].first] && graph[entry][j].second >= k){
                    count ++;
                    visit[graph[entry][j].first] = true;
                    q.push(graph[entry][j].first);
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
