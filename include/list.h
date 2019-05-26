#ifndef LIST_H
#define LIST_H

namespace ls {
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
			/// Construtor padrão.
			list() {
				m_head = new Node();
				m_tail = new Node();
				m_head->next = m_tail;
				m_head->prev = nullptr;
				m_tail->next = nullptr;
				m_tail->prev = m_head;
				m_size = 0;
			}
			/// Destrutor.
			~list() {
				// Remover todos os nós.
				while(m_head->next != m_tail) {
					pop_back();
				}
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