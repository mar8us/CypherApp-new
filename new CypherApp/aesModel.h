#pragma once
#include "cryptoModel.h"


class AesModel : public CryptoModel
{
public:

	AesModel()
		{	}
	
	~AesModel()
		{	}

	bool encryptAes(const std::vector<unsigned char>& input);
	void setKeyLength(int keyLength);
	void generateKey();
	void generateIV();
	bool getCtx(EVP_CIPHER_CTX* ctx);
	void saveToFile(std::string filePath) override;
	void saveKey(std::string filePath);
	//void saveKey(std::string filePath);
	//void saveIV(std::string filePath);
	//void saveEncryptedText(std::string filePath);

	std::vector<unsigned char> getIV()
		{	return iv;	}

	std::vector<unsigned char> getKey()
		{	return key;	}

	std::vector<unsigned char> getCypher_Msg()
		{	return cypher_msg;	}

	
private:
	const EVP_CIPHER* cipher_mode;
	int key_size;
	std::vector<unsigned char> key;
	std::vector<unsigned char> iv;
	std::vector<unsigned char> cypher_msg;
};