#pragma once
#include <iostream>
#include <string>
#include "not_found_exception.h"

using namespace std;

template <class Key>
class NotValidKey : public not_found_exception<Key> {
private:
	Key errorKey;
	string errorMsg;
public:
	NotValidKey(Key key, string msg) {
		errorKey = key;
		errorMsg = msg;
	}
	const Key& get_key() const noexcept {
		cout << errorMsg;
		return errorKey;
	}
};