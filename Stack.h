#include <iostream>
using namespace std;

template<typename type>
class Stack {
	type* data;				// Массив для хранения данных
	int _top;
	int size;// Указатель на вершину стека
public:
	Stack();					// Конструктор по умолчанию
	Stack(int size);			// Конструктор для инициализации размера стека
	Stack(const Stack& st);		// Конструктор копирования
	Stack(Stack&& st);			// Конструктор переноса

	bool empty()const;			// Пустой стек?						
	void push(type& val);		// Добавление элемента в конец стека
	void push(type&& val);		// Перенос элемента в конец стека
	int size()const;			// Количество элементов в стеке
	void pop();					// Удаление последнего элемента в стеке
	const type& top()const;		// Возврат последнего элемента в стеке
	void swap(Stack& val);		// Обмен 2х стеков местами

	~Stack();					// Деструктор
};

template<typename type>
inline Stack<type>::Stack()
{
	this->data = nullptr;
	this->_top = 0;
	this->size = 0;
}

template<typename type>
inline Stack<type>::Stack(int size)
{
	this->data = new type[size];
	this->size = size;
	this->_top = size;
}

template<typename type>
inline Stack<type>::Stack(const Stack& st)
{
	this->data = new type[st.size];
	for (auto i = 0; i < st.size; i++)
	{
		this->data[i] = st.data[i];
	}
	this->size = st.size;
	this->_top = st.size;
}

template<typename type>
inline Stack<type>::Stack(Stack&& st) 
{
	this->data = st.data;
	this->_top = st._top;
	this->size = st.size;
	st.data = nullptr;
}

template<typename type>
inline bool Stack<type>::empty() const
{
	for (auto i = 0; i < this->size; i++)
	{
		if (this->data[i])
		{
			continue;
		}
		else
		{
			return true;
		}
	}
	return false;
}

template<typename type>
inline void Stack<type>::push(type& val)
{
	this->data[this->_top] = val;
	this->size += 1;
	this->_top += 1;
}

template<typename type>
inline void Stack<type>::push(type&& val)
{
	this->data[this->_top] = *val;
	this->size += 1;
	this->_top += 1;
}

template<typename type>
inline int Stack<type>::size() const
{
	return this->size;
}

template<typename type>
inline void Stack<type>::pop()
{
	this->_top = _top - 1;
}

template<typename type>
inline const type& Stack<type>::top() const
{
	return this->data[_top - 1];
}

template<typename type>
inline void Stack<type>::swap(Stack& val)
{
	size_t buf_size1{ this->size };
	size_t buf_top1{ this->_top };
	type* buf_data1 = this->data;

	size_t buf_size2{ val.size };
	size_t buf_top2{ val._top };
	type* buf_data2 = val.data;

	this->data = new type[val.size];
	val.data = new type[this->size]; 

	this->data = buf_data2;
	val.data = buf_data1;

	this->size = buf_size2;
	val.size = buf_size1;

	this->_top = buf_top2;
	val._top = buf_top1;
}

template<typename type>
inline Stack<type>::~Stack()
{
	delete[] * this;
}
