/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
    let slow = 0;
    let i = 0;
    for (; i < nums.length; i++) {
        if (nums[i] != nums[slow]) {
            slow++;
        }
        nums[slow] = nums[i];
    }
    return slow + 1;
};

var in_array = [1, 1, 2];
console.log(removeDuplicates(in_array));
console.log(in_array);

in_array = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4];
console.log(removeDuplicates(in_array));
console.log(in_array);