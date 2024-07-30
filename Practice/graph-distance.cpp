#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<climits>
#include<algorithm>
#include<unordered_map>

using namespace std;

//For unweighted shortest source to distance travel using BFS
void shortestDistanceUndirected(vector<vector<int> >& edges, int s, int d, int vertices){

    vector<vector<int>> adj(vertices);
    for (auto edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    vector<int> parent(vertices, -1);
    vector<bool> visited(vertices, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    int node, currentNode = d;
    while(!q.empty()){
        node = q.front();
        q.pop();
        for(auto& next : adj[node]){
            if(!visited[next]){
                parent[next] = node;
                visited[next] = true;
                q.push(next);
            }
        }
    }
    vector<int> ans;
    ans.emplace_back(currentNode);
    while(currentNode != s){
        currentNode = parent[currentNode];
        ans.push_back(currentNode);

    }
    reverse(ans.begin(), ans.end());
    for(auto& n : ans){
        cout<<n<<" ";
    }
    cout<<endl;
}

void printShortestDistanceDirected(vector<vector<int> >& edges, int s, int d, int vertices){
    vector<vector<pair<int,int>>> adj(vertices);
    vector<int> inDegree(vertices, 0);
    vector<int> dist(vertices, INT_MAX);
    for (auto edge : edges) {
        adj[edge[0]].push_back({edge[1], edge[2]});
        inDegree[edge[1]]++;
    }
    //Get topological order of the graph
    vector<int> topo;
    queue<int> q;
    for(int i=0; i<vertices; i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    int node;
    while(!q.empty()){
        node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto& next : adj[node]){
            //Removing the edges at a time of node having 0 inDegree
            if(--inDegree[next.first]==0){
                q.push(next.first);
            }
        }
    }
    dist[s] = 0;
    for(int& element : topo){
        if(dist[element]!=INT_MAX){
            for(auto& next : adj[element]){
                if(dist[next.first] > dist[element] + next.second){
                    dist[next.first] = dist[element] + next.second;

                }
            }
        }
    }
    for(auto& ele : dist){
        cout<<ele<<" ";
    }    
    cout<<endl;
}

//Time complexity : O(E * log v)
void dijkstraDistance(vector<vector<int> >& edges, int s, int vertices){
    vector<vector<pair<int,int>>> adj(vertices);
    vector<int> dist(vertices, INT_MAX);
    dist[s] = 0;
    for (auto edge : edges) {
        adj[edge[0]].push_back({edge[1], edge[2]});
        // Uncomment below if you wanna check for undirected
        // adj[edge[1]].push_back({edge[0], edge[2]});
    }
    //First will indicate distance, other will indicate node
    set<pair<int,int>> ss;
    ss.insert({0,0});
    pair<int,int> tmp;
    while(ss.size()>0){
        tmp = *ss.begin();
        ss.erase(ss.begin());
        for(auto& next : adj[tmp.second]){
            if(dist[next.first] > tmp.first + next.second){
                if(ss.count({dist[next.first], next.first})){
                    ss.erase({dist[next.first], next.first});
                }
                dist[next.first] = tmp.first + next.second;
                ss.insert({dist[next.first], next.first});
            }
        }
    }
    for(auto& ele : dist){
        cout<<ele<<" ";
    }    
    cout<<endl;
}

//Can work with negative edges as well, T.C : O(V*E);
void bellmanFordDistance(vector<vector<int> >& edges, int s, int vertices){
    vector<int> dist(vertices, INT_MAX);
    dist[s] = 0;
    for(int i=1; i<vertices; i++){
        for(auto& e : edges){
            if(dist[e[0]]!=INT_MAX && dist[e[1]] > dist[e[0]] + e[2]){
                dist[e[1]] = dist[e[0]] + e[2];
            }
        }
    }
    //Check whether there is negative edge cycle or not
    bool flag = false;
    for(auto& e : edges){
        if(dist[e[0]]!=INT_MAX && dist[e[1]] > dist[e[0]] + e[2]){
            flag = true;
            break;
        }
    }
    if(flag){
        cout<<"There is a negative edge cycle present in the graph. \n";
    }
    for(auto& ele : dist){
        cout<<ele<<" ";
    }    
    cout<<endl;
}

void floydWarshalDistance(vector<vector<int> >& edges, int v){
    vector<vector<int>> dist(v, vector<int>(v, INT_MAX));
    for(int i=0; i<v; i++){
        dist[i][i] = 0;
    }
    for(auto& e : edges){
        dist[e[0]][e[1]] = e[2];
        //dist[e[1]][e[0]] = e[2];
    }
    for(int k=0; k<v; k++){
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                //Relax using kth node at a time
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    cout<<"Distance between all the nodes are:\n";
    for(auto& r : dist){
        for(auto& x : r){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int v = 8;
    int s = 0, d = 6;
    // edge list
    vector<vector<int> > edges= { 
            { 0, 1, 1 }, { 1, 2, 2 }, { 0, 3, 4 }, { 3, 4, 1 },
            { 4, 7, 2 }, { 3, 7, 5 }, { 6, 7, 2 }, { 4, 5, 4 },
            { 4, 6, 1 }, { 5, 6, 2 } };

    
    //Shortest distance in undirected unweighted graph
    //shortestDistanceUndirected(edges, s, d, v);

    //printShortestDistanceDirected(edges, s, d, v);

    //dijkstraDistance(edges, s, v);
    //bellmanFordDistance(edges, s, v);
    
    floydWarshalDistance(edges, v);

    return 0;
}