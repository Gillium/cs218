#include <cstdlib>
#include <ostream>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "queue.h"
#ifndef MYHASH
#define MYHASH

using namespace std;

class HashIsFull
// Exception class used by InsertItem when hash is full
{
};

class HashIsEmpty
// Exception class used by DeleteItem when hash is empty
{
};

class ItemNotFound
// Exception class used by FindItemIndex when item is not found in hash
{
};

enum CollisionTypes {LINEAR, QUADRATIC};

static const int ARRAY_SIZE = 103;

template <class ItemType>
class Hash
// linear probe to handle collisions
{
public:
	Hash(ItemType emptyVal, ItemType deletedVal, CollisionTypes ct);
	// Overloaded constructor
	// Pre:  None
	// Post: data is initialized, length is zero, emptyItem is set to emptyVal,
	//		 deletedItem is set to deletedVal, collisionType set to ct

	~Hash();
	// Deconstructor
	// Pre:  data is initialized
	// Post: data is destroyed

	Hash(const Hash<ItemType>& orginalHash);
	// Copy constructor
	// Pre:  data is initialized, orginalHash is a valid hash with same size as this
	// Post: data contains a copy of the originalHash array, length is set to orginalHash
	//		 length, emptyItem is set to orginalHash.emptyItem, deletedItem is set to
	//		 orginalHash.deletedItem, collisionType is set to orginalHash.collisionType

	void InsertItem(ItemType item);
	// Function: Inserts item in hash using collisionType to handle collisions
	// Pre:		 data is initialized
	// Post:	 data contains item, length is incremented

	bool Search(ItemType item);
	// Function: Searches hash array for item, if found return true otherwise false
	// Pre:		 data is initialized
	// Post:	 function value = (item found)

	void DeleteItem(ItemType item);
	// Function: If item is found in hash array delete item else throw exception
	// Pre:		 data is intialized
	// Post:	 If item is found, data does not contain item and length is decremented,
	//			 otherwise throws ItemNotFound

	ItemType RetrieveItem(ItemType item);
	// Function: Retrieves item from hash
	// Pre:		 data is initialized
	// Post:	 function value = (item) else throws exception when item not found

	QueueType<ItemType> RetrieveAllItems();
	// Function: Retrieves all items from hash
	// Pre:		 data is initialized
	// Post:	 None

	void Display(ostream& outStream);
	// Function: Displays hash table
	// Pre:		 data is intialized
	// Post:	 None

	unsigned int GetLength();
	// Function: Returns length of hash
	// Pre:		 data is intialized
	// Post:	 function value = (length)

	unsigned int getCollisions();
	// Function: Returns collisions
	// Pre:		 hash is initialized
	// Post:	 function value = (collisions)

	void resetCollisions();
	// Function: Resets collisions
	// Pre:		 None
	// Post:	 collisions = 0

	static unsigned int GetASCIIHash(ItemType item);
	// Function: Returns simple ASCII hash of item
	// Pre:		 None
	// Post:	 function value = (sum of ASCII values of individual characters in string
	//			 representation of items)

	static string GetMD5Hash(string message);
	// Function: Returns md5 hash of message (from http://en.wikipedia.org/wiki/MD5)
	// Pre:		 None
	// Post:	 function value = (md5 hash of message string)

private:
	ItemType data[ARRAY_SIZE];
	unsigned int length;
	ItemType deletedItem;
	ItemType emptyItem;
	CollisionTypes collisionType;
	unsigned int collisions;

	bool IsFull();
	// Function: Checks to see if hash array is full
	// Pre:		 data is intialized
	// Post:	 Function value = (length equals ARRAY_SIZE);

	bool IsEmpty();
	// Function: Checks to see if hash array is empty
	// Pre:		 data is intialized
	// Post:	 Function value = (length equals zero);

	unsigned int FindItemIndex(ItemType item);
	// Function: Returns the index of item if found otherwise throw exception
	// Pre:		 data is intialized
	// Post:	 function value = (index of item) if found, otherwise throws ItemNotFound
	//			 exception
};

#include "hash.template"
#endif