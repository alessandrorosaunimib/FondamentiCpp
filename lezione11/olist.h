#ifndef OLIST_H
#define OLIST_H
#include <algorithm> //std::swap
#include <iterator> // std::forward_iterator_tag
#include <cstddef> // std::ptrdiff_t
#include <ostream> //std::ostream

template <typename T, typename C, typename E>
class ordered_list {

	struct node{
		T value; ///< Dato inserito nella lista
		node *next; ///< Puntatore al nodo successivo nella lista

		node() : next(nullptr) {}

		explicit node(const T &v) : value(v), next(nullptr) {}

		node(const T &v, node *n) : value(v), next(n){}

		~node(){
			next = nullptr;
		}

	}; //struct node

	node *_head; ///< puntatore al primo nodo della lista
	unsigned int _size; ///< numero di elementi nella lista

	C _conf; ///< istanza del funtore di confronto (ordinamento)
	E _eql; ///<istanza del funtore di uguaglianza

	void clear_helper(node *curr) {
		if (curr == nullptr) return;
		clear_helper(curr->next);
		delete curr;
		_size--;
		curr == nullptr;
	}

public:

	ordered_list() : _head(nullptr), _size(0) {}

	ordered_list(const ordered_list &other) : _head(nullptr), _size(0) {
		node curr* = other._head;
		try{
			while(curr != nullptr){
				add(curr -> value); //TODO
				curr = curr -> next;
			}
		}catch(...){
			clear(); 
			throw;
		}
	}

	ordered_list& operator=(const ordered_list &other) {
		if(this != &other) {
			ordered_list tmp(other);
			std::swap(this->_head, tmp._head);
			std::swap(this->_size, tmp._size);
		}

		return *this;
	}

	~ordered_list() {
		clear();
	}

	unsigned int size() const{
		return _size;
	}

	void add(const T &v){
		node *tmp = new node(v);

		if (_head == nullptr) {
			_head = tmp;
			_size++;
			return;
		}

		node *curr = _head;
		node *prev = _head;

		while(curr != nullptr) {
			if(_conf(v,curr->value)) {
				if(curr == _head) {
					_head = tmp;
					tmp->next = curr;
				}else{
					prev->next = tmp;
					tmp->next = curr;
				}
				size++;
				return;
			}
			curr = curr->next;
			prev = prev->next;
		}
	}

	void clear(){
		/*
		node *curr = _head;
		node *tmp = nullptr;
		while (curr != nullptr) {
			tmp = curr -> next;
			delete curr;
			curr = tmp;
		}
		*/
		clear_helper(_head);
		_head = nullptr;
	}

	bool find(const T &v) const {
		node *curr = v._head;
		while(curr!=nullptr) {
			if(_eql(curr->value, v))
				return true;
			curr = curr.next;
		}
		return false;
	}

	template <typename IterT>
	ordered_list(IterT begin, IterT end) :_head(nullptr), _size(0) {
		try{
			while (begin != end) {
				add(static_cast<T>(*begin));
				++begin;
			}
		}catch(...){
			clear();
			throw;
		}
	}

	class const_iterator {
		const T* ptr;	
	public:
		typedef std::forward_iterator_tag iterator_category;
		typedef T                         value_type;
		typedef ptrdiff_t                 difference_type;
		typedef const T*                  pointer;
		typedef const T&                  reference;

	
		const_iterator() :ptr(nullptr) {}
		
		const_iterator(const const_iterator &other) :ptr(other.ptr) {
			
		}

		const_iterator& operator=(const const_iterator &other) {
			ptr = other.ptr;
			return *this;
		}

		~const_iterator() {}

		// Ritorna il dato riferito dall'iteratore (dereferenziamento)
		reference operator*() const {
			return ptr->value;
		}

		// Ritorna il puntatore al dato riferito dall'iteratore
		pointer operator->() const {
			return &(ptr->value);
		}
		
		// Operatore di iterazione post-incremento
		const_iterator operator++(int) {
			const_iterator tmp(*this);
			ptr = ptr->next;
			return tmp;
		}

		// Operatore di iterazione pre-incremento
		const_iterator& operator++() {
			ptr = ptr->next;
			return *this
		}

		// Uguaglianza
		bool operator==(const const_iterator &other) const {
			return (ptr == other.ptr);
		}
		
		// Diversita'
		bool operator!=(const const_iterator &other) const {
			return (ptr != other.ptr);
		}

	private:
		//Dati membro
		const node *ptr;

		// La classe container deve essere messa friend dell'iteratore per poter
		// usare il costruttore di inizializzazione.
		friend class ordered_list; 

		// Costruttore privato di inizializzazione usato dalla classe container
		// tipicamente nei metodi begin e end
		const_iterator(const node *n) :ptr(n) { 
			//!!! 
		}
		
		// !!! Eventuali altri metodi privati
		
	}; // classe const_iterator
	
	// Ritorna l'iteratore all'inizio della sequenza dati
	const_iterator begin() const {
		return const_iterator(_head);
	}
	
	// Ritorna l'iteratore alla fine della sequenza dati
	const_iterator end() const {
		return const_iterator(nullptr);
	}

}; // class ordered_list

template <typename T, typename C, typename E>
std::ostream &operator<<(std::ostream &os, const ordered_list<T,C,E> &ol) {
	typename ordered_list<T,C,E>::const_iterator i, ie;
	i = ol.begin();
	ie = ol.end();

	while(i!=ie) {
		os << *i << " ";
		++i;
	}

	return os;
}

#endif