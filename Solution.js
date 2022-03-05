
/**
 * @param {number[]} mapping
 * @param {number[]} nums
 * @return {number[]}
 */
var sortJumbled = function (mapping, nums) {

    const size = nums.length;
    const pair_originalToMapped = [];
    for (let i = 0; i < size; i++) {
        pair_originalToMapped[i] = [nums[i], mapInteger(mapping, nums[i])];
    }

    pair_originalToMapped.sort((originalValue_x, originalValue_y) => originalValue_x[1] - originalValue_y[1]);
    for (let i = 0; i < size; i++) {
        nums[i] = pair_originalToMapped[i][0];
    }
    return nums;
};

/**
 * @param {number[]} mapping
 * @param {number} originalValue
 */
function mapInteger(mapping, originalValue) {
    if (originalValue < 10) {
        return mapping[originalValue];
    }

    let mappedValue = 0;
    let factorDigitPlace = 1;

    while (originalValue !== 0) {
        mappedValue += (mapping[originalValue % 10]) * factorDigitPlace;
        factorDigitPlace *= 10;
        originalValue = Math.floor(originalValue / 10);
    }
    return mappedValue;
}
