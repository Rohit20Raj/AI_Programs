#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>> adjMatrix, int n){
    queue<int> pendingNodes;
    vector<bool> visited(n, false);
    int sv = 0;

    pendingNodes.push(sv);

    int root;

    while(!pendingNodes.empty()){
        root = pendingNodes.front();
        cout<<root<<" ";
        for(int i=0; i<n; i++){
            if(adjMatrix[root][i] == 1){
                if(visited[i]){
                    continue;
                }
                pendingNodes.push(i);
                visited[i] = true;
            }
        }
        pendingNodes.pop();
    }
}

void DFS(vector<vector<int>> adjMatrix, int n){
    stack<int> pendingNodes;
    vector<bool> visited(n, false);
    int sv = 0;

    pendingNodes.push(sv);

    int root;

    while(!pendingNodes.empty()){
        root = pendingNodes.top();
        cout<<root<<" ";
        pendingNodes.pop();
        for(int i=0; i<n; i++){
            if(adjMatrix[root][i] == 1){
                if(visited[i]){
                    continue;
                }
                pendingNodes.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    int n = 5, e = 6;
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    adjMatrix[0][1] = 1;
    adjMatrix[0][2] = 1;
    adjMatrix[1][3] = 1;
    adjMatrix[1][4] = 1;
    adjMatrix[2][3] = 1;
    adjMatrix[2][4] = 1;
    adjMatrix[4][3] = 1;

    cout<<"BFS traversal: ";
    BFS(adjMatrix, n);

    cout<<endl<<"DFS traversal: ";
    DFS(adjMatrix, n);

    return 0;
}