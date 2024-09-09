#include <iostream>
using namespace std;
int get_max(int data[], int size)
{
	int max_element = data[0];
	for (int i = 0; i < size; i++)
	{
		if (data[i] > max_element)
		{
			max_element = data[i];
		}
	}
	return max_element;
}
void counting_sort(int data[], int size, int range, int div)
{
	int* output_array = new int[size];
	int* count_array = new int[range];
	for (int i = 0; i < range; i++)
	{
		count_array[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		count_array[(data[i] / div) % 10]++;
	}
	for (int i = 1; i < range; i++)
	{
		count_array[i] = count_array[i] + count_array[i - 1];
	}
	for (int i = 0; i < size; i++)
	{
		output_array[count_array[(data[i] / div) % 10] - 1] = data[i];
	}
	for (int i = 0; i < size; i++)
	{
		data[i] = output_array[i];
	}
}
void radix_sort(int data[], int size, int range)
{
	int max;
	max = get_max(data, size);
	for (int div = 1; max / div > 0; div *= 10)
	{
		counting_sort(data, size, range, div);
	}
}
int main()
{
	int size;
	cout << "Input elements into the array" << endl;
	cin >> size;
	int lower = 0;
	int upper = 0;
	cout << "Input " << size << " elements into the array in the range " << lower << " to " << upper << endl;
	cout << "Input lower limit_";
	cin >> lower;
	cout << "Input upper limit_";
	cin >> upper;
	int range = (upper - lower) + 1;
	int* data = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> data[i];
	}
	cout << "Array elements before sorting" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << data[i]<<" ";
	}
	cout << endl;
	radix_sort(data, size, range);
	cout << endl;
	cout << "Array elements after sorting" << endl;
	for (int w = 0; w < size; w++)
	{
		cout << data[w] << " ";
	}
	return 0;
}