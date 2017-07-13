#pragma onceMap
#include <unordered_map>
#include <atomic>
#include "Component.h"
#include <vector>

#include <unordered_map>
#include <atomic>


//This is copy-paste as is to understand the logic. Needs reimplemting with niver wrapper functions


template <class ComponentType>
class ComponentMap {

public:
	//Use some typedefs for convienience
	typedef std::unordered_multimap<int, ComponentType> Map;
	typedef typename Map::iterator iterator;
	typedef typename Map::const_iterator const_iterator;

//Interfacing functions for accessing standard hash table functionality from outside the class
	
	//Iterator functions
	const_iterator Begin() const { return m_map.begin(); }
	const_iterator End() const { return m_map.end(); }
	iterator Begin() { return m_map.begin(); }
	iterator End() { return m_map.end(); }
	
	//Return number of elements in the container.
	unsigned int Size() const { return m_map.size(); }
	//Return number of elements of given type present in the container.
	template <class Key>
	unsigned int Count()  const { return m_map.count(getTypeId<Key>()); }

	//Get the first instance of stored component mathcing supplied type.
	template <class Key>
	Key GetComponent() 
	{
		auto it = m_map.find(getTypeId<Key>());

		if (it != End())
			return static_cast<Key>(it->second);
		else
			return NULL;
	}



	//Get the first instance of stored component mathcing supplied type.
	template <class Key>
	Key GetComponent() const
	{
		auto it = m_map.find(getTypeId<Key>());

		if (it != End())
			return static_cast<Key>(it->second);
		else
			return NULL;
	}


	//Return a vector of all instances of a given type in the table.
	template <class Key>
	std::vector<Key> GetComponents()
	{
		std::vector<Key> components;
	
		//No need to check if there are any of this component present in the hash table, as if there arent then an empty range will be given
		auto range = m_map.equal_range(getTypeId<Key>());

		for (auto it = range.first; it != range.second; ++it)
			components.push_back(static_cast<Key>((it->second)));
	
		return components;
	}

	//Const version of above
	template <class Key>
	std::vector<Key> GetComponents() const
	{
		std::vector<Key> components;

		//No need to check if there are any of this component present in the hash table, as if there arent then an empty range will be given
		auto range = m_map.equal_range(getTypeId<Key>());

		for (auto it = range.first; it != range.second; ++it)
			components.push_back(static_cast<Key>((it->second)));

		return components;
	}


	// Associates a value with the type "Key"
	template <class Key>
	void AddComponent(ComponentType &&value) {
		m_map.insert(std::make_pair<int, ComponentType>(getTypeId<Key>(),std::forward<ComponentType>(value)));
	}

private:
	template <class Key>
	inline static int getTypeId() {
		static const int id = LastTypeId++;
		return id;
	}

	static int LastTypeId;
	Map m_map;
};
template <class ComponentType>
int ComponentMap<ComponentType>::LastTypeId(0);


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
