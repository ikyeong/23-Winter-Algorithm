#include <iostream>
using namespace std;
int w,h;
int map[51][51];
bool visit[51][51];

int idx1[8] = {-1,-1,-1,0,0,1,1,1};
int idx2[8] = {-1,0,1,-1,1,-1,0,1};

void DFS(int i, int j){
    visit[i][j] = true;
    /*
        -1 -1
        -1  0
        -1  1
         0 -1
         0  1
         1 -1
         1  0
         1  1
    */
    for (int k=0;k<8;k++){
        if ( i+idx1[k]<1 || h<i+idx1[k] ) continue;
        if ( j+idx2[k]<1 || w<j+idx2[k] ) continue;
        if (map[i+idx1[k]][j+idx2[k]] == 1 && !visit[i+idx1[k]][j+idx2[k]])
            DFS(i+idx1[k], j+idx2[k]);
    }
    
}

int main(){
    while (true){
        cin>>w>>h;
        if (w == 0) exit(0);
        for (int i=1;i<=h;i++){
            for (int j=1;j<=w;j++){ //1 : 땅, 0 : 바다
                cin>>map[i][j];
            } 
        }

        int count = 0;
        for (int i=1;i<=h;i++){
            for (int j=1;j<=w;j++){
                if (map[i][j] == 1 && !visit[i][j]){
                    DFS(i,j);
                    count ++;
                } 
            }
        }
        cout<<count<<endl; 
        /*fill_n(visit, sizeof(visit), false);
        * 이거는 이차원이상 배열에 적용되지 않는다.
        */
        fill_n(&visit[0][0], sizeof(visit), false);
    }
    return 0;
}
