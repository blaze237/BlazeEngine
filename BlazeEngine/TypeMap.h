#pragma once
#include <unordered_map>
#include <atomic>
#include "Component.h"
#include <vector>

#include <unordered_map>
#include <atomic>


//This is copy-paste as is to understand the logic. Needs reimplemting with niver wrapper functions
template <class ValueType>
class TypeMap {
	// Internally, we'll use a hash table to store mapping from type
	// IDs to the values.
	typedef std::unordered_map<int, ValueType> InternalMap;
public:
	typedef typename InternalMap::iterator iterator;
	typedef typename InternalMap::const_iterator const_iterator;
	typedef typename InternalMap::value_type value_type;

	const_iterator begin() const { return m_map.begin(); }
	const_iterator end() const { return m_map.end(); }
	iterator begin() { return m_map.begin(); }
	iterator end() { return m_map.end(); }

	// Finds the value associated with the type "Key" in the type map.
	template <class Key>
	iterator find() { return m_map.find(getTypeId<Key>()); }

	// Same as above, const version
	template <class Key>
	const_iterator find() const { return m_map.find(getTypeId<Key>()); }

	// Associates a value with the type "Key"
	template <class Key>
	void put(ValueType &&value) {
		m_map[getTypeId<Key>()] = std::forward<ValueType>(value);
	}

private:
	template <class Key>
	inline static int getTypeId() {
		static const int id = LastTypeId++;
		return id;
	}

	static int LastTypeId;
	InternalMap m_map;
};
template <class ValueType>
int TypeMap<ValueType>::LastTypeId(0);


////template <class ComponentType> 
//class ComponentMap
//{
//public:
//	ComponentMap(){}
//	~ComponentMap(){}
//
//	//Typedef for convience
//	typedef std::unordered_multimap<int, Component*> HashTable;
//	
//	
//	//Interface functions for accessing some standard HashTable iterator functionality 
//	inline HashTable::const_iterator begin() const { 
//		return hashTable.begin(); 
//	}
//	inline HashTable::const_iterator end() const {
//		return hashTable.end(); 
//	}
//	//Const versions
//	inline HashTable::iterator begin() { 
//		return hashTable.begin(); 
//	}
//	inline HashTable::iterator end() {
//		return hashTable.end(); 
//	}
//
//
//	//Return pointer to the first instance of stored component of provided type if one exists.
//	template <class Key>
//	Key* GetComponent()
//	{
//		auto it = hashTable.find(getTypeId<Key>());
//
//		if (it != end())
//			return static_cast<Key*>(it->second);
//		else
//			return NULL;
//	}
//
//
//	//Return pointer to the first instance of stored component of provided type if one exists.
//	template <class Key>
//	std::vector<Key*> GetComponent()
//	{
//		std::vector<Key*> components;
//
//		auto range = hashTable.equal_range(getTypeId<Key>());
//		//Do check	//Need to check the pairs for get al ad return will be diff
//		for (auto it = range.first; it != range.second; ++it) 
//		{
//			components.push_back(it->second);
//		}
//	}
//
//
//
//private:
//	HashTable hashTable;
//	static std::atomic_int LastTypeId;
//
//	  template <class Key>
//  inline static int getTypeId() {
//    static const int id = LastTypeId++;
//    return id;
//  }
//
//
//
//};
//
