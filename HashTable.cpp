#include <iostream>
#include "HashTableClass.h"
#include "NotValidKey.h"

using namespace std;

int main()
{
    HashTable<string, int> hashTable;
    try {
        hashTable.set("100", 500);
        hashTable.set("200", 900);
        if (hashTable.is_set("300"))
            cout << "Is set" << endl;
        else
            cout << "Is not set" << endl;
        cout << hashTable.get("200") << endl;
        hashTable.set("100", 1000);
    }
    catch (NotValidKey<string>& ex) {
        cout << ex.get_key() << endl;
    }
    catch (exception& ex) {
        cout << ex.what() << endl;
    }
    return 0;
}
