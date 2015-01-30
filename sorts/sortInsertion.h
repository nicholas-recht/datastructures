#ifndef SORTINSERTION_H
#define SORTINSERTION_H

#include <iostream>
template<class T>
void sortInsertion(T data[], int numItems)
{
	for (int wall = 1; wall < numItems; ++wall)
	{
		//binary sort
		int start = 0;
		int end = wall - 1;
		T temp = data[wall];
		data[wall] = data[numItems - 1]; 
		int mid = 0;
		while (start <= end && end >= start)
		{
			mid = (start + end) / 2;
			if (data[mid] < temp)
				start = mid + 1;
			else
				end = mid - 1;
		}
		//If the start is greater than the end than he should go to the next spot over
		if (data[mid] < temp)
			++mid; 
		//otherwise it's already in the right spot
		//Shift everything else
		for (int i = numItems - 1; i >= mid + 1; --i)
			data[i] = data[i - 1]; 

		//copy over the data
		data[mid] = temp;
 
	}
}


#endif