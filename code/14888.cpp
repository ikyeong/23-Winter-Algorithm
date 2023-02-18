#include <iostream>
using namespace std;
int N, seq[12], op[11];
int order[11], visit[11];
int ans[2] = {1000000000, -1000000000};

void evaluate(int pos){
    if (pos == N-1){
        int value = seq[1];
        for (int i=0;i<N-1;i++){
            if (order[i] == 0) value = value + seq[i+2];
            else if (order[i] == 1) value = value - seq[i+2];
            else if (order[i] == 2) value = value * seq[i+2];
            else if (order[i] == 3) value = value / seq[i+2];
            
        }
        ans[0] = min(ans[0],value);
        ans[1] = max(ans[1],value);
    }else{
        for (int i=1;i<N;i++){
            if (!visit[i]){
                order[pos] = op[i];
                visit[i] = true;
                evaluate(pos+1);
                visit[i] = false;
            }
        }
    }
}

int main(){
    cin>>N;
    for (int i=1;i<=N;i++){
        cin>>seq[i];
    }
    int index = 1;
    for (int i=0;i<4;i++){
        int x;
        cin>>x;
        for (int j=0;j<x;j++){
            op[index++] = i;
        }
    }
    
    evaluate(0);

    cout<<ans[1]<<endl<<ans[0]<<endl;

    return 0;
}
