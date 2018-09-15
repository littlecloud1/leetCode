//Hackerrank: Tree: Huffman Decoding
//use dfs
//find the next branch: s[i] == 0? left: right
//if branch is null, add curr node to res
//else increase i and recursively do next branch.
//for the last node, because pos increase in previous branch
//we have to manually add it into result.
//O(n)


void dfs(node* root, string s, int& pos, vector<char>& res ) {
    if(!root) return;
    if(pos == s.size()) {
        res.push_back(root->data);
        return;
    }
    node* direct = (s[pos] == '0')? root->left:root->right;
    if(!direct) res.push_back(root->data);
    else {
        pos++;
        dfs(direct, s, pos, res);
    }
    return;
}



void decode_huff(node * root, string s) {
    vector<char> res;
    if(s.size() == 0) return ;
    int pos = 0;
    while(pos < s.size() && root){
        dfs(root, s, pos, res);
    }
    for(auto i:res) cout<<i;
}
