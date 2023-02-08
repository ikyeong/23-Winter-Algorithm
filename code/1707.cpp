#include <iostream>
#include <vector>
using namespace std;
int V,E;
vector<int> visit(20001);
vector<vector<int>> edge(20001);
string ans = "YES";

void DFS(int x, int section){
    visit[x] = section;
    for (auto it=edge[x].begin();it!=edge[x].end();it++){
        if (ans == "NO") break;
        if (visit[*it] == section){
            ans = "NO";
            break;
        }else if (visit[*it] == 0){
            DFS(*it, section%2+1);
        }
    }
}

int main(){
    int testCase;
    cin>>testCase;
    while (testCase-->0){
        ans = "YES";
        edge.assign(20001, vector<int>(0)); // 벡터초기화
        visit.assign(20001, 0);

        cin>>V>>E;
        while(E-->0){
            int x,y;
            cin>>x>>y;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }

        for (int i=1;i<=V;i++){
            if (visit[i] == 0)
                DFS(i,1);
        }

        cout<<ans<<endl;        
    }
    return 0;
}
