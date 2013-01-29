/*
RadixSort(values, numValues)
for position going from 1 to 3
	for counter going from 0 to numValues - 1
		Set whichQueue to digit at position "position" of values[counter]
		queues[whichQueue].Enqueue(values[counter])
	Collect queues

Collect Queues
Set index to 0
for counter going from 0 to 9
	while !queues[counter].IsEmpty()
		queues[counter].Dequeue(item)
		Set values[index] to item
		Increment index
*/