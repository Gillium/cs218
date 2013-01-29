/*
MergeSort(values, first, last)
base case:
if fewer than two items in values[first]..values[last], do nothing
general case:
Cut the array in half
MergeSort the left half
MergeSort the right half
Merge the two sorted halves into one sorted array





Merge(ItemType values[], int leftFirst, int leftLast, int rightFirst, int rightLast)
Set saveFirst to leftFirst		//To know where to copy back
Set index to leftFirst
while more items in left half AND more items in right half
	if values[leftFirst] < values[rightFirst]
		Set tempArray[index] to values[leftFirst]
		increment leftFirst
	else
		Set tempArray[index] to values[rightFirst]
		Increment rightFirst
	Increment index
Copy any remaining items from left half to tempArray
Copy any remaining items from right half to tempArray
Copy the sorted elements from tempArray back into values
*/
