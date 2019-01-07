#pragma once
class Bitset
{
private:
	vector<uint> data_;
	int size_;
public:
	Bitset();
	Bitset(uint n);
	~Bitset();
	void Resize(uint n);
	void Clear(bool val = false);
	void Set(uint index, bool val);
	bool Get(uint index);
	Bitset& operator=(const Bitset& copy);
	Bitset& operator|=(const Bitset& right);
};

