#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

void Greedy_BFS(vector<vector<int>> adjMatrix){
    int n = adjMatrix.size();
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<bool> visited(n, false);

    int sv = 0, target = 5;
    pq.push(make_pair(0, sv));

    while(!pq.empty()){
        int x = pq.top().second;
        while (!pq.empty()) {
            pq.pop();
        }
        cout<<x<<" ";
        visited[x] = true;

        if(x == target){
            break;
        }

        for(int i=0; i<n; i++){
            if(adjMatrix[x][i] != 0){
                if(visited[i]){continue;}
                pq.push(make_pair(adjMatrix[x][i], i));
            }
        }
    }
}

int main(){
    int n = 6, e = 8;
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    adjMatrix[0][1] = 1;
    adjMatrix[0][5] = 10;
    adjMatrix[1][2] = 2;
    adjMatrix[1][3] = 1;
    adjMatrix[2][4] = 5;
    adjMatrix[3][4] = 3;
    adjMatrix[3][5] = 4;
    adjMatrix[4][5] = 2;

    Greedy_BFS(adjMatrix);
    return 0;
}