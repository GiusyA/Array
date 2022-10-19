#pragma once
#include <initializer_list>
#include <string>

template <typename T>
class Array
{
#pragma region f/p
private:
	size_t count = 0;
	T* tab = nullptr;
#pragma endregion
#pragma region constructor/destructor
public:
	Array() = default;
	Array(const size_t& _count);
	Array(const size_t& _count, const T& _item);
	Array(const std::initializer_list<T>& _tab);
	Array(const Array<T>& _copy);
	~Array();
#pragma endregion
#pragma region methods
public:
	T& At(const size_t& _index);
	T& Front();
	T& Back();
	void Clear(bool _done = false);
	void Resize(const size_t& _count);
	size_t Count() const;
#pragma endregion
#pragma region operator
public:
	T& operator[](const size_t& _index);
	T operator[](const size_t& _index) const;
	bool operator==(const Array<T>& _other);
	bool operator!=(const Array<T>& _other);
#pragma endregion
};

#pragma region constructor/destructor
template<typename T>
Array<T>::Array(const size_t& _count)
{
	count = _count;
	tab = new T[_count];
}
template<typename T>
Array<T>::Array(const size_t& _count, const T& _item)
{
	count = _count;
	tab = new T[_count];
	for (size_t i = 0; i < _count; i++) tab[i] = _item;
}
template<typename T>
Array<T>::Array(const std::initializer_list<T>& _tab)
{
	size_t _index = 0;
	count = _tab.size();
	tab = new T[count];
	for (T _item : _tab)
	{
		tab[_index] = _item;
		_index++;
	}
}
template<typename T>
Array<T>::Array(const Array<T>& _copy)
{
	tab = _copy.tab;
	count = _copy.count;
}
template<typename T>
Array<T>::~Array()
{
	Clear(true);
	count = 0;
}
#pragma endregion

#pragma region methods
template<typename T>
T& Array<T>::At(const size_t& _index)
{
	return tab[_index];
}
template<typename T>
T& Array<T>::Front()
{
	return tab[count - 1];
}
template<typename T>
T& Array<T>::Back()
{
	return tab[0];
}
template<typename T>
inline void Array<T>::Clear(bool _done)
{
	delete[] tab;
	tab = (_done) ? nullptr : new T[count];
}
template<typename T>
void Array<T>::Resize(const size_t& _count)
{
	T* _tmp = tab;
	size_t _oldCount = count;
	count = _count;
	tab = new T[count];
	for (size_t i = 0; i < count && i < _oldCount; i++) tab[i] = _tmp[i];
	for (size_t i = _oldCount; i < count; i++) tab[i] = T();
	delete[] _tmp;
}
template<typename T>
size_t Array<T>::Count() const
{
	return count;
}
#pragma endregion

#pragma region operator
template<typename T>
T& Array<T>::operator[](const size_t& _index)
{
	return tab[_index];
}

template<typename T>
T Array<T>::operator[](const size_t& _index) const
{
	return tab[_index];
}
template<typename T>
bool Array<T>::operator==(const Array<T>& _other)
{
	if (count != _other.count) return false;
	for (size_t i = 0; i < count; i++) if (tab[i] != _other.tab[i]) return false;
	return true;
}
template<typename T>
bool Array<T>::operator!=(const Array<T>& _other)
{
	return !this->operator==(_other);
}
#pragma endregion