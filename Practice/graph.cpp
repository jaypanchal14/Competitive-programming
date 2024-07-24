#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
using namespace std;

/*
Objective : Graph and its understanding
It consist of edges and nodes. It can directed or un-directed.
Can be described in three ways :
1) Adjacency Matrix : Non-zero(its cost) -> edge is present, 0 -> No edge
2) Adjacency list : Each node identified by its index stores the nodes in list/set, which are adjacent to that node.
3) Set representation : one set of all the nodes, and other set containing all the pair-wise nodes which are connected via an edge.

Regular graph : Each node having same degree
Complete graph : Each node is connected to all the other nodes
Cycle graph : Each node is having degree 2 and there's cycle covering all the nodes
Path : Sequences of nodes connected by edges (No repeatation of edge and node)
Cycle : Path starting and ending at the same node
*/

class graph{
    public:

        int nodes;
        //Using adjacency list
        unordered_map<int, vector<int>> adj;

        //direction : 1 -> directed, 0 -> for undirected
        void addEdge(int src, int dest, bool direction){
            adj[src].push_back(dest);
            if(!direction){
                adj[dest].push_back(src);
            }
        }

        void printAllEdges(){
            for(auto node : adj){
                cout<<"Parent : "<<node.first<<" -> ";
                for(int child : node.second){
                    cout<<child<<" ";
                }
                cout<<endl;
            }
        }

        void bfs(int root){
            queue<int> q;
            vector<int> visited(nodes, false);
            vector<int> answer;
            if(root < 0 && root >= nodes){
                cout<<"Source : "<<root<< " not found in the graph"<<endl;
                return ;
            }
            q.push(root);
            while(!q.empty()){
                int n = q.front();
                q.pop();
                if(visited[n]){
                    //Already visited
                    continue;
                }
                answer.push_back(n);
                visited[n] = true;
                for(auto next : adj[n]) if(visited[next]==false){
                    q.push(next);
                }
            }
            cout<<"BFS from source : "<<root<<" is -> ";
            for(int item : answer){
                cout<<item<<" ";
            }
            cout<<endl;
        }

        void dfs(int root){
            stack<int> s;
            vector<int> visited(nodes, false);
            vector<int> answer;
            if(root < 0 && root >= nodes){
                cout<<"Source : "<<root<< " not found in the graph"<<endl;
                return ;
            }
            s.push(root);
            while(!s.empty()){
                int n = s.top();
                
                if(!visited[n]){
                    answer.push_back(n);
                    visited[n] = true;
                }
                bool allVisited = true;
                for(auto next : adj[n]) if(visited[next]==false){
                    s.push(next);
                    allVisited = false;
                    break;
                }
                if(allVisited){
                    s.pop();
                }
            }
            cout<<"DFS from source : "<<root<<" is -> ";
            for(int item : answer){
                cout<<item<<" ";
            }
            cout<<endl;
        }

        // Detecting cycle with BFS approach (for undirected graph ONLY)
        bool checkCycleWithBFSUndirected(int root, unordered_map<int, bool> &visited){
            if(root < 0 || root >= nodes){
                cout<<"Source : "<<root<< " not found in the graph"<<endl;
                return false;
            }
            unordered_map<int, int> parent;
            queue<int> q;
            
            q.push(root);
            parent[root] = -1;
            visited[root] = true;
            while(!q.empty()){
                int n = q.front();
                q.pop();
                
                for(auto next : adj[n]){
                    if(visited[next] == true && next != parent[n]){
                        cout<<"cycle got detected, Parent and child are : "<<n<<" and "<<next<<endl;
                        return true;
                    }
                    else if(visited[next]==false){
                        q.push(next);
                        parent[next] = n;
                        visited[next] = true;
                    }
                }
            }
            return false;
        }

        // Detecting cycle with DFS approach (for undirected graph ONLY)
        bool checkCycleWithDFSUndirected(int root, unordered_map<int, bool> &visited){
            if(root < 0 || root >= nodes){
                cout<<"Source : "<<root<< " not found in the graph"<<endl;
                return false;
            }
            stack<int> s;
            s.push(root);
            unordered_map<int, int> parent;
            parent[root] = -1;
            
            while(!s.empty()){
                int n = s.top(); s.pop();
                if(visited[n]){
                    cout<<"Cycle got detected at: "<<n<<endl;
                    return true;
                }
                visited[n] = true;
                for(auto next : adj[n]) {
                    if(visited[next]==false){
                        s.push(next);
                        parent[next] = n;
                    }else if(next != parent[n]){
                        cout << "Cycle detected at nodes: " << n << " and " << next << endl;
                        return true;
                    }
                    
                }
            }
            return false;
        }

