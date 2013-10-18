#include <inttypes.h>

template<class TIN>
int __varint_encode(TIN in, char* out) {
	//encode least significant group first....
	uint8_t bytes_written = 0;
	uint8_t byte;
	for (;;) {
		byte = in & 0x7F;
		in >>= 7;
		byte |= (in == 0) ? (0x80) : (0x00);
		*out++ = byte;
		bytes_written++;
		if (in == 0)
			return bytes_written;
	}
	return (0);
}

template<class TOUT>
int __varint_decode(const char* in, TOUT* out) {
	//encode least significant group first....
	uint8_t bytes_read;
	uint8_t data_bits;
	uint8_t byte;
	uint8_t shift;
	bytes_read = 0;
	shift = 0;
	*out = 0;
	for (;;) {
		byte = *in++;
		bytes_read++;
		data_bits = byte & 0x7F;
		*out |= (data_bits << shift);
		if ((byte & 0x80) != 0) {
			return bytes_read;
		}
		shift += 7;
	}
	return (0);
}

int varint_encode(uint8_t in, char* out) {
	return __varint_encode(in, out);
}
int varint_encode(uint16_t in, char* out) {
	return __varint_encode(in, out);
}
int varint_encode(uint32_t in, char* out) {
	return __varint_encode(in, out);
}
int varint_encode(uint64_t in, char* out) {
	return __varint_encode(in, out);
}

int varint_decode(const char* in, uint8_t* out) {
	return __varint_decode(in, out);
}
int varint_decode(const char* in, uint16_t* out) {
	return __varint_decode(in, out);
}
int varint_decode(const char* in, uint32_t* out) {
	return __varint_decode(in, out);
}
int varint_decode(const char* in, uint64_t* out) {
	return __varint_decode(in, out);
}
