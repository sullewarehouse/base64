
//
// example.cpp
// 
// Author:
//     Brian Sullender
//     SULLE WAREHOUSE LLC
// 
// Description:
//     The example program for using base64
//

#include <iostream>
#include "base64.h"

int main()
{
	char* out;
	char* in = "Some text 1234";
	size_t inlen = strlen(in);

	printf("Data: %s\n", in);

	// Encode the data
	size_t outlen = base64_encode_alloc(in, inlen, &out);
	if (outlen == 0) {
		printf("%s", "Encode error: input too long");
		return -1;
	}
	if (out == NULL) {
		printf("%s", "Encode error: memory allocation error");
		return -1;
	}

	// Note: out is zero terminated
	printf("Encoded: %s\n", out);

	// Our input will be the previous output

	in = out;
	inlen = outlen;

	// Decode the data
	bool ok = base64_decode_alloc(in, inlen, &out, &outlen);
	if (!ok) {
		printf("%s", "Decode error: input was not valid base64");
		return -1;
	}
	if (out == NULL) {
		printf("%s", "Decode error: memory allocation error");
		return -1;
	}

	// Note: out is NOT zero terminated!
	printf("Decoded: %.*s\n", (int)outlen, out);

	// Free resources
	free(out);
	free(in);

	// Exit
	return 0;
}
