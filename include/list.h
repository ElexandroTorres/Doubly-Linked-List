#ifndef LIST_H
#define LIST_H

namespace sc {
	template<typename T>
	class list {
		private:
			using size_type = unsigned long;
			struct Node {
				T data; //<! Dados do elemento.
				Node *prev; //<! Nó que aponta para o Nó anterior.
				Node *next; //<! Nó que aponta para o Nó seguinte.
				/// Construtor basico.
				Node(const T &data_ = T(), Node *prev_ = nullptr, Node *next_ = nullptr) {
					data = data_;
					prev = prev_;
					next = next_;
				}
			};

		public:
			/* Iterators */

			/// Iterator
			class iterator{
				public:
					/// Construtor padrão.
					iterator(Node *it = nullptr) {
						current = it;
					}

					iterator &operator++() {
						current = current->next;
						return *this;
					}

					iterator &operator--() {
						current = current->prev;
						return *this;
					}

					T &operator*() {
						return current->data;
					}

					bool operator==(const iterator &rhs) const {
						return current == rhs.current;
					}
					bool operator!=(const iterator &rhs) const {
						return !(current == rhs.current);
					}

				private:
					Node *current; //<! Ponteiro para nó.
					
			};


			/// Construtor padrão.
			list() {
				m_head = new Node();
				m_tail = new Node();
				m_head->next = m_tail;
				//m_head->prev = nullptr;
				//m_tail->next = nullptr;
				m_tail->prev = m_head;
				m_size = 0;
			}
			/// Construtor com lista inicializadora.
			list(std::initializer_list<T> ilist) {
				m_head = new Node();
				m_tail = new Node();
				m_head->next = m_tail;
				m_tail->prev = m_head;

				for(auto it = ilist.begin(); it != ilist.end(); it++) {
					push_back(*it);
				}	
				
			}
			/// Destrutor.
			~list() {
				// Remover todos os nós.
				clear();
				// Por fim remover o head e o tail.
				delete m_head;
				delete m_tail;
			}

			/* Operations */

			/*!
			 * @return O numero de elemtnos da lista.
			*/
			size_type size() const {
				return m_size;
			}
			/*!
			 * Limpa a lista, excluindo os elementos e liberando a memoria dos nós que os armazena.
			*/
			void clear() {
				while(m_head->next != m_tail) {
					pop_back();
				}
				m_size = 0;
			}
			/*
			 * Verifica se a lista está vazia.
			 * @return true caso esteja vazia e false caso contrario.
			*/
			bool empty() {
				return (m_size == 0);
			}
			/*!
			 * Adiciona um determinado valor no inicio da lista.
			 * @param value Valor a ser adicionado no inicio da lista.
			*/
			void push_front(const T &value) {
				Node *temp = m_head->next;
				Node *newNode = new Node(value, m_head, temp);
				m_head->next = newNode;
				temp->prev = newNode;
				m_size++;
			}
			/*!
			 * Adiciona um determinado valor no final da lista.
			 * @param value Valor a ser adicionado no final da lista.
			*/
			void push_back(const T &value) {
				Node *temp = m_tail->prev;
				Node *newNode = new Node(value, temp, m_tail);
				m_tail->prev = newNode;
				temp->next = newNode;
				m_size++;
			}
			/*!
			 * Remove o elemento no final da lista.
			*/
			void pop_back() {
				if(m_tail->prev != m_head) {
					Node *temp = m_tail->prev;
					Node *target = m_tail->prev;
					temp = temp->prev;
					delete target;
					temp->next = m_tail;
					m_tail->prev = temp;
					m_size--;
				}
			}
			/*!
			 * Remove o elemento no inicio da lista.
			*/
			void pop_front() {
				if(m_head->next != m_tail) {
					Node *temp = m_head->next;
					Node *target = m_head->next;
					temp = temp->next;
					delete target;
					temp->prev = m_head;
					m_head->next = temp;
					m_size--;
				}
			}
			/*!
			 * @return O elemento no final da lista.
			*/
			const T &back() const {
				if(m_tail->prev != m_head) {
					Node *target = m_tail->prev;
					return target->data;
				}
				//retornar alguma coisa.
			}
			/*!
			 * @return O elemento no inicio da lista.
			*/
			const T &front() const {
				if(m_head->next != m_tail) {
					Node *target = m_head->next;
					return target->data;
				}
				//retornar alguma coisa.
			}
			/*!
			 * Substituio conteudo da lista com uma certa quantiade de uma determinado valor.
			 * @param count Quantidade de elementos que terão na lista.
			 * @param value Valor que será inserido em toda a lista.
			*/
			void assign(const size_type &count, const T &value) {
				clear();
				for(size_type i = 0; i < count; i++) {
					push_back(value);
				}
			}

			/* Operations with iterators */

			/*!
			 * @return Um iterator para o inicio da lista.
			*/
			iterator begin() {
				return iterator(m_head->next); // Retorna um iterator para o elemento seguinte ao m_head.
			}
			/*!
			 * @return Um iterator para o final da lista. m_tail.
			*/
			iterator end() {
				return iterator(m_tail);
			}
			//imprime a lista.
			void print() {
				Node *it = m_head->next;
				while(it != m_tail) {
					std::cout << it->data << " ";
					it = it->next;
				}
				std::cout << "\n";
			}


		private:
			size_type m_size;
			Node *m_head;
			Node *m_tail;
						
	};
}

#endif