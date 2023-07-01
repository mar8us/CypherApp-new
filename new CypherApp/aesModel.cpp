#include "aesModel.h"
#include <openssl/rand.h>


bool AesModel::encryptAes(const std::vector<unsigned char>& input)
{
	std::vector<unsigned char> iv = generateIV();
    return true;
}

void AesModel::setKeyLength(int keyLenght)
{
    switch (keyLenght) 
    {
        case 128:
            cipher_mode = EVP_aes_128_cbc();
            break;
        case 192:
            cipher_mode = EVP_aes_192_cbc();
            break;
        case 256:
            cipher_mode = EVP_aes_256_cbc();
            break;
        default:
            break;
    }
    key_size = EVP_CIPHER_key_length(cipher_mode);
}

std::vector<unsigned char> AesModel::generateKey() 
{
    std::vector<unsigned char> key(key_size);
    RAND_bytes(key.data(), key.size());
    return key;
}

std::vector<unsigned char> AesModel::generateIV() 
{
    size_t size = EVP_CIPHER_iv_length(cipher_mode);
    std::vector<unsigned char> iv(size);
    RAND_bytes(iv.data(), size);
    return iv;
}