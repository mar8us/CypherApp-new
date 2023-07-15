#include "aesModel.h"
#include <openssl/rand.h>
#include <fstream>
#include <iostream>

namespace qto
{


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

const std::vector<unsigned char>& AesModel::encryptAes(const std::vector<unsigned char>& input)
{
    if (key.empty() || iv.empty())
        return std::vector<unsigned char>();

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!(ctx))
        return std::vector<unsigned char>();
        //return false;

    if (EVP_EncryptInit_ex(ctx, cipher_mode, nullptr, key.data(), iv.data()) != 1)
    {
        EVP_CIPHER_CTX_free(ctx);
        return std::vector<unsigned char>();
        //return false;
    }

    std::vector<unsigned char> output(input.size() + EVP_CIPHER_CTX_block_size(ctx));
    int out_len = 0;

    if (EVP_EncryptUpdate(ctx, output.data(), &out_len, input.data(), input.size()) != 1)
    {
        EVP_CIPHER_CTX_free(ctx);
        return std::vector<unsigned char>();
        //return false;
    }
    int final_len = 0;

    if (EVP_EncryptFinal_ex(ctx, output.data() + out_len, &final_len) != 1)
    {
        EVP_CIPHER_CTX_free(ctx);
        return std::vector<unsigned char>();
        //return false;
    }
    output.resize(out_len + final_len);
    EVP_CIPHER_CTX_free(ctx);

    cypher_msg.clear();
    cypher_msg.insert(cypher_msg.end(), output.begin(), output.end());
    return cypher_msg;
    //return true;
}

void AesModel::saveToFile(std::string filePath)
{
    std::ofstream out(filePath, std::ios::binary);
    if (!out)
        return;
    out.write(reinterpret_cast<const char*>(iv.data()), iv.size()); // Zapisz IV przed zaszyfrowanymi danymi
    out.write(reinterpret_cast<const char*>(cypher_msg.data()), cypher_msg.size());
    out.close();
}


std::vector<unsigned char> BaseCtrl::readFromFile(System::String^ filePath)
{
    std::string file_path = tools::systemStringToString(filePath);
    std::ifstream input_stream(file_path, std::ios::binary);
    std::vector<unsigned char> input_data((std::istreambuf_iterator<char>(input_stream)), std::istreambuf_iterator<char>());
    input_stream.close();
    return input_data;
}

System::String^ AesCtrl::encryptAes(System::String^ input)
{
    const std::vector<unsigned char> intput = tools::convert_SystemString_to_vector(input);
    const std::vector<unsigned char> encryptedData = aes->encryptAes(intput);
    return tools::convert_Bytes_To_HexString(encryptedData);
}

void AesCtrl::saveToFile(std::string filePath)
{
    aes->saveToFile(filePath);
}

std::vector<unsigned char> AesCtrl::keyFromTextBox(System::String^ key)
{
    std::vector<unsigned char> keyData = tools::convert_SystemString_to_vector(key);    
    return keyData;
}

}// end__namespace qto