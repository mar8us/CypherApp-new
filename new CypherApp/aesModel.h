#pragma once
#include "cryptoModel.h"
#include "toolsToConvert.h"
#include <memory>

namespace qto
{

class AesModel : public CryptoModel
{
public:

	AesModel(int keyLength)
	{	
		setKeyLength(keyLength);
	}

	~AesModel()
	{	}

	const std::vector<unsigned char>& encryptAes(const std::vector<unsigned char>& input);
	void generateKey();
	void generateIV();
	void saveToFile(std::string filePath) override;
	void saveKey(std::string filePath);
	//void saveKey(std::string filePath);
	//void saveIV(std::string filePath);
	//void saveEncryptedText(std::string filePath);

	std::vector<unsigned char>& getIV()
	{
		return iv;
	}

	std::vector<unsigned char>& getKey()
	{
		return key;
	}

	void setKey(std::vector<unsigned char>& newKey)
	{
		key = newKey;
	}

	std::vector<unsigned char>& getCypher_Msg()
	{
		return cypher_msg;
	}

const EVP_CIPHER* cipher_mode;
private:
	void setKeyLength(int keyLength);

	int key_size;
	std::vector<unsigned char> key;
	std::vector<unsigned char> iv;
	std::vector<unsigned char> cypher_msg;
};

class BaseCtrl
{
public:
	BaseCtrl()
	{	}
	std::vector<unsigned char> readFromFile(System::String^ filePath);
};

class AesCtrl : public BaseCtrl
{
public:
	AesCtrl(int keyLength) : aes(std::make_unique<qto::AesModel>(keyLength))
	{	
		aes->generateKey();			
		aes->generateIV();
	}
	System::String^ encryptAes(System::String^ input);
	void saveToFile(std::string filePath);
	std::vector<unsigned char> keyFromTextBox(System::String^ key);
	std::unique_ptr<qto::AesModel> aes;
};
}