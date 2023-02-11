#include <iostream>
#include <queue>
using namespace std;
int n,k;
bool visit[100001]; //메모리 초과 오류 -> visit배열로 중복된 값이 queue에 들어가지 않도록 함.

bool valid(int x){ //OutOfBounds 오류 -> queue에 넣을 값이 정해진 범위 안에 있는지 확인
    if (0<=x && x<=100000) return true;
    return false;
}

void BFS(){
    queue<int> q;
    q.push(n);
    bool found = false;
    int count = 0;
    visit[n] = true;
    while (!q.empty()){
        int size = q.size();
        for (int i=0;i<size;i++){
            int x = q.front();
            if (x == k){
                found = true;
                break;
            }
            if (valid(x*2) && !visit[x*2]){
                q.push(x*2);
                visit[x*2] = true;
            } 
            if (valid(x+1) && !visit[x+1]){
                q.push(x+1);
                visit[x+1] = true;
            }
            if (valid(x-1) && !visit[x-1]){
                q.push(x-1);
                visit[x-1] = true;
            }
            q.pop();
        }
        if (found) break;
        count++;
    }
    cout<<count<<endl;
}

int main(){
    cin>>n>>k;
    BFS();
    return 0;
}
