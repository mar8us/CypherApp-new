#pragma once

#include <string>
#include <vector>
#include <openssl/evp.h>
#include <openssl/provider.h>


class CryptoModel
{
public:

	CryptoModel() { }
    ~CryptoModel() { }
	//virtual void readFromFile(std::string filePath) = 0;
	virtual void saveToFile(std::string filePath) = 0;
};

class OpenSSLInitializer {
public:
    OpenSSLInitializer() {
        prov = OSSL_PROVIDER_load(NULL, "default");
        if (!prov) {
            // Handle error
        }
    }

    ~OpenSSLInitializer() {
        if (!OSSL_PROVIDER_unload(prov)) {
            ;
        }
    }

private:
    OSSL_PROVIDER* prov;
};