#include "aesModel.h"
#include <openssl/rand.h>
#include <fstream>
#include <iostream>


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
    key.resize(key_size);
}

void AesModel::generateKey() 
{
    RAND_bytes(key.data(), key.size());
}

void AesModel::generateIV() 
{
    size_t size = EVP_CIPHER_iv_length(cipher_mode);
    iv.resize(size);
    RAND_bytes(iv.data(), size);
}

bool AesModel::encryptAes(const std::vector<unsigned char>& input)
{
    if (key.empty() || iv.empty())
        return false;

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!(ctx))
        return false;

    if (EVP_EncryptInit_ex(ctx, cipher_mode, nullptr, key.data(), iv.data()) != 1) 
    {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    std::vector<unsigned char> output(input.size() + EVP_CIPHER_CTX_block_size(ctx));
    int out_len = 0;

    if (EVP_EncryptUpdate(ctx, output.data(), &out_len, input.data(), input.size()) != 1) 
    {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }
    int final_len = 0;

    if (EVP_EncryptFinal_ex(ctx, output.data() + out_len, &final_len) != 1) 
    {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }
    output.resize(out_len + final_len);
    EVP_CIPHER_CTX_free(ctx);

    cypher_msg.clear();
    cypher_msg.insert(cypher_msg.end(), output.begin(), output.end());
    return true;
}

void AesModel::saveToFile(std::string filePath)
{
    std::ofstream out(filePath, std::ios::binary);
    if (!out)
        out.write(reinterpret_cast<const char*>(iv.data()), iv.size()); // Zapisz IV przed zaszyfrowanymi danymi
    out.write(reinterpret_cast<const char*>(cypher_msg.data()), cypher_msg.size());
    out.close();
}
