class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int start=0,currTank=0,totalTank=0;
       for(int i=0;i<gas.size();i++){
            int diff = gas[i]-cost[i];
            totalTank+=diff;
            currTank+=diff;
            if(currTank<0){
                start=i+1;
                currTank=0;
            }
       } 
       return totalTank>=0?start:-1;
    }
};
