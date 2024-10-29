#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

//Que : 1, Given graph of weighed edges, each connected nodes, shares the same interest with eachother.
//Return the product of node pair values, having highest number of shared interests. 
//Basically, product of nodes having largest shared edges.
int getMaxCommonInterest(){
    int n = 4;
    int m = 5;
    unordered_map<int, unordered_map<int, vector<int>>> adj;
    vector<int> from = {1,1,2,2,2};
    vector<int> to = {2,2,3,3,4};
    vector<int> weight = {2,3,1,3,4};
    for(int i=0; i<m; i++){
        adj[from[i]][to[i]].push_back(weight[i]);
        adj[to[i]][from[i]].push_back(weight[i]);
    }
    int ans = 0;
    size_t count = 0;
    //Get largest count of common interest
    for(auto& xx : adj){
        for(auto& p : xx.second){
            if(count < p.second.size()){
                count = p.second.size();
                ans = (xx.first)*(p.first);
            }else if(count == p.second.size()){
                ans = max(ans, (xx.first)*(p.first));
            }
        }
    }
    cout<<"maxi: "<<count<<endl;
    cout<<"Ans: "<<ans<<endl;
    return ans;
}

//Que : 2, check from based on given direction and moves, you will end up in loop or not.
int checkLoop(){
    string s = "LGRG";
    int x1 = 0, y1 = 0, index = 0;
    vector<int> x = {0, -1, 0, 1};
    vector<int> y = {1, 0, -1, 0};
    
    for(char& c : s){
        if(c == 'G'){
            x1 += x[index];
            y1 += y[index];
        }else if(c=='R'){
            index = (index+1)%4;
        }else{
            index = (index-1+4)%4;
        }
    }
    if((x1 == 0 && y1 == 0) || index != 0){
        cout<<"Loop \n";
    }else{
        cout<<"No loop\n";
    }
    return 0;
}

int main(){

    getMaxCommonInterest();
    return 0;
}