#pragma once
#include "cryptoModel.h"


class AesModel : public CryptoModel
{
public:
	bool encryptAes(const std::vector<unsigned char>& input);
	void setKeyLength(int keyLength);
	std::vector<unsigned char> generateKey();
	std::vector<unsigned char> generateIV();
	void saveToFile(std::string filePath) override;
	//void saveKey(std::string filePath);
	//void saveIV(std::string filePath);
	//void saveEncryptedText(std::string filePath);

private:
	const EVP_CIPHER* cipher_mode;// = nullptr;
	int key_size;
};