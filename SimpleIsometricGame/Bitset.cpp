#include "stdafx.h"
#include "Bitset.h"

Bitset::Bitset()
{
}

Bitset::Bitset(uint n)
{
	size_ = n;
	data_.resize((size_ - 1) / (sizeof(uint) * 8) + 1, 0);
}

Bitset::~Bitset()
{
}

void Bitset::Resize(uint n)
{
	size_ = n;
	data_.resize((n - 1) / (sizeof(uint) * 8) + 1, 0);
}

void Bitset::Clear(bool val)
{
	if (!val)
	{
		fill(data_.begin(), data_.end(), 0);
	}
	else
	{
		fill(data_.begin(), data_.end(), ~0);
	}
}

void Bitset::Set(int index)
{
	if (index >= 0 && index < size_)
	{
		int bit_pos = 1 << (index % (sizeof(uint) * 8));
		data_[index / (sizeof(uint) * 8)] |= bit_pos;
	}
}

bool Bitset::Get(int index)
{
	if (index >= 0 && index < size_)
	{
		int bit_pos = 1 << (index % (sizeof(uint) * 8));
		return (bit_pos & data_[index / (sizeof(uint) * 8)]);
	}
	return false;
}

Bitset & Bitset::operator|=(const Bitset & right)
{
	if (right.size_ == size_)
	{
		for (int i = 0; i < data_.size(); i++)
		{
			data_[i] |= right.data_[i];
		}
	}
	return *this;
}
