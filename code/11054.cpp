#include <iostream>
using namespace std;
int N, seq[1001], ans;
int DP[1001][2]; //DP[i][0] : i번째 index를 끝으로 만들 수 있는 증가하는 수열의 최소길이
                 //DP[i][1] : i번째 index를 시작으로 만들 수 있는 감소하는 수열의 최대길이
int main(){
    cin>>N;
    for (int i=1;i<=N;i++) cin>>seq[i];

    for (int i=1;i<=N;i++){
        int maxLength;
        //증가하는 수열
        maxLength = 0;
        for (int j=i-1;j>0;j--){
            if (seq[j] < seq[i]) maxLength = max(maxLength,DP[j][0]);
        }
        DP[i][0] = maxLength + 1;

        //감소하는 수열
        maxLength = 0;
        for (int j=N+2-i;j<=N;j++){
            if (seq[N+1-i] > seq[j]) maxLength = max(maxLength,DP[j][1]);
        }
        DP[N+1-i][1] = maxLength + 1;
    }

    for (int i=1;i<=N;i++){
        ans = max(ans, DP[i][0]+DP[i][1]-1);
    }

    cout<<ans<<endl;

    return 0;
}
