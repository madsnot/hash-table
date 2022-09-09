#pragma once
#include <iostream>
#include <map>
#include "dictionary.h"
#include "NotValidKey.h"

using namespace std;

template <class Key, class Value>
class HashTable : public dictionary<Key, Value> {
private:
	map<Key, Value> hashTableElements;

public:
	HashTable() {};

	~HashTable() {
		hashTableElements.clear();
	}

	const Value& get(const Key& key) const override {
		try {
			return hashTableElements.at(key);
		}
		catch (out_of_range& ex) {
			throw NotValidKey<Key>(key, "Unable to get value by key: ");
		}
	}

	void set(const Key& key, const Value& value) override {
		if (hashTableElements.find(key) != hashTableElements.end())
			throw NotValidKey<Key>(key, "Unable to add new value to existing key: "); 
		hashTableElements[key] = value;
	}

	bool is_set(const Key& key) const override {
		if (hashTableElements.find(key) == hashTableElements.end())
			return false;
		return true;
	}

};