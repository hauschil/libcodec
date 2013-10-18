#include <inttypes.h>
uint64_t zig_zag_encode(const int64_t in) {
	/**
	 * Example:
	 (-1 << 1) ^ (-1 >> 7) = 11111110 ^ 11111111
	 = 00000001
	 */
	return (in << 1) ^ (in >> 63);
}

int64_t zig_zag_decode(const uint64_t in) {
	uint64_t out;
	int64_t sign;
	sign = in<<63;
	out = in ^ (sign>>63);
	out = (out>>1)|sign;
	return *(int64_t*)&out;
}
