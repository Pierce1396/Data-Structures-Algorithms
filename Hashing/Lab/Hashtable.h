#pragma once
#include <iostream>
#include <memory>

using namespace std;

template<class Type>
struct Bucket {
	Type data;
	bool empty = true;
};


template<class Type>
class Hashtable;

template<class Type>
ostream& operator<< (ostream &, Hashtable<Type>&);


template<class Type>
class Hashtable
{
public:
	Hashtable();
	Hashtable(int);
	Hashtable(int, double);
	Hashtable(const Hashtable<Type>& other);
	Hashtable& operator=(const Hashtable<Type>& other);

	int getSize() const;
	int getCapacity() const;
	double getLoadFactorThreshold() const;
	bool empty() const;
	void rehash();
	static bool isPrime(int);
	static int nextPrime(int);
	void insert(const Type);
	void remove(Type);
	bool contains(Type) const;
	int indexOf(Type) const;
	void clear();
	friend ostream& operator<< <>(ostream &, Hashtable<Type>&);

private:
	int hash(int v) const;
	int capacity;
	int size;
	double loadFactor;
	double threshold;
	unique_ptr<Bucket<Type>[]> htable;
};



template<class Type>
Hashtable<Type>::Hashtable()
{
	size = 0;
	capacity = 17;
	loadFactor = size / capacity;
	threshold = .65;
	htable = make_unique<Bucket<Type>[]>(capacity);
}


template<class Type>
Hashtable<Type>::Hashtable(int capacity) : capacity(capacity)
{
	size = 0;
	loadFactor = size / capacity;
	htable = make_unique<Bucket<Type>[]>(capacity);
	threshold = .65;
}

template<class Type>
Hashtable<Type>::Hashtable(int capacity, double threshold) : capacity(capacity)
{
	//Constructs an empty hash table with the given capacity and load factor threshold values
	size = 0;
	loadFactor = size / capacity;
	this->threshold = threshold;
	htable = make_unique<Bucket<Type>[]>(capacity);
}

/*
	Complete the operator= to create a deep copy of the hashtable
*/
template<class Type>
Hashtable<Type>::Hashtable(const Hashtable<Type>& other)
{
	capacity = other.capacity;
	loadFactor = other.loadFactor;
	size = other.size;
	threshold = other.threshold;
	htable = make_unique<Bucket<Type>[]>(capacity);
	for(int i = 0; i < capacity; i++){
		htable[i] = other.htable[i];
	}

}

/*
	Complete the operator= to create a deep copy of the hashtable
*/
template<class Type>
Hashtable<Type>& Hashtable<Type>::operator=(const Hashtable<Type>& other)
{
	if(this == &other){
		return *this;
	}else{
		capacity = other.capacity;
		loadFactor = other.loadFactor;
		size = other.size;
		threshold = other.threshold;
		htable = make_unique<Bucket<Type>[]>(capacity);
		for(int i = 0; i < capacity; i++){
		htable[i] = other.htable[i];
		}
	}
	
}



template<class Type>
int Hashtable<Type>::hash(int v) const 
{

	return v % capacity; 
}

template<class Type>
int Hashtable<Type>::getSize() const
{
	return size;
}

template<class Type>
int Hashtable<Type>::getCapacity() const
{
	return capacity;
}

template<class Type>
double Hashtable<Type>::getLoadFactorThreshold() const
{
	return threshold;
}


template<class Type>
bool Hashtable<Type>::empty() const
{
	if (size == 0) {
		return true;
	}
	return false;
}

