class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> indices;
        for(int I=0; I< nums.size(); I++){
            indices[nums[I]] = I;
        }
        for(int I=0; I<nums.size();I++){
            int diff = target - nums[I];
            if(indices.find(diff) != indices.end() && I != indices[diff]){ //exists
                return vector<int>{I,indices[diff]};
            }
        }
        return vector<int>{};
    }
};