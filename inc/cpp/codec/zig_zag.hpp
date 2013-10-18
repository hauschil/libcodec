/*
 * zig_zag.hpp
 *
 *  Created on: 18.10.2013
 *      Author: hauschil
 */

#ifndef ZIG_ZAG_HPP_
#define ZIG_ZAG_HPP_

uint64_t zig_zag_encode(const int64_t in);
int64_t zig_zag_decode(const uint64_t in);
#endif /* ZIG_ZAG_HPP_ */
