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

			/*! Cria os nós principais da lista duplamente encadeada. Nó cabeça e Nó Calda. */
			void create_mainNodes() {
				m_head = new Node();
				m_tail = new Node();
				m_head->next = m_tail;
				m_tail->prev = m_head;
			}



		public:
			/* Iterators */

			/// Iterator
			class iterator {
				public:
					/// Construtor padrão.
					iterator(Node *it = nullptr) {
						current = it;
					}
					/*! Pré incremento. Avança o iterador para o proximo nó.*/
					iterator &operator++() {
						current = current->next;
						return *this;
					}
					/*! Pós incremento. Avança o iterador para o proximo nó.*/
					iterator operator++(int) {
						iterator temp = current;
						current = current->next;
						return temp;
					}
					/*! Pré decremento. Regride o iterador para o nó anterior.*/
					iterator &operator--() {
						current = current->prev;
						return *this;
					}
					/*! Pós decremento. Regride o iterador para o nó anterior.*/
					iterator operator--(int) {
						iterator temp = current;
						current = current->prev;
						return temp;
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
			/// Cons_Iterator
			class const_iterator {
				public:
					/// Construtor padrão.
					const_iterator(Node *it = nullptr) {
						current = it;
					}
					/*! Pré incremento. Avança o iterador para o proximo nó.*/
					const_iterator &operator++() {
						current = current->next;
						return *this;
					}
					/*! Pós incremento. Avança o iterador para o proximo nó.*/
					const_iterator operator++(int) {
						const_iterator temp = current;
						current = current->next;
						return temp;
					}
					/*! Pré decremento. Regride o iterador para o nó anterior.*/
					const_iterator &operator--() {
						current = current->prev;
						return *this;
					}
					/*! Pós decremento. Regride o iterador para o nó anterior.*/
					const_iterator operator--(int) {
						const_iterator temp = current;
						current = current->prev;
						return temp;
					}

					T &operator*() {
						return current->data;
					}

					bool operator==(const const_iterator &rhs) const {
						return current == rhs.current;
					}
					bool operator!=(const const_iterator &rhs) const {
						return !(current == rhs.current);
					}

				private:
					const Node *current; //<! Ponteiro para nó.
					
			};


			/// Construtor padrão.
			list() {
				create_mainNodes(); // Cria os nós cabeça e calda da lista.
			}
			/// Construtor explicit.
			explicit list(size_type count) {
				create_mainNodes();
				for(size_type i = 0; i < count; i++) {
					push_back(int()); // Cria um nó e o inicia com o tipo inteiro padrão.
				}
			}
			/// Construtor with range.
			template<typename InputIt>
			list(InputIt first, InputIt last) {
				create_mainNodes();
				while(first != last) {
					push_back(*first);
					first++;
				}
			}
			/// Construtor com lista inicializadora.
			list(std::initializer_list<T> ilist) {
				create_mainNodes();
				auto ilistTemp = ilist.begin();
				while(ilistTemp != ilist.end()) {
					push_back(*ilistTemp);
					ilistTemp++;
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

			bool operator==(const list &other) {
				// Verificar se as listas possuem tamanhos diferentes. Caso sim, elas são diferentes.
				if(other.m_size != m_size) {
					return false;
				}
				// Caso tenham o mesmo tamanho, comparar todos os nós para verificar se possuem elementos diferentes.
				Node *temp1 = m_head;
				Node *temp2 = other.m_head;

				while(temp1 != m_tail) {
					temp1 = temp1->next;
					temp2 = temp2->next;
					// Caso encontre algum valor diferente na mesma posição que na outra lista, elas são diferentes.
					if(temp1->data != temp2->data) {
						return false;
					}
				}
				// Caso passe por todos os testes acima e não tenha sido invalidado a igualdade elas são iguais.
				return true;

			}

			bool operator!=(const list &other) {
				return !(*this == other); // Caso as listas não sejam iguais elas são diferentes.
			}


		private:
			size_type m_size = 0; // Toda lista criada tem inicialmente tamanho zero.
			Node *m_head;
			Node *m_tail;
						
	};
	

}

#endif