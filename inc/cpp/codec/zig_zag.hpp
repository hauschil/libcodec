/*
 * zig_zag.hpp
 *
 *  Created on: 18.10.2013
 *      Author: hauschil
 */

#ifndef ZIG_ZAG_HPP_
#define ZIG_ZAG_HPP_

int zig_zag_encode(const int8_t in, uint8_t* out);
int zig_zag_encode(const int16_t in, uint16_t* out);
int zig_zag_encode(const int32_t in, uint32_t* out);
int zig_zag_encode(const int64_t in, uint64_t* out);


int zig_zag_decode(const uint8_t in, int8_t* out);
int zig_zag_decode(const uint16_t in, int16_t* out);
int zig_zag_decode(const uint32_t in, int32_t* out);
int zig_zag_decode(const uint64_t in, int64_t* out);
#endif /* ZIG_ZAG_HPP_ */
