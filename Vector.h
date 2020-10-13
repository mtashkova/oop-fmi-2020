#pragma once
#include <stdexcept>
#include <iostream>

template<class T>
class Vector
{
	T* arr = nullptr;
	int size;
	int capacity;
	void expand(int cap);
public:
	Vector();
	Vector(const Vector& cpy);
	Vector<T>& operator=(const Vector& cpy);
	void insert(const T& el);
	void erase(int ind);
	void clear();
	void removeByObject(const T& el);
	const T& operator[](unsigned int n) const;
	T& operator[](unsigned int n);
	void resize(size_t n);
	int Size() const;
	int Capacity() const;
	~Vector();
	void print() const;
};

template<class T>
inline void Vector<T>::expand(int cap)
{
	if (capacity >= cap) return;
	capacity = cap;
	T* temp = new T[cap];
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
}
template<class T>
inline Vector<T>::Vector()
{
	 arr = new T[8];
	 size = 0;
	 capacity = 8;
}

template<class T>
inline Vector<T>::Vector(const Vector & cpy)
{
	size = cpy.size;
	capacity = cpy.capacity;
	arr = new T[cpy.capacity];
	for (int i = 0; i < size; i++)
	{
		arr[i] = cpy.arr[i];
	}
}

template<class T>
inline Vector<T> & Vector<T>::operator=(const Vector & cpy)
{
	if (this != &cpy)
	{
		size = cpy.size;
		capacity = cpy.capacity;
		delete[] arr;
		arr = new T[cpy.capacity];
		for (int i = 0; i < size; i++)
		{
			arr[i] = cpy.arr[i];
		}
	}
	return *this;
}
template<class T>
inline void Vector<T>::insert(const T & el)
{
	if (size >= capacity) expand(2 * capacity);
	arr[size] = el;
	size++;


}


template<class T>
inline void Vector<T>::erase(int ind)
{
	if (ind >= size || ind<0) throw std::runtime_error("The index is out of range");
	for (int i = ind; i < size - 1;i++)
	{
		arr[i] = arr[i + 1];
	}
	size--;
}

template<class T>
inline void Vector<T>::clear()
{
	size = 0;
}

template<class T>
inline void Vector<T>::removeByObject(const T& el)
{
	for (int i = 0; i < size;i++)
	{
		if (arr[i] == el)
		{
			erase(i);
		}
	}

}
template<class T>
inline const T & Vector<T>::operator[](unsigned int n) const
{
	return arr[n];
}

template<class T>
inline T & Vector<T>::operator[](unsigned int n)
{
	return arr[n];
}

template<class T>
inline void Vector<T>::resize(size_t n)
{
	if (size > n)
	{
		size = n;
		return;
	}
	T* temp = new T[n];
	for (size_t i = 0; i < size; i++)
		temp[i] = arr[i];
	for (size_t i = size; i < n; i++)
		temp[i] = T();
	delete[] arr;
	arr = temp;
	size = n;


}

template<class T>
inline int Vector<T>::Size() const
{
	return size;
}


template<class T>
inline int Vector<T>::Capacity() const
{
	return capacity;
}
template<class T>
inline Vector<T>::~Vector()
{
	delete[] arr;
}

template<class T>
inline void Vector<T>::print() const
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << std::endl;
	}

}
