class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count=0;
        sort(people.begin(),people.end());
        int l=0,r=people.size()-1;
        while(l<=r){
            if(people[r]>=limit){
                count++;
                r--;
                continue;
            }
            int sum = people[l]+people[r];
            if(sum<=limit){
                count++;
                l++;
                r--;
                continue;
            }
            else{
                count++;
                r--;
            }
        }
        return count;
    }
};