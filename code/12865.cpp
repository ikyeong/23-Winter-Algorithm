#include <iostream>
using namespace std;
int N, K;
int obj[101][2];
int dp[101][100001];

int main(){
    cin>>N>>K;
    for (int i=1;i<=N;i++){
        cin>>obj[i][0]>>obj[i][1];   
    }    
    for (int i=1;i<=N;i++){
        for (int j=1;j<=K;j++){
            if (obj[i][0] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j-obj[i][0]]+obj[i][1],dp[i-1][j]);
        }
    }
    cout<<dp[N][K]<<endl;
    return 0;
}
