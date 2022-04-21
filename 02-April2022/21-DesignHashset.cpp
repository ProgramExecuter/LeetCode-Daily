// Time Complexity => Add      - O(1)amortized
//                    Remove   - O(1)amortized
//                    Contains - O(1)
//
// Space Complexity - O(N), N => no. of unique elements

class MyHashSet {
private:
	int m_size, capacity;
	double load_factor;
	vector<list<int>> table;

	int hash(int key) {
		return key % capacity;                  // Hash the given number
	}

	list<int>::iterator search(int key) {       // Search the given 'key'
		int h = hash(key);                      // First find 'hash' of the 'key'
		return find(table[h].begin(), table[h].end(), key);
	}

	void rehash() {                             // Start hashing
	    m_size = 0;
		capacity = max(2, capacity);
		vector<list<int>> old_table(move(table));
		table = vector<list<int>>(capacity);    // Create new hash-table
		
		for( list<int>& chain: old_table )      // Copy old hash table new one
			for (int& key: chain)
				add(key);
	}

public:
	MyHashSet() : m_size(0), capacity(2), load_factor(0.75), table(capacity) {}
	
	void add(int key) {
		if(contains(key))                       // Key already exists, RETURN
			return;
		
		m_size++;                               // Increase size
		int h = hash(key);                      // Create hash for the key
		table[h].push_back(key);
		
		if(m_size  >=  load_factor*capacity) {  // Double the capacity, if filled
			capacity *= 2;
			rehash();
		}
	}
	
	void remove(int key) {              
		int h = hash(key);                          // Find the hash for key
		auto it = search(key);
		
		if(it == table[h].end())                    // Key not found
			return;
		
		m_size--;                                   // Key found, remove it
		table[h].erase(it);
		
		if(m_size  <=  0.5*load_factor*capacity) {  // Reduce the capacity, if empty
			capacity /= 2;
			rehash();
		}
	}
	
	bool contains(int key) {
		int h = hash(key);
		return search(key) != table[h].end();
	}
};