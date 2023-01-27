#include <iostream>
using namespace std;
int N, M, maxValue;
int paper[5][5];

int main(){
    cin>>N>>M;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=M;j++){
            char ch;
            cin>>ch;
            paper[i][j] = ch - '0';
        }
    }

    for (int idx=0;idx<(1<<N*M);idx++){ //0 : 가로, 1 : 세로
        int row = 0;
        int col = 0;

        int copy = idx;
        for (int i=1;i<=N;i++){
            int num = 0;
            for (int j=1;j<=M;j++){
                if (!(copy & 1)){
                    num = num*10 + paper[i][j];
                }else{ //1이 나오면 지금까지의 값 더하고 초기화
                    row += num;
                    num = 0;
                }
                copy = copy >> 1;
            }
            row += num;
        }

        copy = idx;
        for (int i=1;i<=M;i++){
            int num = 0;
            int temp = idx>>(i-1);
            for (int j=1;j<=N;j++){
                if (temp & 1){
                    num = num*10 + paper[j][i];
                }else{
                    col += num;
                    num = 0;
                }
                temp = temp>>M;
            }
            col += num;
        }
        maxValue = max(maxValue, row + col);
    }

    cout<<maxValue<<endl;

    return 0;
}
