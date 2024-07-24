#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
//To find the articulation point (vertices, on removal of whose create a disconnected component)
void dfs(int node, int parent, int& timer, unordered_map<int, vector<int>>& adj, 
            vector<int>& low, vector<int>& discover, vector<bool>& visited, vector<int>& ans){
    visited[node] = true;
    low[node] = discover[node] = timer++;
    int child = 0;
    for(auto& next : adj[node]){
        if(next==parent){
            continue;
        }
        if(visited[next]==false){
            dfs(next, node, timer, adj, low, discover, visited, ans);
            low[node] = min(low[next], low[node]);
            if(low[next]>=discover[node] && parent!=-1){
                ans.push_back(node);
            }
            child++;
        }else{
            low[node] = min(low[node], discover[next]);
        }
    }
    if(parent==-1 && child>1){
        ans.push_back(node);
    }
}

vector<int> getArticulationPoint(vector<vector<int>>& edges){
    vector<int> ans;
    unordered_map<int, vector<int>> adj;
    for(int i=0; i<edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    int timer = 0;
    int n = adj.size();
    vector<int> low(n, -1);
    vector<int> discover(n, 1000000);
    vector<bool> visited(n, false);
    dfs(0, -1, timer, adj, low, discover, visited, ans);
    return ans;
}


int main(){
    vector<vector<int> > edges= { 
            { 0, 1, 1 }, { 1, 2, 2 }, { 0, 3, 4 }, { 3, 4, 1 },
            { 4, 7, 2 }, { 3, 7, 5 }, { 6, 7, 2 }, { 4, 5, 4 },
            { 4, 6, 1 }, { 5, 6, 2 } };
    vector<int> ans = getArticulationPoint(edges);
    cout<<"Articulation points are: \n";
    for(int& c : ans){
        cout<<c<<" ";
    }
    cout<<endl;
    return 0;
}