        //Using DFS
        bool checkCycleForDirected(int root, unordered_map<int, bool> &visited, vector<bool> &callMade){
            
            callMade[root] = true;
            visited[root] = true;
            for(int& next : adj[root]){
                if(visited[next] == false){
                    if(checkCycleForDirected(next, visited, callMade)){
                        return true;
                    }
                }
                if(callMade[next]){
                    return true;
                }
            }
            callMade[root] = false;
            return false;
        }

        // Using BFS
        bool checkCycleForDirectedUsingBFS(){
            int count = 0, node;
            vector<int> inDegree(nodes, 0);
            for(int i=0; i<nodes; i++){
                for(auto& next : adj[i]){
                    inDegree[next]++;
                }
            }
            queue<int> q;
            for(int i=0; i<nodes; i++){
                if(inDegree[i] == 0){
                    q.push(i);
                }
            }
            while(!q.empty()){
                node = q.front();
                q.pop();
                count++;
                for(auto& next : adj[node]){
                    inDegree[next]--;
                    if(inDegree[next] == 0){
                        q.push(next);
                    }
                }
            }
            //Conclusion : in case of cycle in directed graph, topological order will be wrong or incomplete
            return count!=nodes;
        }

        //Only for DAG
        void topologicalSort(){

            //(1)Below is recursive DFS approach
            /*stack<int> st;
            unordered_map<int, bool> visited;
            for(int i=0; i<nodes; i++){
                if(!visited[i]){
                    topologicalUtil(i, st, visited);
                }
            }
            while(!st.empty()){
                cout<<st.top()<<" ";
                st.pop();
            }
            cout<<endl;
            */

           //(2) Kahn's algorithm with BFS
            vector<int> inDegree(nodes, 0);
            vector<int> ans;
            for(int i=0; i<nodes; i++){
                for(int& next : adj[i]){
                    inDegree[next]++;
                }
            }
            queue<int> q;
            for(int i=0; i<nodes; i++){
                if(inDegree[i]==0){
                    q.push(i);
                }
            }
            int node;
            while(!q.empty()){
                node = q.front();
                q.pop();
                ans.push_back(node);
                for(int& next : adj[node]){
                    //Removing the edges at a time of node having 0 inDegree
                    if(--inDegree[next]==0){
                        q.push(next);
                    }
                }
            }
            cout<<"Your topological sort is: ";
            for(int& ele : ans){
                cout<<ele<<" ";
            }
            cout<<endl;
        }

        void topologicalUtil(int i, stack<int>& st, unordered_map<int, bool>& visited){
            visited[i] = true;
            for(int& next : adj[i]){
                if(!visited[next]){
                    topologicalUtil(next, st, visited);
                }
            }
            st.push(i);
        }
};

int main(){
    //Instance for directed graph
    graph g;
    int nodes = 8;
    g.nodes = nodes;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(3, 4, 1);
    //g.addEdge(4, 5, 1);
    g.addEdge(5, 3, 1);
    g.addEdge(2, 6, 1);
    g.addEdge(2, 7, 1);
    g.addEdge(7, 6, 1);

    g.printAllEdges();
    /*
    bool cyclePresent = false;
    unordered_map<int, bool> visited;
    vector<bool> callMade(nodes, false);
    for(int i=0; i<nodes; i++){
        if(!visited[i]){
            cyclePresent = g.checkCycleForDirected(i, visited, callMade);
        }
        if(cyclePresent){
            break;
        }
    }
    cout<<"Cycle present with DFS(1 - present / 0 - absent): "<<cyclePresent<<endl;
    */
    //Print the graph's topological sorted order
    g.topologicalSort();
    cout<<"Cycle present with BFS for directed: "<<g.checkCycleForDirectedUsingBFS()<<endl;
    
    return 0;
}

//Use below for trying by own
int main1(){

    graph g;
    /*int n,m;
    cout<<"Enter number of nodes: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>m;
    g.nodes = n;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u, v, 0);
    }*/

    int n = 8;
    g.nodes = n;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(4, 5, 0);
    g.addEdge(5, 3, 0);
    g.addEdge(2, 6, 0);
    g.addEdge(2, 7, 0);
    g.addEdge(7, 6, 0);

    g.printAllEdges();

    g.bfs(0);
    g.dfs(0);

    unordered_map<int, bool> visited;
    bool cyclePresent = false;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            cyclePresent = g.checkCycleWithBFSUndirected(i, visited);
        }
        if(cyclePresent){
            break;
        }
    }
    cout<<"Cycle present with BFS: "<<cyclePresent<<endl;
    
    //To check the cycle
    cyclePresent = false;
    for(auto i = visited.begin(); i != visited.end(); i++){
        i->second = false;
    }
    for(int i=0; i<n; i++){
        if(!visited[i]){
            cyclePresent = g.checkCycleWithDFSUndirected(i, visited);
        }
        if(cyclePresent){
            break;
        }
    }
    cout<<"Cycle present with DFS: "<<cyclePresent<<endl;
    return 0;
}