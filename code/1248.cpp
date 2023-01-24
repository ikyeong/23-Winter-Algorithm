#include <iostream>
using namespace std;
int N;
int seq[11];
char signMatrix[11][11];

bool check(int x){ //index 행의 조건만 검사하는 함수
    int sum = 0;
    for (int i=x;i>0;i--){
        sum += seq[i];
        if (signMatrix[i][x] == '0' && sum != 0) return false;
        if (signMatrix[i][x] == '+' && sum <= 0) return false;
        if (signMatrix[i][x] == '-' && sum >= 0) return false;
    }
    return true;
}

void DFS(int x){
    if (x == N+1){
        for (int i=1;i<=N;i++)
            cout<<seq[i]<<" ";
        exit(0); //재귀함수 종료
    }else{
        for (int i=-10;i<=10;i++){
            seq[x] = i;
            if (check(x)) DFS(x+1);
        }
    }
}

int main(){
    cin>>N;
    for (int i=1;i<=N;i++){
        for (int j=i;j<=N;j++){
            cin>>signMatrix[i][j];
        }
    }

    DFS(1);

    return 0;
}

// bool check(){ //모든 조건을 다 검사하는 함수(시간초과)
//     for (int i=1;i<=N;i++){
//         int sum = seq[i];
//         for (int j=i+1;j<=N;j++){
//             sum += seq[j];
//             if (signMatrix[i][j] == '0' && sum != 0) return false;
//             if (signMatrix[i][j] == '+' && sum <= 0) return false;
//             if (signMatrix[i][j] == '-' && sum >= 0) return false;
//         }
//     }
//     return true;
// }