template<class Type>
void Hashtable<Type>::rehash()
{
	//Resize the table using the following algorithm....  
	//double the capacity of the list and then finds the next prime number to determine the new size.  
	//Rehash all the items according to the new hash algorithm.  You may need to create a temporary array in order to accomplish this.  
	//Keep in mind with unique pointers, you must use the keyword "move" to transfer ownership of the pointer
	int oldCapacity = capacity;
	capacity = nextPrime(capacity * 2);
	auto arr = make_unique<Bucket<Type>[]>(capacity);
	for (int i = 0; i < oldCapacity; i++)
	{
		if (htable[i].empty == false)
		{
			int hashKey = (int)htable[i].data % capacity;

			if (arr[hashKey].empty == true)
			{
				arr[hashKey].data = htable[i].data;
			}
			else
			{
				int j = 0;
				int hashKey2 = (int)(htable[i].data + (j * j)) % capacity;
				if (arr[hashKey2].empty == true)
				{
					arr[hashKey2].data = htable[i].data;
				}else{
					while (arr[hashKey2].empty == false)
					{
						j++;
						int hashKey2 = (int)(htable[i].data + (j * j)) % capacity;
						if (arr[hashKey2].empty == true)
						{
							arr[hashKey2].data = htable[i].data;
							break;
						}
						
					}
				}
			}
		}
	}
	htable = move(arr);

}

template<class Type>
bool Hashtable<Type>::isPrime(int p)
{
	//Takes an int parameter and returns true if the number is prime.  Used in finding the next prime number.  Note: should be static for testing purposes.  
	//To make it static, put the word static in front of the function definition in the class.  It is not added to the function implementation after the class.

	bool flag = true;
	for(int i = 2; i <= p / 2; i++){
		if(p % i == 0){
			flag = false;
			break;
		}
	}
	return flag;
}

template<class Type>
int Hashtable<Type>::nextPrime(int p)
{
	//Takes an int value and returns the next prime number.  Note: should also be static for testing purposes
	if(p <= 1){
		return 2;
	}
	int prime = p;
	bool found = false;

	while(!found){
		prime++;

		if(isPrime(prime)){
			found = true;
		}
	}
	return prime;
}

template<class Type>
void Hashtable<Type>::insert(Type value)
{

	//Inserts the given value into the hashtable. 
	//When there are collisions, quadratic hashing is used instead of linear.  
	//If the table capacity is higher than the loadFactorThreshold, then rehash the table.

	int i = 0;

		if(((double) (size + 1) / (double) capacity) >= threshold){
		rehash();
	}
	while(!htable[hash(value + (i * i))].empty){
		i++;
	}
	htable[hash(value + (i * i))] = {value, false};
	size++;

	
}

/*
	Complete the remove the value from the hashtable
*/
template<class Type>
void Hashtable<Type>::remove(Type value)
{
	int i = 0;
	while(htable[hash(value + (i * i))].data != value && i < capacity){
		i++;
	}
	if(i == capacity){
		return;
	}
	htable[hash(value + (i * i))] = {0, true};
	size--;	


}

/*
	Complete the contains method to return true of the Hashtable contains the value
*/
template<class Type>
bool Hashtable<Type>::contains(Type value) const {
	int i = 0;
	while(htable[hash(value + (i * i))].data != value && i < capacity){
		i++;
	}
	if(htable[hash(value + (i * i))].data == value){
		return true;
	}	
	
	return false;
}

template<class Type>
int Hashtable<Type>::indexOf(Type i) const
{
	//Returns the index of the given value. If the value is not in the hashtable, returns -1. 
	//This is not a normal method for a hashtable and is here solely to test that your hashtable does quadratic probing.

	 

	if(contains(i) == false){
		return -1;
	}else{
		for(int j = 0; j < capacity; j++){
			if(htable[j].data == i){
			return j;
			}
		}
	}


}

template<class Type>
void Hashtable<Type>::clear()
{
	size = 0;
	htable = make_unique<Bucket<Type>[]>(capacity);
}



template<class Type>
ostream& operator<< (ostream & out, Hashtable<Type>& h) {
	out << "\nCapacity: " << h.capacity << "\n";
	for (int i = 0; i < h.capacity; i++) {

		if (h.htable[i].empty == false) {
			out << i << ": " << h.htable[i].data << endl;
		}

	}
	return out;
}