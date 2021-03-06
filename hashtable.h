#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "fstream"
#include "cmath"
#include <iostream>
#include "string.h"

template<typename T1, typename T2>
class HashTable;


template<typename T1, typename T2>
std::ofstream& operator << (std::ofstream& stream, HashTable<T1, T2> const & existing)
{
    stream << existing.length << std::endl;
    typename HashTable<T1, T2>::Node* node;
    for(unsigned int i = 0; i < existing.tableSize; i++)
    {
        if(existing.hashTable[i])
        {
            node = existing.hashTable[i];
            while(node)
            {
                stream << *(node->key) << std::endl;
                stream << *(node->object) << std::endl;
                node = node->next;
            }
        }
    }
}

template<typename T1, typename T2>
std::ifstream& operator >> (std::ifstream& stream, HashTable<T1, T2> &existing)
{
    unsigned int length;
    existing.deleteAll();
    stream >> length;
    T1 key;
    T2 value;
    for(unsigned int i =0; i < length; i++)
    {
        stream >> key;
        stream >> value;
        existing.addPair(key, value);
    }
}

template<typename T1, typename T2>
class HashTable
{
private:
    struct Node;
public:
    class Iterator
    {
    public:
        Iterator();
        ~Iterator();
        friend HashTable;
        Iterator(Iterator const &);
        Iterator(Node*, const HashTable *parent);
        Iterator& operator ++();
        Iterator operator ++(int);
        bool operator == (Iterator const &) const;
        bool operator != (Iterator const &) const;
        T1 operator *();
        T2 getValue() const;
    private:
        Node *node;
        const HashTable *parent;
    };
    friend Iterator;
    HashTable();
    ~HashTable();
    HashTable(HashTable const &);
    void addPair(T1 const &, T2 const &);
    bool isPresent(T1 const) const;
    void deleteKey(T1 const);
    void deleteAll();
    unsigned int getLength() const {return length;}
    Iterator begin();
    Iterator end();
    bool operator == (HashTable const &) const;
    bool operator != (HashTable const &) const;
    T2& operator [] (T1 const &) const;
    friend std::ofstream& operator << <T1, T2> (std::ofstream&, HashTable const &);
    friend std::ifstream& operator >> <T1, T2> (std::ifstream& stream, HashTable &existing);
    T2 bankProfit() const;
private:
    struct Node
    {
        T2* object;
        T1* key;
        Node* next;
        Node();
        ~Node();
    };
    unsigned int length;
    unsigned int tableSize;
    Node** hashTable;

};



template<typename T1, typename T2>
HashTable<T1, T2>::Node::Node()
{
    object = nullptr;
    key = nullptr;
    next = nullptr;
}
/*
unsigned int hash(const std::string const &key);
*/
template<typename T1>
unsigned int hash(T1 const &key)
{
    return(static_cast<unsigned int>(1024*fmod(key*0.618033, 1)));
}

template<>
unsigned int hash<std::string>(std::string const &key);

template<typename T1, typename T2>
HashTable<T1, T2>::HashTable():
    length(0),
    tableSize(256),
    hashTable(new Node*[256])
{
    for(unsigned int i = 0; i <= tableSize; i++)
    {
        hashTable[i] = nullptr;
    }
}

template<typename T1, typename T2>
HashTable<T1, T2>::Node::~Node()
{
    delete object;
    delete key;
    if(next)
    {
        delete next;
    }
}

template<typename T1, typename T2>
HashTable<T1, T2>::~HashTable()
{
    for(unsigned int i = 0; i < tableSize; i++)
    {
        if(hashTable[i])
        {
            delete hashTable[i];
            hashTable[i] = nullptr;
        }
    }
}
// Пользователь даёт ключ и значение
// хэш не зависит от значение, а зависит от ключа
// полученный ключ отправляется во внешнюю функцию хэша
// в классе берётся остаток от деления хэша на размер таблицы, чтобы получить индекс
// запись хранит ещё и ключ для проверок соответствия
// хэш != ключ
// шаблон лучше создать сразу

