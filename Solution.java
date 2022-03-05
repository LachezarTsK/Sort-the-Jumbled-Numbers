
import java.util.Arrays;

public class Solution {

    public int[] sortJumbled(int[] mapping, int[] nums) {

        final int size = nums.length;
        int[][] pair_originalToMapped = new int[size][2];
        for (int i = 0; i < size; i++) {
            pair_originalToMapped[i] = new int[]{nums[i], mapInteger(mapping, nums[i])};
        }

        Arrays.sort(pair_originalToMapped, (originalValue_x, originalValue_y) -> originalValue_x[1] - originalValue_y[1]);
        for (int i = 0; i < size; i++) {
            nums[i] = pair_originalToMapped[i][0];
        }
        return nums;
    }

    public int mapInteger(int[] mapping, int originalValue) {
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
}
