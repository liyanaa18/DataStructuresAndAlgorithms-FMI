#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int partition(vector<int>& array, int left, int right) { 

	int pivot = array[right]; 

	int positonOfPivot = left; 
	while (right > left)
	{
		if (array[left] < pivot) {
			swap(array[positonOfPivot++], array[left]);
		}

		left++;
	}

	swap(array[positonOfPivot], array[right]);
	return positonOfPivot;
}

void quickSort(vector<int>& array, int left, int right) {
	
	if (left >= right) {
		return;
	}

	int pivot = partition(array, left, right);

	quickSort(array, left, pivot - 1);

	quickSort(array, pivot + 1, right);

}


int main() {

	vector<int> v = { 5, -1, 2, 4, 1, 0 };

	quickSort(v, 0, v.size() - 1);

	for (int i = 0;i < v.size();i++) {
		cout << v[i] << " ";
	}

	return 0;
}