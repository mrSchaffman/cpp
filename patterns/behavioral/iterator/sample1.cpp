/**
 * This is only for demonstration purpose
 * Use it at your own Risks
 * 
*/

#include<iostream>
namespace entity
{
    namespace node
    {
        template <class T>
        class Node
        {
        private:
            Node *m_next = nullptr;
            T m_value{};

        public:
            Node(const T &value, Node *nextNode = nullptr):m_value(value),m_next(nextNode) {}
            Node(Node *nextNode = nullptr):m_next(nextNode) {}
            ~Node() { if(m_next)delete m_next; }
        };

        template <class T>
        class NodeChainIterator
        {
        private:
            Node<T> *m_current = nullptr;

        public:
            NodeChainIterator(Node<T> *currentNode) : m_current(currentNode) {}
            ~NodeChainIterator() { delete m_current;}
            T operator*() { return *this; }
            // TODO operator++, operator--...
        };

        template<class T>
        class NodeChainInterface
        {
        private:
            Node<T> *m_first = nullptr;
            Node<T> *m_last = nullptr;
            unsigned int m_count{};
        protected:
            NodeChainInterface(Node<T> *first, Node<T> *last):m_first(first),m_last(last) {}

        public:
            virtual~NodeChainInterface() { destroy();}
            bool isEmpty() const { return m_count == 0; }

            // the use of iterators
            NodeChainIterator<T> begin() {
                NodeChainIterator<T> temp(m_first);
                return temp;
            }
            NodeChainIterator<T> end() {
                NodeChainIterator<T> temp(nullptr);
                return temp;
            }
            virtual void insert(const T &newItem) = 0;
            // virtual void insertFront(const T &newItem) = 0;
            // ...

        private:
            void destroy()noexcept{
                Node<T> *temp;
                while (m_first != nullptr)
                {
                    temp = m_first;
                    m_first = m_first->m_next;
                    delete temp;
                }
                m_count = 0;
                m_last = nullptr;
            }
        };

        template<class T>
        class OneDirectionNodeChain: protected NodeChainInterface<T>
        {
        private:
            Node<T>* m_first = nullptr;
            Node<T>* m_current = nullptr;
            Node<T>* m_last = nullptr;
            unsigned int m_size{};

        public:
            using NodeChainInterface<T>::begin;
            using NodeChainInterface<T>::end;
            using NodeChainInterface<T>::isEmpty;

            virtual void insert(const T &newItem) override
            {
                m_current = new Node<T>(newItem, m_current->m_next);
                if (m_last==m_current)
                    m_last = m_current->m_next;
                m_count++;
            }

            OneDirectionNodeChain(unsigned int size) {
                m_first = m_current = m_last = new Node<T>;
                m_size = size;
                NodeChainInterface<T>::NodeChainInterface<T>(m_first, m_last);
            }
            ~OneDirectionNodeChain() { destroy(); }

        private:
            void destroy()noexcept{
                while (m_first!=nullptr)
                {
                    m_current = m_first;
                    m_first = m_first->m_next;
                    delete m_current;
                }
            }
        };
    } // namespace node
    
  
} // namespace entity

int main(){
    using namespace entity::node;
    OneDirectionNodeChain<int> nList(5);
    nList.insert(10);
    nList.insert(20);
    nList.insert(30);

    auto beginIter = nList.begin();
    auto endIter = nList.end();
    nList.isEmpty();
    std::cout << nList.isEmpty() << "\n";
    std::cout << *beginIter << " -> " << *endIter << "\n";
    
    return 0;
}