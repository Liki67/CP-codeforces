class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int i=0,k=0;
        bool flag=true;
        if(intervals[i][0]<newInterval[0]){
            ans.push_back(intervals[i]);i++;
        }
        else{
            ans.push_back(newInterval);
            flag=false;
        }
        
        while(i<intervals.size()) {
            if(flag &&intervals[i][0]>newInterval[0])
            {
                if(ans[k][1]>=newInterval[0]){
                    ans[k][1]=max(ans[k][1],newInterval[1]);
                }
                else{
                    ans.push_back(newInterval);k++;flag=true;
                }
            }else{
                if(ans[k][1]>=intervals[i][0]){
                    ans[k][1]=max(ans[k][1],intervals[i][1]);
                }else{
                    ans.push_back(intervals[i++]);k++;
                }
            }
        }
        return ans;
    }
};