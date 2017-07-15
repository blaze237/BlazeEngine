//This code works fine but is very flawed. There is no easy way of supporting polymorphism with this system, as such a simple iterative searcg using dyanmic casts will be used for
//component fetching instead. In a well designed game getComponent calls will be kept to a min anyway, and for the order of ten or so components, the perfomance lost should be 
//neglibigble and far outweighed by the better polymorphism support

//#pragma once
//#include <unordered_map>
//#include <atomic>
//#include "Component.h"
//#include <vector>
//#include <unordered_map>
//
//
//
//#include <unordered_map>
//#include <atomic>
//
//
//template <class ComponentType>
//class ComponentMap {
//
//public:
//	//Use some typedefs for convienience
//	typedef std::unordered_multimap<int, ComponentType> Map;
//	typedef typename Map::iterator iterator;
//	typedef typename Map::const_iterator const_iterator;
//
////Interfacing functions for accessing standard hash table functionality from outside the class
//	
//	//Iterator functions
//	const_iterator Begin() const { return m_map.begin(); }
//	const_iterator End() const { return m_map.end(); }
//	iterator Begin() { return m_map.begin(); }
//	iterator End() { return m_map.end(); }
//	
//	//Return number of elements in the container.
//	unsigned int Size() const { return m_map.size(); }
//	//Return number of elements of given type present in the container.
//	template <class Key>
//	unsigned int Count()  const { return m_map.count(getTypeId<Key>()); }
//
//	//Get the first instance of stored component mathcing supplied type.
//	template <class Key>
//	Key GetComponent() 
//	{
//		auto it = m_map.find(getTypeId<Key>());
//
//		if (it != End())
//			return static_cast<Key>(it->second);
//		else
//			return NULL;
//	}
//
//
//
//	//Get the first instance of stored component mathcing supplied type.
//	template <class Key>
//	Key GetComponent() const
//	{
//		auto it = m_map.find(getTypeId<Key>());
//
//		if (it != End())
//			return static_cast<Key>(it->second);
//		else
//			return NULL;
//	}
//
//
//	//Return a vector of all instances of a given type in the table.
//	template <class Key>
//	std::vector<Key> GetComponents()
//	{
//		std::vector<Key> components;
//	
//		//No need to check if there are any of this component present in the hash table, as if there arent then an empty range will be given
//		auto range = m_map.equal_range(getTypeId<Key>());
//
//		for (auto it = range.first; it != range.second; ++it)
//			components.push_back(static_cast<Key>((it->second)));
//	
//		return components;
//	}
//
//	//Const version of above
//	template <class Key>
//	std::vector<Key> GetComponents() const
//	{
//		std::vector<Key> components;
//
//		//No need to check if there are any of this component present in the hash table, as if there arent then an empty range will be given
//		auto range = m_map.equal_range(getTypeId<Key>());
//
//		for (auto it = range.first; it != range.second; ++it)
//			components.push_back(static_cast<Key>((it->second)));
//
//		return components;
//	}
//
//
//	// Associates a value with the type "Key"
//	//Optionaly can also associate it with an alias class, this is intended to allow for the use of polymorphism.
//	//E.G storing all subclasses of a collider component as both their own type, and as a colider and being able to 
//	//acess them all at once by asking for all coliders, as this behaviour is not inherently provided by the data structure.
//	template <class Key, class Alias = Key>
//	void AddComponent(ComponentType &&value) 
//	{
//		m_map.insert(std::make_pair<int, ComponentType>(getTypeId<Key>(),std::forward<ComponentType>(value)));
//
//		//If an alias type has been supplied, store the component ref twice under both keys.
//		//As we are only ever storing component pointers we dont really care about the extra space this uses.
//		if (!std::is_same<Key,Alias>())
//			m_map.insert(std::make_pair<int, ComponentType>(getTypeId<Alias>(), std::forward<ComponentType>(value)));
//	}
//
//private:
//	template <class Key>
//	inline static int getTypeId() {
//		static const int id = LastTypeId++;
//		return id;
//	}
//
//	static int LastTypeId;
//	Map m_map;
//};
//template <class ComponentType>
//int ComponentMap<ComponentType>::LastTypeId(0);