template<typename T1, typename T2>
void HashTable<T1, T2>::addPair(T1 const &key, T2 const &value)
{
    unsigned int bucket = hash(key) % tableSize;
    Node *existing;
    if(isPresent(key))
    {
        existing = hashTable[bucket];
        while(existing)
        {
            if(*(existing->key) == key )
            {
                break;
            }
        }
        *(existing->object) += value;
    }
    else
    {
        existing = new Node();
        existing->object = new T2(value);
        existing->key = new T1(key);
        if(hashTable[bucket])
        {
            existing->next = hashTable[bucket];
        }
        else
        {
            existing->next = nullptr;
        }
        hashTable[bucket] = existing;
        length++;
    }
}

template<typename T1, typename T2>
bool HashTable<T1, T2>::isPresent(T1 const key) const
{
    unsigned int bucket = hash(key) % tableSize;
    if(hashTable[bucket])
    {
        Node* existingNode = hashTable[bucket];
        while (existingNode)
        {
            if(*(existingNode->key) == key)
            {
                return true;
            }
            existingNode = existingNode->next;
        }
    }
    return false;
}

template<typename T1, typename T2>
void HashTable<T1, T2>::deleteKey(T1 const key)
{

    if(isPresent(key))
    {
        unsigned int bucket;
        bucket = hash(key) % tableSize;
        Node* current = hashTable[bucket];
        Node* previous = nullptr;
        if(!(current->next))
        {
            delete current;
            hashTable[bucket] = nullptr;
        }
        else
        {
            if(*(current->key) == key)
            {
                if(!previous)
                {
                    hashTable[bucket] = current->next;
                    delete current;
                }
            }
            else
            {
                previous = current;
                current = current->next;
                while(current)
                {
                    if(*(current->key) == key)
                    {
                        previous->next = current->next;
                        delete current;
                        break;
                    }
                    current = current->next;
                }
            }
        }
        length--;
    }
}

template<typename T1, typename T2>
void HashTable<T1, T2>::deleteAll()
{
    for(unsigned int i = 0; i < tableSize; i++)
    {
        delete hashTable[i];
        hashTable[i] = nullptr;
    }
    length = 0;
}

template<typename T1, typename T2>
T2& HashTable<T1, T2>::operator[](T1 const &key) const
{
    if(isPresent(key))
    {
        Node* current = hashTable[hash(key)%tableSize];
        while(current)
        {
            if(*(current->key) == key)
            {
                return *(current->object);
            }
            current = current->next;
        }
    }
}

template<typename T1, typename T2>
bool HashTable<T1, T2>::operator==(HashTable const &existing) const
{
    unsigned int i;
    int key;
    if(length != existing.length)
    {
        return false;
    }
    for( i = 0; i < tableSize; i ++)
    {
        if(hashTable[i])
        {
            key = *(hashTable[i]->key);
            if(existing.isPresent(key))
            {
                if(this->operator[](key) != existing[key])
                {
                    return false;
                }
            }
        }
    }
    return true;
}


template<typename T1, typename T2>
bool HashTable<T1, T2>::operator != (HashTable const &existing) const
{
    return(!(*this == existing));
}

template<typename T1, typename T2>
HashTable<T1, T2>::HashTable(HashTable const &existing):
    length(0),
    tableSize(existing.tableSize),
    hashTable(new Node*[tableSize])
{
    for(unsigned int i = 0; i <= tableSize; i++)
    {
        hashTable[i] = nullptr;
    }
    unsigned int i;
    for( i = 0 ; i < tableSize ; i++ )
    {
        if(existing.hashTable[i])
        {
            addPair(*(existing.hashTable[i]->key), *(existing.hashTable[i]->object));
        }
    }
}

template<typename T1, typename T2>
HashTable<T1, T2>::Iterator::Iterator():
    node(nullptr),
    parent(nullptr)
{

}

template<typename T1, typename T2>
HashTable<T1, T2>::Iterator::~Iterator()
{

}

