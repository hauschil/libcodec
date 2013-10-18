#include <inttypes.h>

template<int bits_per_byte>
int base_encode(const char* in, int n, char* out, int m) {
	static const int bpb = bits_per_byte;
	static const int mask = ((1 << bpb) - 1);

}

template<int bits_per_byte>
int base_decode(const char* in, int n, char* out, int m) {
	/**
	 * varint encoding is a special case of base128 encoding

	 * each byte only stores 7 instead of 8 bytes, such that for m bytes we require at most
	 * we want to decode at most m bytes, so read the string
	 * Returns: Bytes read from input stream; We also might need the bytes written to the output stream?!
	 */
	static const int bpb = bits_per_byte;
	static const int mask = ((1 << bpb) - 1);

	uint8_t bytes_read;
	uint8_t data_bits;
	uint8_t byte;
	uint8_t shift;
	uint8_t out_rem, out_pos;
	bytes_read = 0;
	shift = 0;
	*out = 0;
	for (;;) {
		byte = *in++; //read in bytes
		bytes_read++;
		//determine read position
		data_bits = byte & mask; //mask relevant bits
		out_rem = (shift & 0x07); //start in the pack of 8 bits %8 := &
		out_pos = (shift >> 0x03); //number of bytes to start /8 := >>3
		out[out_pos] |= (data_bits << out_rem);
		out[out_pos + 1] = (out_rem > 0) ? (data_bits >> (8 - out_rem)) : (0);
		if ((byte & 0x80) != 0) {
			return bytes_read;
		}
		shift += bpb;
	}
	return (-1);
}

int base_64_decode(const char* in, int n, char* out, int m) {
	return base_decode<7>(in, n, out, m);
}

int base_128_decode(const char* in, int n, char* out, int m) {
	return base_decode<7>(in, n, out, m);
}
