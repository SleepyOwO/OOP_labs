#pragma once
//#include <initializer_list>

template <typename type>
struct Elem {
	type value;
	Elem* next;
	Elem* prev;
};

template <typename type>
class List {
	private:
		Elem<type>* start;
		Elem<type>* end;
		int count1;
		int count2;
		bool is_copy;
	public:
		List() : start{ NULL }, end{ NULL }, count1{ 0 }, count2{ 0 }, is_copy{} {};
		~List();
		List(const List&);
		void push(type, int);
		type pop(int);
		bool empty(int);
		bool full(int);
		void print(int);
		List<type>& operator = (const List&);
		bool operator != (const List&);
		friend std::ostream& operator<< (std::ostream& out, List& li) {
			Elem<type>* tmp{nullptr};
			if (li.count1)
				tmp = li.start;
			else {
				tmp = li.end;
				for (int i{}; i < li.count2; i++)
					tmp = tmp->prev;
			}
			std::cout << "Список: ";
			for (int i{}; i < li.count1 + li.count2; i++) {
				out << tmp->value << " ";
				tmp = tmp->next;
			}
			out << '\n';
			return out;
		}

};

template <typename type>
List<type>::~List() {
	Elem<type>* p, * tmp = start;
	for (int i{}; i < count1 + count2; i++) {
		p = tmp;
		tmp = tmp->next;
		delete p;
	}
	start = nullptr;
	end = nullptr;
	count1 = 0;
	count2 = 0;
}

template <typename type>
List<type>::List(const List& copy) {
	start = nullptr, end = nullptr;
	count1 = 0, count2 = 0;
	is_copy = true;
	Elem<type>* tmp;
	if (copy.count1) {
		tmp = copy.start;
		for (int i{}; i < copy.count1 - 1; i++) {
			tmp = tmp->next;
		}
		for (int i{}; i < copy.count1; i++) {
			push(tmp->value, 1);
			tmp = tmp->prev;
		}
		tmp = copy.end;
		for (int i{}; i < copy.count2 - 1; i++) {
			tmp = tmp->prev;
		}
		for (int i{}; i < copy.count2; i++) {
			push(tmp->value, 2);
			tmp = tmp->next;
		}
		std::cout << "Список скопирован\n";
	}
	else if (copy.count2){
		tmp = copy.end;
		for (int i{}; i < copy.count2 - 1; i++)
			tmp = tmp->prev;
		while (tmp) {
			push(tmp->value, 2);
			tmp = tmp->next;
		}
		std::cout << "Список скопирован\n";
	}
	else
		std::cout << "Нечего копировать\n";
}

template <typename type>
void List<type>::push(type value, int number) {
	Elem<type>* tmp{ new Elem<type>{value, NULL, NULL} };
	switch (number) {
	case 1:
		if (!count1 && !count2) {
			end = new Elem<type>;
			start = tmp;
			tmp->next = end;
			end->prev = tmp;
		}
		else if (!count1 && count2) {
			start = tmp;
			Elem<type>* cur = end;
			for (int i{}; i < count2 - 1; i++) {
				cur = cur->prev;
			}
			start->next = cur;
			cur->prev = start;
		}
		else if (count1 && !count2) {
			Elem<type>* cur = start;
			start = tmp;
			start->next = cur;
			cur->prev = start;
			Elem<type>* stack1_end = start;
			for (int i{}; i < count1 - 1; i++) {
				stack1_end = stack1_end->next;
			}
			end->prev = stack1_end;
		}
		else {
			Elem<type>* cur = start;
			start = tmp;
			start->next = cur;
			cur->prev = start;
		}
		count1++;
		return;
	case 2:
		if (!count1 && !count2) {
			start = new Elem<type>;
			end = tmp;
			tmp->prev = start;
			start->next = tmp;
		}
		else if (count1 && !count2) {
			end = tmp;
			Elem<type>* cur = start;
			for (int i{}; i < count1 - 1; i++) {
				cur = cur->next;
			}
			end->prev = cur;
			cur->next = end;
		}
		else if (!count1 && count2) {
			Elem<type>* cur = end;
			end = tmp;
			end->prev = cur;
			cur->next = end;
			Elem<type>* stack2_end = end;
			for (int i{}; i < count2; i++) {
				stack2_end = stack2_end->prev;
			}
			start->next = stack2_end;
		}
		else {
			Elem<type>* cur = end;
			end = tmp;
			end->prev = cur;
			cur->next = end;
		}
		count2++;
		return;
	default:
		std::cout << "Некорректное значение!\n";
		break;
	}
}

