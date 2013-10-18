#include <inttypes.h>

template< class TIN, class TOUT>
int __zig_zag_encode(const TIN in, TOUT* out) {
	static const int bytes = sizeof(TIN);
	static const int bits = (bytes<<3) -1; //no_bytes*8 -1
	*out = (in << 1) ^ (in >> bits);
	return (bytes);
}

template< class TIN, class TOUT>
int __zig_zag_decode(const TIN in, TOUT* out) {
	static const int bytes = sizeof(TIN);
	static const int bits = (bytes<<3) -1; //no_bytes*8 -1

	TIN tmp; //we need it to be unsigned
	TOUT sign;
	sign = in<<bits;
	tmp = in ^ (sign>>bits);
	tmp = (tmp>>1)|sign;
	*out = *(TOUT*)&tmp;
	return (bytes);
}



int zig_zag_encode(const int8_t in, uint8_t* out){ return __zig_zag_encode(in, out); }
int zig_zag_encode(const int16_t in, uint16_t* out){ return __zig_zag_encode(in, out); }
int zig_zag_encode(const int32_t in, uint32_t* out){ return __zig_zag_encode(in, out); }
int zig_zag_encode(const int64_t in, uint64_t* out){ return __zig_zag_encode(in, out); }



int zig_zag_decode(const uint8_t in, int8_t* out) { return __zig_zag_decode(in,out);}
int zig_zag_decode(const uint16_t in, int32_t* out){ return __zig_zag_decode(in,out);}
int zig_zag_decode(const uint32_t in, int32_t* out){ return __zig_zag_decode(in,out);}
int zig_zag_decode(const uint64_t in, int64_t* out){ return __zig_zag_decode(in,out);}