template<typename T1, typename T2>
HashTable<T1, T2>::Iterator::Iterator(HashTable::Iterator const &existing):
    node(existing.node),
    parent(existing.parent)
{
}

template<typename T1, typename T2>
typename HashTable<T1, T2>::Iterator& HashTable<T1, T2>::Iterator::operator ++()
{
    unsigned int i;
    HashTable<T1, T2>::Node *temp;
    if(node->next != nullptr)
    {
        node = node->next;
        return *this;
    }
    for( i = 0; i < parent->tableSize; i++)
    {
        temp = parent->hashTable[i];
        while(temp && temp != node)
        {
            temp = temp->next;
        }
        if(temp)
        {
            break;
        }
    }
    i++;
    while(parent->hashTable[i] && i < parent->tableSize)
    {
        i++;
    }
    if(i != parent->tableSize)
    {
        node = parent->hashTable[i];
    }
    return *this;
}

template<typename T1, typename T2>
typename HashTable<T1, T2>::Iterator HashTable<T1, T2>::Iterator::operator++(int)
{
    unsigned int i;
    HashTable<T1, T2>::Iterator prev = *this;
    HashTable<T1, T2>::Node *temp;
    if(node->next != nullptr)
    {
        node = node->next;
        return prev;
    }
    for( i = 0; i < parent->tableSize; i++)
    {
        temp = parent->hashTable[i];
        while(temp && temp != node)
        {
            temp = temp->next;
        }
        if(temp)
        {
            break;
        }
    }
    i++;
    while(!parent->hashTable[i] && i < parent->tableSize)
    {
        i++;
    }
    if(i != parent->tableSize)
    {
        node = parent->hashTable[i];
    }
    return  prev;
}

template<typename T1, typename T2>
T1 HashTable<T1, T2>::Iterator::operator*()
{
    return (*(node->key));
}

template<typename T1, typename T2>
T2 HashTable<T1, T2>::Iterator::getValue() const
{
    return (*(node->object));
}

template<typename T1, typename T2>
bool HashTable<T1, T2>::Iterator::operator==(Iterator const &existing) const
{
    if(*(node->object) == *(existing.node->object) &&
            *(node->key) == *(existing.node->key) &&
            parent == existing.parent)
    {
        return true;
    }
    return false;
}

template<typename T1, typename T2>
bool HashTable<T1, T2>::Iterator::operator!=(Iterator const &existing) const
{
    return(!(this->operator==(existing)));
}

template<typename T1, typename T2>
typename HashTable<T1, T2>::Iterator HashTable<T1, T2>::begin()
{
    HashTable<T1, T2>::Iterator *iter;
    if(length > 0)
    {
        unsigned int i = 0 ;
        while (!hashTable[i])
        {
            i++;
        }
        iter = new HashTable<T1, T2>::Iterator(hashTable[i], this);

    }
    return *iter;
}

template<typename T1, typename T2>
typename HashTable<T1, T2>::Iterator HashTable<T1, T2>::end()
{
    HashTable<T1, T2>::Iterator *iter;
    if(length > 0)
    {
        unsigned int i = tableSize;
        while (!hashTable[i])
        {
            i--;
        }
        iter = new HashTable<T1, T2>::Iterator(hashTable[i], this);
        while(iter->node->next)
        {
            iter->node = iter->node->next;
        }
    }
    return *iter;
}

template<typename T1, typename T2>
HashTable<T1, T2>::Iterator::Iterator(typename HashTable<T1, T2>::Node* existing,
                                      const HashTable<T1, T2> *parentNew)
{
    node = existing;
    parent = parentNew;
}

template<typename T1, typename T2>
T2 HashTable<T1, T2>::bankProfit() const
{
   T2 answer = 0;
   for(unsigned int i = 0; i < tableSize; i++)
   {
       if(hashTable[i])
       {
           answer += *(hashTable[i]->object) / 10;
       }
   }
   return answer;
}

#endif // HASHTABLE_H