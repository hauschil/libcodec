/*
 *
 *  Created on: 18.10.2013
 *      Author: hauschil
 */
#include <limits.h>
#include <inttypes.h>
#include <assert.h>
#include <iostream>
#include "codec/zig_zag.hpp"

int unittest_zigzag() {
	using namespace std;
	int32_t val;
	uint32_t zig_zag_val;
	int32_t recovered;

	{
		for (val = -10000; val < 10000; val++) {
			zig_zag_encode(val,&zig_zag_val);
			zig_zag_decode(zig_zag_val, &recovered);
			//clog << val << " " << zig_zag_val << " " << recovered << endl;
			assert(val == recovered);
		}
	}
	return (0);
}
