#pragma once

template <class T>
class Vector {
	T* _data;
	size_t _size;
public:
	Vector(size_t size);

	T& operator[](size_t pos);

	template <class Type> class Iterator;
	typedef Iterator<T> iterator;

	iterator begin() noexcept {
		return iterator(_data);
	}

	iterator end() noexcept {
		return iterator(_data + _size);
	}


	template <class Type> 
	class Iterator {
		Type* p_cur;
	public:
		Iterator(Type* ptr = nullptr){
			p_cur = ptr;
		}
		Iterator(const Iterator& other){
			p_cur = other.p_cur;
		}

		Iterator& operator = (const Iterator & other){
			if (*this != other) {
				p_cur = other.p_cur;
			}
			return *this;
		}

		bool operator!=(const Iterator& other) const {
			return p_cur != other.p_cur;
		}

		Iterator operator++(int) {
			Iterator tmp = *this;
			p_cur++;
			return tmp;
		}

		Type& operator*() const {
			return *p_cur;
		}

	};

};

template <class T>
Vector<T>::Vector(size_t size) {
	_size = size;

	if (size == 0) {
		_data = nullptr;
	}
	else {
		_data = new T[_size];
		for (int i = 0; i < _size; i++) {
			_data[i] = T();
		}
	}
}

template <class T>
T& Vector<T>::operator[]( size_t pos ) {
	return _data[pos];
}