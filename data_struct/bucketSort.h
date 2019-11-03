#ifndef _BUCKETSORT_H_
#define _BUCKETSORT_H_

#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include"helpFunction.h"

using namespace std;
void bucketSort(vector<int> &nums) {
	if (nums.size() < 2) {
		return;
	}
	int m_max = INT_MIN;
	int size = nums.size();
	for (int i = 0; i <size; i++) {
		m_max = max(m_max, nums[i]);
	}
	vector<int> bucket(m_max + 1) ;
	for (int i = 0; i < size; i++) {
		bucket[nums[i]]++;
	}
	int i = 0;
	for (int j = 0; j < bucket.size(); j++) {
		while (bucket[j]-- > 0) {
			nums[i++] = j;
		}
	}
}

#endif