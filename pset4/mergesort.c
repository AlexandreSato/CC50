/* C program of my first Merge Sort with recursion | time: (O)nlog2n
 * by Alexandre Nobuharu Sato in 2020/12/22 */
#include <stdio.h>
#include <cc50.h>


/*
 *Prototypes
 */
//l is for left and r is right index of the sub-array of arr to be sorted
void
mergeSort(int arr[], int l, int r);

//Merges two subarrays of arr[], first is arr[l...m], second is arr[m+1...r]
void
merge(int arr[], int l, int m, int r);


//Utility function to print an array
void
printArray(int arr[], int size);



/*
 *Driver
 */
int
main(void)
{
	//fill array
	int arr[65536], size;
	for (size = 0; size < 65536; size++)
	{
		int arrRaw = GetInt();
		if (arrRaw == INT_MAX)//wait for EOF
			break;
		arr[size] = arrRaw;
	}

	printf("Given array is \n");
	printArray(arr, size);

	mergeSort(arr, 0, size - 1);

	printf ("\nSorted array is \n");
	printArray(arr, size);

	return 0;
}


/*
 *Functions
 */
//Break arr[] in the middle and come back merging in recursion
void
mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{       //Same as (l+r)/2 but avoids overflow
		int m = l + (r - l) / 2;

		//Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void
merge(int arr[], int l, int m, int r)
{
	int i =0, j=0, k=0;//index of first, second and merged subarray
	int n1 = m - l + 1;
	int n2 = r - m;

	//temp arrays
	int L[n1], R[n2];

	//fill temp arrays
	for(i=0; i < n1; i++)
		L[i] = arr[l + i];
	for(j=0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	//Merge the temp arrays back into arr[l ... r]
	i = 0; j = 0; k = l; //Zeroing index of first, second and merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) //Copy the reimaining elements of L[], if there any
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) //Copy the reimaining elementes of R[], if there are any
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void
printArray(int arr[], int size)
{
	for(int i = 0; i <= size -1 ; i++)
		printf("%d  ", arr[i]);
	printf("\n");
}
