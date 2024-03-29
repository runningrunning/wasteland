// get familiar with CPP CODE
// can not call parents' funcion in subclass's constructor !!!!!!
// or just Iterator(*this).next(); in peek

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
    bool has_peek;
    int v_peek;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        has_peek = false;
        // can not call Iterator::next or Iterator::hasNext here.
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {

        if (!has_peek)
        {
            has_peek = true;
            v_peek = Iterator::next();
        }

        return v_peek;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if (!has_peek)
            return Iterator::next();

        has_peek = false;
        return v_peek;
	}

	bool hasNext() const {
        return has_peek || Iterator::hasNext();
	}
};
