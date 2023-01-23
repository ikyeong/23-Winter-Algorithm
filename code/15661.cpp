#include<iostream>
using namespace std;
int N;
int ability[21][21];
bool check[21];
int res = 2000;

int getAbility(){ //두 팀 능력치의 차를 구하는 함수
    int start = 0;
    int link = 0;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            if (check[i] == check[j] && check[i] == true) 
                start += ability[i][j];
            if (check[i] == check[j] && check[i] == false) 
                link += ability[i][j];
        }
    }
    return abs(start-link);
}

//x는 check된 개수, pos는 배열의 다음 index
void DFS(int x, int pos){
    if (x == N-1){ 
        res = min(res,getAbility());
    }else{
        for (int i=pos;i<=N;i++){
            check[i] = true;
            res = min(res, getAbility()); //하나 이상 check되어 있을때도 능력치차 구하기
            DFS(x+1,i+1);
            check[i] = false;
        }
    }
}

int main(){
    
    cin>>N;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            cin>>ability[i][j];
        }
    }

    DFS(0, 1);

    cout<<res<<endl;
}
