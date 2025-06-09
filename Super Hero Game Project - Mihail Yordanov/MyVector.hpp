#pragma once


template <typename T>
class MyVector
{
	T** _data;
	size_t _capacity;
	size_t _size;

	void resize();	
	void moveFrom(MyVector<T>&& other);
	void copyFrom(const MyVector<T>& other);
	void free();
public:

	MyVector();
	MyVector(const MyVector<T>& other);
	MyVector& operator=(const MyVector<T>& other);

	MyVector(MyVector<T>&& other);
	MyVector& operator=(MyVector<T>&& other);

	void add(const T& obj);
	void remove(size_t index);

	const T* operator[](size_t index) const;
	T*& operator[](size_t index);
	size_t lenght() const;

	~MyVector();

};


template <typename T>
void MyVector<T>::remove(size_t index)
{
	if (index >= _size)
		throw std::bad_alloc();
	_data[index] = _data[--_size];
}
template <typename T>
void MyVector<T>::add(const T& obj)
{
	if (_size == _capacity)
		resize();

	_data[_size] = new T(obj);
	_size++;
}
template <typename T>
const T* MyVector<T>::operator[](size_t index) const
{
	if (index >= _size)
		throw std::bad_alloc();
	return _data[index];
}
template <typename T>
T*& MyVector<T>::operator[](size_t index)
{
	if (index >= _size)
		throw std::bad_alloc();
	return _data[index];
}
template <typename T>
size_t MyVector<T>::lenght() const
{
	return _size;
}

template <typename T>
MyVector<T>::MyVector()
{
	_capacity = 4;
	_data = new T * [_capacity];
	for (int i = 0; i < _capacity; i++)
		_data[i] = new T;
	_size = 0;
}
template <typename T>
void MyVector<T>::resize()
{
	T** resizedData = new T * [_capacity *= 2];
	for (int i = 0; i < _size; i++)
		resizedData[i] = _data[i];

	delete[] _data;
	_data = resizedData;
}
template <typename T>
void MyVector<T>::free()
{
	for (int i = 0; i < _size; i++)
		delete _data[i];
	delete[] _data;
}
template <typename T>
void MyVector<T>::copyFrom(const MyVector<T>& other)
{
	_data = new T * [other._capacity];
	_size = other._size;
	_capacity = other._capacity;

	for (int i = 0; i < other._size; i++)
		_data[i] = other._data[i];

}
template <typename T>
void MyVector<T>::moveFrom(MyVector<T>&& other)
{
	_size = other._size;
	_capacity = other._capacity;

	_data = other._data;
	for (int i = 0; i < other._capacity; i++)
		other._data[i] = nullptr;

	other._size = other._capacity = 0;
}
template <typename T>
MyVector<T>::MyVector(const MyVector<T>& other)
{
	copyFrom(other);
}
template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
template <typename T>
MyVector<T>::MyVector(MyVector<T>&& other)
{
	moveFrom(std::move(other));
}
template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector<T>&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}
template <typename T>
MyVector<T>::~MyVector()
{
	free();
}

