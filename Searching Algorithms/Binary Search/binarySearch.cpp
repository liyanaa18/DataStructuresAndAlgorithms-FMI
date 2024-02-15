#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int l, int r, int x)
{
	if (r >= l) {
		int mid = (l+r)/2; 

		if (arr[mid] == x) 
			return mid;

		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		return binarySearch(arr, mid + 1, r, x);
	}

	return -1;
}

int main()
{
	vector<int> arr = { 2, 3, 4, 7, 10, 40, 60 };
	int x = 10;
	int result = binarySearch(arr, 0, arr.size() - 1, x);
	cout << result;

	return 0;
}
