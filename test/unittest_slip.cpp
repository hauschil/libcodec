/*
 * unittest_slip.cpp
 *
 *  Created on: 18.10.2013
 *      Author: hauschil
 */
#include <limits.h>
#include <inttypes.h>
#include <assert.h>
#include <iostream>
#include "codec/slip.hpp"
#include <string>

#define STRINGIFY(str) #str
#define LOG(str) std::clog << STRINGIFY(str) << ": " << str << std::endl;
int unittest_slip() {
	const char* data = "Hello World, My name is Somebody";
	int bytes_data = strlen(data);
	char encoded[200];
	char decoded[200];
	{
		int bytes_written = slip_encode(data, bytes_data, encoded);
		int bytes_read = slip_decode(encoded, bytes_written, decoded);
		/*
		 LOG(data);
		 LOG(decoded);
		 LOG(bytes_data);
		 LOG(bytes_read);
		 LOG(bytes_written);

		 */
	}
	return (0);
}
