#include <iostream>
using namespace std;
int N, S, count, sum;
int seq[21];

void evaluate(int sum){
    if (sum == S) count++;
}

void DFS(int x, int pos){
    if (x != N){
        for (int i=pos;i<=N;i++){
            sum += seq[i];
            evaluate(sum);
            DFS(x+1,i+1);
            sum -= seq[i];
        }
    }
}

int main(){
    cin>>N>>S;

    for (int i=1;i<=N;i++) cin>>seq[i];

    DFS(0,1);

    cout<<count<<endl;

    return 0;
}
