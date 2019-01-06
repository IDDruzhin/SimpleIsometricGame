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
	void Set(int index);
	bool Get(int index);
	//Bitset& operator=(const Bitset& copy);
	Bitset& operator|=(const Bitset& right);
};

