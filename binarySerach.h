﻿#pragma once
#include <vector>
using namespace std;
//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，
//输出旋转数组的最小元素。例如，数组 [3, 4, 5, 1, 2] 为[1, 2, 3, 4, 5] 的一个旋转，该数组的最小值为1。
class minInRotateArray {
public:
	int minArray(vector<int>& numbers) {
		int n = numbers.size();
		if (n == 0)return 0;
		int l = 0, r = n - 1;
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (numbers[mid] < numbers[r])
				r = mid;
			else if (numbers[mid] > numbers[r])
				l = mid + 1;
			else --r;
		}
		return numbers[l];
	}
};
//一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
class findTwoNumbersAppearOnce {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		int n = 0;
		for (int &i : nums) {
			n ^= i;
		}
		int digE1 = 1;
		while ((digE1&n) == 0) {
			digE1 <<= 1;
		}
		int a = 0, b = 0;
		for (int &i : nums) {
			if (digE1&i)
				a ^= i;
			else
				b ^= i;
		}
		return vector<int>{a, b};
	}
};