/*
 * integration_test.cpp
 *
 *  Created on: 18.10.2013
 *      Author: hauschil
 */

#include <inttypes.h>
#include <assert.h>
#include "codec/zig_zag.hpp"
#include "codec/slip.hpp"
#include "codec/varint.hpp"

#define STRINGIFY(str) #str
#include <iostream>
#define LOG(str) std::clog << STRINGIFY(str) << ": " << str << std::endl;

struct TestStruct {
	uint64_t var_0;
	int32_t var_1;
};

int integrationtest(int argc, const char* argv) {
	char enc_buffer[2][100];
	char dec_buffer[2][100];
	TestStruct test;
	TestStruct test_dec;
	test.var_0 = 1024;
	test.var_1 = -2048;
	//int struct_usage = sizeof(TestStruct);

	/**
	 * Suppose we want to sent this data... then we will first zigzag encode var_1
	 */
	{
		/*
		 LOG(test.var_0);
		 LOG(test.var_1);
		 */
		char* vl_buf_ptr = enc_buffer[0];
		int vl_buf_usage = 0;

		char* slip_buf_ptr = enc_buffer[1];
		int slip_buf_usage = 0;
		vl_buf_usage += varint_encode(test.var_0, vl_buf_ptr + vl_buf_usage);
		uint32_t tmp_0;
		zig_zag_encode(test.var_1, &tmp_0);
		vl_buf_usage += varint_encode(tmp_0, vl_buf_ptr + vl_buf_usage);
		slip_buf_usage += slip_encode(vl_buf_ptr, vl_buf_usage, slip_buf_ptr);
		/*
		 LOG(struct_usage);
		 LOG(vl_buf_usage);
		 LOG(slip_buf_usage);
		 */
		/**
		 * Decode phase
		 */
		char *slip_dec_buf_ptr = dec_buffer[1];
		int slip_dec_buf_usage = 0;
		int vl_dec_buf_usage = 0;
		slip_dec_buf_usage += slip_decode(slip_buf_ptr + slip_dec_buf_usage,
				slip_buf_usage, slip_dec_buf_ptr);
		vl_dec_buf_usage += varint_decode(slip_dec_buf_ptr, &test_dec.var_0);
		uint64_t tmp = 0;
		vl_dec_buf_usage += varint_decode(slip_dec_buf_ptr + vl_dec_buf_usage,
				&tmp);
		zig_zag_decode(tmp, &test_dec.var_1);
		/*
		 LOG(vl_dec_buf_usage);
		 LOG(slip_dec_buf_usage);
		 LOG(test_dec.var_0);
		 LOG(test_dec.var_1);
		 */
		assert(test_dec.var_0 == test.var_0);
		assert(test_dec.var_1 == test.var_1);
	}

	return (0);
}
