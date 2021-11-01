#include "Map.h"

Map::Map() {
	head = nullptr;
}
	// Create an empty map (i.e., one with no key/value pairs)
Map::~Map() {
	for (node * n = head;n != nullptr;) {
		node * temp = n;
		n = n->next;
		delete temp;
	}
}
Map::Map(const Map& m) {
	*this = m;
}
bool Map::empty() const {
	return size() < 0;
}
	// Return true if the map is empty, otherwise false.
Map& Map::operator=(const Map& m) {
	
	for (node * n = head;n != nullptr;) {
		node * temp = n;
		n = n->next;
		delete temp;
	}
	head = nullptr;
	for (node * n = m.head;n != nullptr;n = n->next) {
		insert(n->key, n->value);
	}
	return *this;
}
int Map::size() const {
	int count = 0;
	for (node * n = head;n != nullptr;n = n->next) {
		count++;
	}
	return count;
}
	// Return the number of key/value pairs in the map.

bool Map::insert(const KeyType& key, const ValueType& value) {
	if (!contains(key)) {
		node * n = new node;
		n->key = key;
		n->value = value;
		n->next = head;
		head = n;
		return true;
	}
	return false;
}
// If key is not equal to any key currently in the map, and if the
// key/value pair can be added to the map, then do so and return true.
// Otherwise, make no change to the map and return false (indicating
// that either the key is already in the map).

bool Map::update(const KeyType& key, const ValueType& value) {
	for (node * n = head;n != nullptr;n = n->next) {
		if (n->key == key) {
			n->value = value;
			return true;
		}
	}
	return false;
}
// If key is equal to a key currently in the map, then make that key no
// longer map to the value it currently maps to, but instead map to
// the value of the second parameter; return true in this case.
// Otherwise, make no change to the map and return false.

bool Map::insertOrUpdate(const KeyType& key, const ValueType& value) {
	if (!update(key, value)) {
		return insert(key, value);
	}
	return true;
}
// If key is equal to a key currently in the map, then make that key no
// longer map to the value it currently maps to, but instead map to
// the value of the second parameter; return true in this case.
// If key is not equal to any key currently in the map then add it and 
// return true. In fact this function always returns true.

bool Map::erase(const KeyType& key) {
	if (head != nullptr){
	for (node * n = head;n->next != nullptr;n = n->next) {
		if (n->next->key == key) {
			node * temp = n->next;
			n->next = n->next->next;
			delete temp;
			return true;
		}
	}
	}
	return false;
}
// If key is equal to a key currently in the map, remove the key/value
// pair with that key from the map and return true. Otherwise, make
// no change to the map and return false.

bool Map::contains(const KeyType& key) const {
	for (node * n = head;n != nullptr;n = n->next) {
		if (n->key == key) {
			return true;
		}
	}
	return false;
}
// Return true if key is equal to a key currently in the map, otherwise
// false.

bool Map::get(const KeyType& key, ValueType& value) const {
	for (node * n = head;n != nullptr;n = n->next) {
		if (n->key == key) {
			value = n->value;
			return true;
		}
	}
	return false;
}
// If key is equal to a key currently in the map, set value to the
// value in the map that that key maps to, and return true.  Otherwise,
// make no change to the value parameter of this function and return
// false.
bool Map::get(int i, KeyType& key, ValueType& value) const {
	if (0 <= i && i < size()) {
		
		node * n = head;
		for (int j = 0; j <= i; n = n->next, j++) {
			if (n != nullptr) {
				if (j == i) {
					key = n->key;
					value = n->value;
					return true;
				}
			}
		}
	}
	return false;
}
// If 0 <= i < size(), copy into the key and value parameters the
// key and value of one of the key/value pairs in the map and return
// true.  Otherwise, leave the key and value parameters unchanged and
// return false.  (See below for details about this function.)
bool Map::combine(const Map& m1, const Map& m2, Map& result) {
	//adding m1 to result 
	for (node * n = m1.head;n != nullptr;n = n->next) {
		if (!result.contains(n->key)) {
			result.insert(n->key, n->value);
		}
		else {
			ValueType value;
			result.get(n->key, value);
			if (value != n->value) {
				result.erase(n->key);
				return false;
			}
		}
	}
	//adding m2 to result 
	for (node * n = m1.head;n != nullptr;n = n->next) {
		if (!result.contains(n->key)) {
			result.insert(n->key, n->value);
		}
		else {
			ValueType value;
			result.get(n->key, value);
			if (value != n->value) {
				result.erase(n->key);
				return false;
			}
		}
	}
	return true;
}
//return false if key is sane in the result map but with a different value, 
void Map::subtract(const Map& m1, const Map& m2, Map& result) {
	Map temp;
	for (node * n = m1.head;n != nullptr;n = n->next) {
		bool f = true;
		for (node * b = m2.head;b != nullptr;b = b->next) {
			if (b->key == n->key) f = false;
		}
		if (f) {
			temp.insert(n->key, n->value);
		}
	}
	result = temp;
	return;
}

void Map::swap(Map& other) {
	Map temp = other;
	other = *this;
	*this = temp;
}