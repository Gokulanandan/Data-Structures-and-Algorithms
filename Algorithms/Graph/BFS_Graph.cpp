#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
#define MAX_NODE 8

void bfs_vector(int k, vector<int> arr[], vector<int> &seen) {
    queue<int> q;
    q.push(k);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(!seen[node]) {
            seen[node] = 1;
            cout<<node<<"->";
            for(int i=0; i< arr[node].size(); i++){
                if(!seen[arr[node][i]])
                    q.push(arr[node][i]);
            }
        }
    }
}

int main(){
    vector<int> node[MAX_NODE];
    vector<int> seen(MAX_NODE, 0);

    cout<<"Enter the Graph Details below " <<endl;
    cout<<"Enter Two Node details with a Space in between \
            eg., 1 2 , where 1 is connected to 2.         \
            This is a Directed Graph" << endl;
    int n = MAX_NODE;
    while(n) {
        int p, q;
        cin >>p>>q;
        node[p].push_back(q);
        n--;
    }

    bfs_vector(0, node, seen);
    cout << "null" << endl;

    for(int i=0; i<=7;i++){
        cout << "["<<i<< "] : " << seen[i]<<endl;
    }
    return 0;
}