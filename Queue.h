template<typename type>
class Queue {
private:
	type* wait;			//Очередь
	int maxLength{250};		//Максимальный размер очереди
	int length;			//Текущий размер очереди
public:
	Queue();			//Конструктор
	Queue(int m);		//Конструктор с размером очереди
	void add(type c);	//Добавление элемента    
	type extract();		//Извлечение элемента
	void clear();		//Очистка очереди
	bool is_empty();	//Проверка существования элементов в очереди
	bool is_full();		//Проверка на переполнение очереди
	int get_count();	//Количество элементов в очереди
	void show();		//демонстрация очереди
	~Queue();			//Деструктор                       
};

template<typename type>
inline Queue<type>::Queue()
{
	this->wait = nullptr;
	/*this->maxLength = 0;*/
	this->length = 0;
	/*this->R = 0;
	this->L = 0;*/
}

template<typename type>
inline Queue<type>::Queue(int m)
{
	this->wait = new type[m];
	this->lenght = m;
	/*this->R = m;
	this->L = 0;*/
}

template<typename type>
inline void Queue<type>::add(type c)
{
	this->wait[length] = c;
	length++;
}

template<typename type>
inline type Queue<type>::extract()
{
	/*this->L += 1;
	this->length -= 1;
	return wait[L - 1];*/

	Queue buffer = new type[this->size];

}

template<typename type>
inline void Queue<type>::clear()
{
	delete[] * this;
}

template<typename type>
inline bool Queue<type>::is_empty()
{
	for (auto i = 0; i < length; i++)
	{
		if (wait[i])
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}

template<typename type>
inline bool Queue<type>::is_full()
{
	if (length => maxLength)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename type>
inline int Queue<type>::get_count()
{
	return this->length;
}

template<typename type>
inline void Queue<type>::show()
{
	for (auto i = L; i < R; i++)
	{
		std::cout << wait[i] << " ";
	}
}

template<typename type>
inline Queue<type>::~Queue()
{
	delete[] * this;
}
