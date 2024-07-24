#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
#include<unordered_map>

using namespace std;

/*
Prim's algorithm:
Starts from any node, pick the smallest edge from outside the MST and connect. (Grows one vertex at a time)

Kruskal'a algorithm:
Sort all the edges based on their weights, pick one edge at a time without creating a cycle. (Grows an edge at a time)
*/

/*
    We are using three vectors,
    mst : to check whether particular vertice is already marked in MST or not
    parent : to map vertices with used edge from parent node
    dist : to store the distance of the vertex from the parent node
    Below implmenetation takes O(n^2) time, you can optimize this by using priority_queue for finding smallest edge
*/
void prims(int v, vector<vector<int>> edges){
    unordered_map<int, vector<pair<int,int>>> adj;
    for(auto& edge : edges){
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }
    vector<int> parent(v, -1), dist(v,INT_MAX);
    vector<bool> mst(v, false);
    dist[0] = 0;
    parent[0] = -1;
    int mini, index;
    for(int i=0; i<v; i++){
        mini = INT_MAX;
        index = -1;
        for(int i=0; i<v; i++){
            if(mst[i]==false && dist[i] < mini){
                index = i;
                mini = dist[i];
            }
        }
        mst[index] = true;
        for(auto& e : adj[index]){
            if(mst[e.first]==false && dist[e.first] > e.second){
                dist[e.first] = e.second;
                parent[e.first] = index;
            }
        }
    }
    for(int i=0; i<v; i++){
        cout<<parent[i]<<" - "<<i<<" : "<<dist[i]<<endl;
    }
}

int findParent(int i, vector<int>& parent){
    if(parent[i]==i){
        return i;
    }
    return parent[i] = findParent(parent[i], parent);
}

bool unionSet(int i, int j, vector<int>& parent, vector<int>& rank){
    int ip = findParent(i, parent);
    int jp = findParent(j, parent);
    if(ip==jp){
        return false;
    }
    if(rank[ip]<rank[jp]){
        parent[ip] = jp;
    }else if(rank[ip]>rank[jp]){
        parent[jp] = ip;
    }else{
        parent[ip] = jp;
        rank[jp]++;
    }
    return true;
}

/*
    In kruskal, we select the smallest edge without creating the cycle, if the vertices of the nodes
    belongs to the same parent, then it will create a cycle and we can't include it in MST.
*/
void krushkalMST(int v, vector<vector<int>> edges){
    vector<int> parent(v+1);
    for(int i=0;i<=v;i++){
        parent[i] = i;
    }
    vector<int> rank(v+1,0);
    vector<vector<int>> ans;
    int count = v-1;
    sort(edges.begin(), edges.end(), [&](vector<int>& a, vector<int>& b){
        return a[2] < b[2];
    });
    for(int i=0;i<edges.size() && count>0; i++){
        if(unionSet(edges[i][0], edges[i][1], parent, rank)){
            count--;
            ans.push_back(edges[i]);
        }
    }
    //Using priority queue
    /*priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> q;
    for(auto& e : edges){
        q.push({e[2], {e[0], e[1]}});
    }
    pair<int, pair<int,int>> tmp;
    int ip, jp;
    while(!q.empty() && count){
        tmp = q.top();
        cout<<"Entered in while with count:"<<count<<", tmp:"<<tmp.second.first<<"-"<<tmp.second.second<<endl;
        q.pop();
        if(unionSet(tmp.second.first, tmp.second.second, parent, rank)==true){
            //Added in the MST
            count--;
            ans.push_back({tmp.second.first, tmp.second.second, tmp.first});
        }
    }
    */
    for(auto& edge : ans){
        cout<<edge[0]<<"-"<<edge[1]<<" : "<<edge[2]<<endl;
    }
}

int main(){
    int vertices = 8;

    // edge list
    vector<vector<int> > edges= { 
            { 0, 1, 1 }, { 1, 2, 2 }, { 0, 3, 4 }, { 3, 4, 1 },
            { 4, 7, 2 }, { 3, 7, 5 }, { 6, 7, 2 }, { 4, 5, 4 },
            { 4, 6, 1 }, { 5, 6, 2 } };
    // prims(vertices, edges);
    krushkalMST(vertices, edges);
    return 0;
}