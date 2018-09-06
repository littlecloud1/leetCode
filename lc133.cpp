//leetcode:133. Clone Graph
//dfs O(n+m)
//make a copy for every node
//use map to prevent duplicate

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        
        //create node
        if (mp.find(node) == mp.end()){ 
            mp[node] = new UndirectedGraphNode(node->label);
            //check neighbour, use dfs
            for(auto n:node->neighbors){
                mp[node]->neighbors.push_back(cloneGraph(n));
            }
        }
        return mp[node];
    }
};
