/*
To encrypt data using OpenSSL, you typically follow these steps:

Generate a Key and Initialization Vector (IV): First, you need to generate a key and an initialization vector (IV). 
The key should be a secure random value, and the IV is used to ensure that 
each encrypted message produces different ciphertext even 
if the same message is encrypted multiple times with the same key.

Encrypt the Data: Once you have the key and IV, you can use them to encrypt your data. 
OpenSSL provides functions for symmetric encryption algorithms like AES. You specify the key, IV, 
and plaintext data to the encryption function, and it produces ciphertext.

Store the Encrypted Data: The ciphertext produced by the encryption function can be stored or transmitted securely.

Here's a basic example in C++ using OpenSSL's EVP interface for AES encryption:

This code generates a random 256-bit key and a 128-bit IV, encrypts the plaintext "Hello, World!"
using AES-256 in CBC mode, and prints the resulting ciphertext in hexadecimal format.

*/


#include <openssl/evp.h>
#include <openssl/rand.h>
#include <iostream>
#include <string>
#include <vector>

// Function to generate a secure random key and IV
void generateKeyAndIV(std::vector<unsigned char>& key, std::vector<unsigned char>& iv) {
    key.resize(32); // AES-256 key size
    iv.resize(16);  // IV size for AES
    RAND_bytes(key.data(), key.size());
    RAND_bytes(iv.data(), iv.size());
}

// Function to encrypt data using AES
std::vector<unsigned char> encryptData(const std::vector<unsigned char>& key, 
                                        const std::vector<unsigned char>& iv, 
                                        const std::string& plaintext) 
{
    std::vector<unsigned char> ciphertext(plaintext.size() + EVP_MAX_BLOCK_LENGTH);
    int ciphertextLen;

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, key.data(), iv.data());
    EVP_EncryptUpdate(ctx, ciphertext.data(), &ciphertextLen, reinterpret_cast<const unsigned char*>(plaintext.data()), plaintext.size());
    EVP_EncryptFinal_ex(ctx, ciphertext.data() + ciphertextLen, &ciphertextLen);
    EVP_CIPHER_CTX_free(ctx);

    ciphertext.resize(ciphertextLen);
    return ciphertext;
}

int main() {
    // Generate a random key and IV
    std::vector<unsigned char> key, iv;
    generateKeyAndIV(key, iv);

    // Plaintext data to encrypt
    std::string plaintext = "Hello, World!";

    // Encrypt the data
    std::vector<unsigned char> ciphertext = encryptData(key, iv, plaintext);

    // Print the ciphertext (in hexadecimal format)
    std::cout << "Ciphertext: ";
    for (unsigned char c : ciphertext) {
        std::cout << std::hex << static_cast<int>(c);
    }
    std::cout << std::endl;

    return 0;
}
