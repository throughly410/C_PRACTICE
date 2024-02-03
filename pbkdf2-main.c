#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int main(void){
    puts("pbkdf2-main");

    const char password[] = "password";       // 文字密碼
	unsigned char salt[] = {'s','a','l','t'}; // Salt
	const int KEY_LEN = 20;                   // 輸出密鑰長度
	unsigned char key[KEY_LEN];               // 輸出的密鑰
	int iter = 2;                             // 迭代次數

    // 以 OpenSSL 計算 PBKDF2-HMAC-SHA1
	PKCS5_PBKDF2_HMAC_SHA1(
			password,           // 文字密碼（輸入）
			strlen(password),   // 文字密碼長度（輸入）
			salt,               // Salt（輸入）
			sizeof(salt),       // Salt 長度（輸入）
			iter,               // 迭代次數
			KEY_LEN,            // 密鑰長度（輸出）
			key);               // 密鑰（輸出）

	// 輸出 PBKDF2-HMAC-SHA1 計算結果
	BIO_dump_fp(stdout, key, KEY_LEN);
}

