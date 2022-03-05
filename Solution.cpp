
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    
public:

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        const size_t size = nums.size();
        vector<vector<int>> pair_originalToMapped {size, vector<int>(2, 0)};
        for (int i = 0; i < size; i++) {
            pair_originalToMapped[i] = {nums[i], mapInteger(mapping, nums[i])};
        }

        auto sortByMappedValueIncreasingOrder = [](const auto& originalValue_x, const auto& originalValue_y) {
            return (originalValue_x[1] - originalValue_y[1]) < 0;
        };
        
        sort(pair_originalToMapped.begin(), pair_originalToMapped.end(), sortByMappedValueIncreasingOrder);        
        for (int i = 0; i < size; i++) {
            nums[i] = pair_originalToMapped[i][0];
        }
        return nums;
    }

    int mapInteger(const vector<int>& mapping, int originalValue) {
        if (originalValue < 10) {
            return mapping[originalValue];
        }

        int mappedValue = 0;
        int factorDigitPlace = 1;

        while (originalValue != 0) {
            mappedValue += (mapping[originalValue % 10]) * factorDigitPlace;
            factorDigitPlace *= 10;
            originalValue /= 10;
        }
        return mappedValue;
    }
};
