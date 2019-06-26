#ifndef VECTOR_H
#define VECTOR_H

typedef unsigned int uint;

template <class T>
class Vector
{
	T *data;
	uint count;
public:
	Vector() : data(0), count(0) {  }

	explicit Vector(uint initCount)
	{
		count = initCount;
		data = new T[count];
	}

	Vector(const Vector<T>& v)
	{
		count = v.count;
		data = new T[count];
		for (int i = 0; i < count; i++)
			data[i] = v.data[i];
	}

	Vector(T array[], uint arraySize)
	{
		count = arraySize;
		data = new T[count];
		for (int i = 0; i < count; i++)
			data[i] = array[i];
	}

	~Vector() { Clear(); }

	void Clear()
	{
		count = 0;
		delete[] data;
	}

	Vector<T>& operator=(const Vector<T>& v)
	{
		if (this == &v)
			return *this;
		if (data)
			delete[] data;
		count = v.count;
		data = new T[count];
		for (int i = 0; i < count; i++)
			data[i] = v.data[i];
		return *this;
	}

	uint& GetCount() const { return count; }
	bool IsEmpty() const { return count == 0; }
	bool operator!() const { return IsEmpty(); }

	T& operator[](uint index) { return data[index]; }

	void Add(const T& item)
	{
		count++;
		T *temp = new T[count];
		int i = 0;
		for (; i < count - 1; i++)
			temp[i] = data[i];
		temp[i] = item;
		delete[] data;
		data = temp;
	}

	void Insert(uint index, const int& item)
	{
		count++;
		T * temp = new T[count];
		for (int i = 0; i < count; i++)
		{
			if (i == index)
				temp[i] = item;
			else
			{
				if (i < index)
					temp[i] = data[i];
				else
					temp[i] = data[i - 1];
			}
		}
		delete[] data;
		data = temp;
	}

	void Remove(uint index)
	{
		count--;
		T * temp = new T[count];
		for (int i = 0; i < count; i++)
			temp[i] = (i >= index) ? data[i + 1] : data[i];
		delete[] data;
		data = temp;
	}
};

#endif 