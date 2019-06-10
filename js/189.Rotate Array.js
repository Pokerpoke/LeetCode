/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function (nums, k) {
    k = k % nums.length;
    swap(nums, 0, nums.length - 1);
    swap(nums, 0, k - 1);
    swap(nums, k, nums.length - 1);
};

var swap = function (nums, start, end) {
    while (start < end) {
        let temp = nums[end];
        nums[end] = nums[start];
        nums[start] = temp;
        start++;
        end--;
    }
}

let nums = [1, 2, 3, 4, 5, 6, 7];
let k = 3;
rotate(nums, k);
console.log(nums);
// console.log(rotate(nums, k));

nums = [1, 2, 3, 4, 5, 6];
k = 2;
rotate(nums, k);
console.log(nums);

nums = [-1];
k = 2;
rotate(nums, k);
console.log(nums);