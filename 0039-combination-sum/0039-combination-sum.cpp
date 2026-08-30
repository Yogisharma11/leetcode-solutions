class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& candidates, int target, int start) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target)
                break;

            temp.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0);
        return ans;
    }
};