template <typename type>
type List<type>::pop(int number) {
	switch (number) {
	case 1:
		if (!count1) {
			throw "Empty stack";
			break;
		}
		else if (count1) {
			--count1;
			Elem<type>* keep = start->next;
			if (start->next)
				keep->prev = nullptr;
			int value = start->value;
			delete	start;
			if (count1)
				start = keep;
			else
				start = nullptr;
			std::cout << "Значение " << value << " выбрано из стека 1\n";
			return value;
		}
	case 2:
		if (!count2) {
			throw "Empty stack";
			break;
		}
		else {
			--count2;
			Elem<type>* keep = end->prev;
			if (end->prev)
				keep->next = nullptr;
			type value = end->value;
			delete	end;
			if (count2)
				end = keep;
			else
				end = nullptr;
			std::cout << "Значение " << value << " выбрано из стека 2\n";
			return value;
		}
	default:
		std::cout << "Некорректное значение!\n";
		break;
	}
}

template <typename type>
bool List<type>::empty(int number) {
	switch (number) {
	case 1:
		if (!count1)
			return 1;
		else
			return 0;
	case 2:
		if (!count2)
			return 1;
		else
			return 0;
	default:
		std::cout << "Некорректное значение!\n";
		break;
	}
}

template <typename type>
bool List<type>::full(int number) {
	switch (number) {
	case 1:
		if (count1)
			return 1;
		else
			return 0;
	case 2:
		if (count2)
			return 1;
		else
			return 0;
	default:
		std::cout << "Некорректное значение!\n";
		break;
	}
}

template <typename type>
void List<type>::print(int number) {
	Elem<type>* cur1 = start;
	Elem<type>* cur2 = end;
	switch (number) {
	case 1:
		if (count1) {
			std::cout << "Стек 1: ";
			for (int i{}; i < count1; i++) {
				std::cout << cur1->value << ' ';
				cur1 = cur1->next;
			}
			std::cout << '\n';
			break;
		}
		else {
			std::cout << "Стек 1: пуст\n";
			break;
		}
	case 2:
		if (count2) {
			std::cout << "Стек 2: ";
			for (int i{}; i < count2; i++) {
				std::cout << cur2->value << ' ';
				cur2 = cur2->prev;
			}
			std::cout << '\n';
			break;
		}
		else {
			std::cout << "Стек 2: пуст\n";
			break;
		}
	default:
		std::cout << "Некорректное значение!\n";
		break;
	}
}

template <typename type>
List<type>& List<type>::operator = (const List& li) {
	if (this != &li) {
		Elem<type>* p, * tmp = start;
		for (int i{}; i < count1 + count2; i++) {
			p = tmp;
			tmp = tmp->next;
			delete p;
		}
		start = nullptr;
		if (li.count1) {
			tmp = li.start;
			for (int i{}; i < li.count1 - 1; i++) {
				tmp = tmp->next;
			}
			for (int i{}; i < li.count1; i++) {
				push(tmp->value, 1);
				tmp = tmp->prev;
			}
			tmp = li.end;
			for (int i{}; i < li.count2 - 1; i++) {
				tmp = tmp->prev;
			}
			for (int i{}; i < li.count2; i++) {
				push(tmp->value, 2);
				tmp = tmp->next;
			}
		}
		else if (li.count2) {
			tmp = li.end;
			for (int i{}; i < li.count2 - 1; i++)
				tmp = tmp->prev;
			while (tmp) {
				push(tmp->value, 2);
				tmp = tmp->next;
			}
		}
		else {
			std::cout << "Список пуст\n";
		}
	}
	return *this;
}


template <typename type>
bool List<type>::operator!=(const List& l2) {
	return (this->count2 != l2.count1);
}