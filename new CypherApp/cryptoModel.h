#pragma once

class CryptoModel
{
public:

	CryptoModel() { };
	~CryptoModel() { };
	virtual void saveToFile() = 0;
};