#include <iostream>
#include "Double_stack_list.h"

//List::~List() {
//	Elem* p, *tmp = start;
//	for (int i{}; i < count1 + count2; i++) {
//		p = tmp;
//		tmp = tmp->next;
//		delete p;
//	}
//	start = nullptr;
//	end = nullptr;
//	count1 = 0;
//	count2 = 0;
//}
//
//List::List(const List& copy) {
//	start = nullptr, end = nullptr;
//	count1 = 0, count2 = 0;
//	is_copy = true;
//	Elem* tmp;
//	if (copy.count1) {
//		tmp = copy.start;
//		for (int i{}; i < copy.count1 - 1; i++) {
//			tmp = tmp->next;
//		}
//		for (int i{}; i < copy.count1; i++) {
//			push(tmp->value, 1);
//			tmp = tmp->prev;
//		}
//		tmp = copy.end;
//		for (int i{}; i < copy.count2 - 1; i++) {
//			tmp = tmp->prev;
//		}
//		for (int i{}; i < copy.count2; i++) {
//			push(tmp->value, 2);
//			tmp = tmp->next;
//		}
//		std::cout << "Список скопирован\n";
//	}
//	else if (copy.count2){
//		tmp = copy.end;
//		for (int i{}; i < copy.count2 - 1; i++)
//			tmp = tmp->prev;
//		while (tmp) {
//			push(tmp->value, 2);
//			tmp = tmp->next;
//		}
//		std::cout << "Список скопирован\n";
//	}
//	else
//		std::cout << "Нечего копировать\n";
//}
//
//void List::push(int value, int number) {
//	Elem* tmp{ new Elem{value, NULL, NULL} };
//	switch (number)	{
//	case 1:
//		if (!count1 && !count2) {
//			end = new Elem; 
//			start = tmp;
//			tmp->next = end;
//			end->prev = tmp;
//		}
//		else if (!count1 && count2) {
//			start = tmp;
//			Elem* cur = end;
//			for (int i{}; i < count2-1; i++) {
//				cur = cur->prev;
//			}
//			start->next = cur;
//			cur->prev = start;
//		}
//		else if (count1 && !count2){
//			Elem* cur = start;
//			start = tmp;
//			start->next = cur;
//			cur->prev = start;
//			Elem* stack1_end = start;
//			for (int i{}; i < count1-1; i++) {
//				stack1_end = stack1_end->next;
//			}
//			end->prev = stack1_end;
//		}
//		else {
//			Elem* cur = start;
//			start = tmp;
//			start->next = cur;
//			cur->prev = start;
//		}
//		count1++;
//		return;
//	case 2:
//		if (!count1 && !count2) {
//			start = new Elem;
//			end = tmp;
//			tmp->prev = start;
//			start->next = tmp;
//		}
//		else if (count1 && !count2) {
//			end = tmp;
//			Elem* cur = start;
//			for (int i{}; i < count1-1; i++) {
//				cur = cur->next;
//			}
//			end->prev = cur;
//			cur->next = end;
//		}
//		else if (!count1 && count2) {
//			Elem* cur = end;
//			end = tmp;
//			end->prev = cur;
//			cur->next = end;
//			Elem* stack2_end = end;
//			for (int i{}; i < count2; i++) {
//				stack2_end = stack2_end->prev;
//			}
//			start->next = stack2_end;
//		}
//		else {
//			Elem* cur = end;
//			end = tmp;
//			end->prev = cur;
//			cur->next = end;
//		}
//		count2++;
//		return;
//	default:
//		std::cout << "Некорректное значение!\n";
//		break;
//	}
//}
//
//int List::pop( int number){
//	switch (number) {
//	case 1:
//		if (!count1) {
//			throw "Empty stack";
//			break;
//		}
//		else if (count1) {
//			--count1;
//			Elem* keep = start->next;
//			if (start->next) 
//				keep->prev = nullptr;
//			int value = start->value;
//			delete	start;
//			if (count1) 
//				start = keep;
//			else
//				start = nullptr;
//			std::cout << "Значение " << value << " выбрано из стека 1\n";
//			return value;
//		}
//	case 2:
//		if (!count2) {
//			throw "Empty stack";
//			break;
//		}
//		else{
//			--count2;
//			Elem* keep = end->prev; 
//			if (end->prev)
//				keep->next = nullptr;
//			int value = end->value;
//			delete	end;
//			if (count2)
//				end = keep;
//			else
//				end = nullptr;
//			std::cout << "Значение " << value << " выбрано из стека 2\n";
//			return value;
//		}
//	default:
//		std::cout << "Некорректное значение!\n";
//		break;
//	}
//}
//
//bool List::empty(int number) {
//	switch (number) {
//	case 1:
//		if (!count1)
//			return 1;
//		else
//			return 0;
//	case 2:
//		if (!count2)
//			return 1;
//		else
//			return 0;
//	default:
//		std::cout << "Некорректное значение!\n";
//		break;
//	}
//}
//
//bool List::full(int number) {
//	switch (number) {
//	case 1:
//		if (count1)
//			return 1;
//		else
//			return 0;
//	case 2:
//		if (count2)
//			return 1;
//		else
//			return 0;
//	default:
//		std::cout << "Некорректное значение!\n";
//		break;
//	}
//}
//
//void List::print(int number) {
//	Elem* cur1 = start;
//	Elem* cur2 = end;
//	switch (number) {
//	case 1:
//		if (count1) {
//			std::cout << "Стек 1: ";
//			for (int i{}; i < count1; i++) {
//				std::cout << cur1->value << ' ';
//				cur1 = cur1->next;
//			}
//			std::cout << '\n';
//			break;
//		}
//		else {
//			std::cout << "Стек 1: пуст\n";
//			break;
//		}
//	case 2:
//		if (count2) {
//			std::cout << "Стек 2: ";
//			for (int i{}; i < count2; i++) {
//				std::cout << cur2->value << ' ';
//				cur2 = cur2->prev;
//			}
//			std::cout << '\n';
//			break;
//		}
//		else {
//			std::cout << "Стек 2: пуст\n";
//			break;
//		}
//	default:
//		std::cout << "Некорректное значение!\n";
//		break;
//	}
//}
//
//List& List::operator = (const List& li) {
//	if (this != &li) {
//		Elem* p, * tmp = start;
//		for (int i{}; i < count1 + count2; i++) {
//			p = tmp;
//			tmp = tmp->next;
//			delete p;
//		}
//		start = nullptr;
//		if (li.count1) {
//			tmp = li.start;
//			for (int i{}; i < li.count1 - 1; i++) {
//				tmp = tmp->next;
//			}
//			for (int i{}; i < li.count1; i++) {
//				push(tmp->value, 1);
//				tmp = tmp->prev;
//			}
//			tmp = li.end;
//			for (int i{}; i < li.count2 - 1; i++) {
//				tmp = tmp->prev;
//			}
//			for (int i{}; i < li.count2; i++) {
//				push(tmp->value, 2);
//				tmp = tmp->next;
//			}
//		}
//		else if (li.count2) {
//			tmp = li.end;
//			for (int i{}; i < li.count2 - 1; i++)
//				tmp = tmp->prev;
//			while (tmp) {
//				push(tmp->value, 2);
//				tmp = tmp->next;
//			}
//		}
//		else {
//			std::cout << "Список пуст\n";
//		}
//	}
//	return *this;
//}
//
//
//bool List::operator!=(const List& l2) {
//	return (this->count2 != l2.count1);
//}