/*
 *
 *  Created on: 18.10.2013
 *      Author: hauschil
 */
#include <limits.h>
#include <inttypes.h>
#include <assert.h>
#include <iostream>
#include "codec/varint.hpp"

int unittest_varint() {
	using namespace std;
	uint64_t val;
	char encoded[5];
	uint64_t decoded;
	uint16_t bytes_written = 0;
	{
		for (val = 0; val < 10000; val++) {
			varint_encode(val,encoded);
			bytes_written = varint_decode(encoded,&decoded);
			//clog << val << "->" << encoded << "->" << decoded << " "<< bytes_written << endl;
			assert(val == decoded);
		}
	}

	return (0);

}
