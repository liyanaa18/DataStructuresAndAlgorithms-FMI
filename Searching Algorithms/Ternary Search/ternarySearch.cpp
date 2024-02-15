#include <iostream>
#include <vector>
using namespace std;

int ternarySearch(vector<int> arr, int l, int r, int key)
{
	if (r >= l) {

		int mid1 = l + (r - l) / 3;
		int mid2 = r - (r - l) / 3;

		if (arr[mid1] == key) 
			return mid1;
		
		if (arr[mid2] == key) 
			return mid2;
		

		if (key < arr[mid1]) 
			return ternarySearch(arr, l, mid1 - 1, key);
		
		else if (key > arr[mid2]) 
			return ternarySearch(arr, mid2 + 1, r, key);
		
		else 
			return ternarySearch(arr, mid1 + 1, mid2 - 1, key);
	}

	return -1;
}

int main()
{

	vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int ans = ternarySearch(arr, 0, arr.size()-1, 6);

	cout << ans << endl;

}


