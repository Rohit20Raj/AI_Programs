#include <bits/stdc++.h>
using namespace std;

int findMinVertex(int* distance, bool* visited, int n){
    int minVertex = -1;
    for(int i=0; i<n; i++){
        if(!visited[i] && (minVertex == -1 || distance[i]<distance[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}

void djikstra(vector<vector<int>> &edges, int n){
    int* distance = new int[n];
    bool* visited = new bool[n];

    for(int i=0; i<n; i++){
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[0] = 0;

    for(int i=0; i<n-1; i++){
        int minVertex = findMinVertex(distance, visited, n);
        visited[minVertex] = true;
        for(int j=0; j<n; j++){
            if(edges[minVertex][j] != 0 && !visited[j]){
                int dist = distance[minVertex]+edges[minVertex][j];
                if(dist<distance[j]){
                    distance[j]=dist;
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
}

int main(){
    int n=5, e=9;
    // cin>>n>>e; 

    // int** edges = new int* [n];
    // for(int i=0; i<n; i++){
    //     edges[i] = new int[n];
    //     for(int j=0; j<n; j++){
    //         edges[i][j] = 0;
    //     }
    // }
    vector<vector<int>> edges(n, vector<int> (n,0));

    // for(int i=0; i<e; i++){
    //     int f, s, w;
    //     cin>>f>>s>>w;
    //     edges[f][s] = w;
    //     edges[s][f] = w;
    // }
    edges[0][1] = 3;
    edges[0][4] = 2;
    edges[0][5] = 5;
    edges[1][2] = 3;
    edges[2][5] = 6;
    edges[2][3] = 2;
    edges[3][5] = 2;
    edges[3][4] = 3;
    edges[4][5] = 4;
    
    // edges[1][0] = 3;
    // edges[4][0] = 2;
    // edges[5][0] = 5;
    // edges[2][1] = 3;
    // edges[5][2] = 6;
    // edges[3][2] = 2;
    // edges[5][3] = 2;
    // edges[4][3] = 3;
    // edges[5][4] = 4;
    cout<<endl;
    djikstra(edges, n);

    return 0;
}