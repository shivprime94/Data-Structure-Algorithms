// CPP program to find the maximum value
// of i*arr[i]
#include <bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int n)
{
	// Sort the array
	sort(arr, arr + n);

	// Finding the sum of arr[i]*i
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += (arr[i] * i);

	return sum;
}

// Driven Program
int main()
{
	int arr[] = { 3, 5, 6, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << maxSum(arr, n) << endl;
	return 0;
}
