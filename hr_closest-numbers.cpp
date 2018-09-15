//Hackerrank: closest-numbers
//sort it
//go through the list and check the distance
//record the smallest distance into hash
//return hash[smallest]
// Complete the closestNumbers function below.
vector<int> closestNumbers(vector<int> arr) {
    if (arr.empty())return arr;
    
    unordered_map<int, vector<int>> hash;
    int smallest = INT_MAX;
        
    sort(arr.begin(),arr.end());
    for(int i = 1; i < arr.size(); i++){
        int dist = arr[i] - arr[i-1];
        smallest = min(dist,smallest);
        hash[dist].push_back(arr[i-1]);
        hash[dist].push_back(arr[i]);
    }
    return hash[smallest];
}