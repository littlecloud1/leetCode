//leetcode:42. Trapping Rain Water
//see notebook
class Solution {
public:
    int trap(vector<int>& height) {
        int vol = 0;
        if (height.empty())return vol;
        
        
        for (int i =0; i < height.size();i++){
                int j = i+1;
                int block=0,last = 0; // block=block before lower, last= block after lower, include lower
                int lower = j;
                while(j < height.size() && height[j] < height[i]){
                    if(height[j] > height[lower]) {
                        block += last;
                        lower = j;
                        last = height[j];
                    }
                    else last += height[j]; //
                    j++;
                }
                if (height[j] >= height[i] && j < height.size() && (j-i-1)>0 ){
                    vol += height[i] *  (j-i-1); // height*width = volumn of water
                    vol -= (block + last); //also remove any blocked area.
                    i = j-1;
                }
                else if ( lower-i-1  > 0 ){
                    vol += height[lower] *(lower-i-1); //height*width = volumn of water
                    vol -= block; //also remove any blocked area.
                    i = lower-1;
                    
                }
                          
            
        }
        return vol;
        
    }
};
