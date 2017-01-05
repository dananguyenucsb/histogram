#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <iomanip>
using namespace std;

typedef int* IntArrayPtr;

void fill_array(int array_grades[], int size);
void histogram(int array_grades[], int size);

void fill_array(int array_grades[], int size){
	cout << "Enter grades (each on a new line):" << endl;
	for(int index = 0; index < size; index++){
		cin >> array_grades[index];
	}
}

void histogram(int array_grades[], int size){

	int counts[1000]={0};
	//initializing counts array to 0

	//a[i] is the array that contains the user input numbers
	//counts[] counts the frequncy of each user number input occurs
	for (int i = 0; i < size; i++){
		counts[array_grades[i]]++;
	}
	//if counts[i] isnt empty, we loop through and
	// and cout stars based on the frequency the number occured
	for (int i = 0; i < 1000; ++i) {
		if (counts[i] != 0)
		{
			cout << setw(3) << i << " ";
			for(int j = 0; j < counts[i]; ++j) {
				cout << "*";
			}
			cout << std::endl;
		}
	}
}

int main(){
	//user input number of grades
	int num_of_grades;
	cout << "Enter number of grades:" << endl;
	cin >> num_of_grades;

	//use of dynamic array
	IntArrayPtr array_grades;
	array_grades = new int[num_of_grades];
	//filling the array with the words
	fill_array(array_grades, num_of_grades);
	//printing out the histogram
	cout << "Histogram:" << endl;
	histogram(array_grades,num_of_grades);

	delete [] array_grades;

	return 0;
}