#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int N, L, R;
int pop[51][51], popNum, countryNum; //인구수
bool visit[51][51]; //연합여부
int idx[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
vector<pair<int,int>> v;

void DFS(int a, int b){
    for (int i=0;i<4;i++){
        int x = a + idx[i][0], y = b + idx[i][1];
        if (x<1 || x>N || y<1 || y>N || visit[x][y]) continue;
        int diff = abs(pop[a][b] - pop[x][y]);
        if (L<=diff && diff<=R){
            v.push_back(pair<int,int>(x,y));
            visit[x][y] = true;
            popNum += pop[x][y];
            countryNum ++;
            DFS(x,y);
        }
    }
}

int main(){
    cin>>N>>L>>R;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            cin>>pop[i][j];
        }   
    }
    int day = 0;
    while (true){
        bool chk = false;
        memset(visit, false, sizeof(visit));
        for (int i=1;i<=N;i++){
            for (int j=1;j<=N;j++){
                if (visit[i][j]) continue;

                visit[i][j] = true;
                popNum = pop[i][j];
                countryNum = 1;
                v.clear();
                v.push_back(pair<int,int>(i,j));                
                DFS(i,j);

                if (countryNum > 1){ // 국경이 열린 경우 인구수 조정
                    chk = true;
                    for (int i=0;i<v.size();i++){
                        int x = v[i].first;
                        int y = v[i].second;
                        pop[x][y] = popNum/countryNum;
                    }
                }
            }
        }
        if (!chk) break;
        day ++;
    }
    cout<<day<<endl;
    return 0;
}
