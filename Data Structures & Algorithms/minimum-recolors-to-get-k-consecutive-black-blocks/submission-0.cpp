class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int countW=0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W') countW++;
        }
        int mini = countW;
        for(int i=k;i<n;i++){
            if(blocks[i]=='W') countW++;
            if(blocks[i-k]=='W') countW--;
            mini = min(mini,countW);
        }
        return mini;
    }
};