#pragma once
int varint_decode(const char* in, uint8_t* out);
int varint_decode(const char* in, uint16_t* out);
int varint_decode(const char* in, uint32_t* out);
int varint_decode(const char* in, uint64_t* out);

int varint_encode(uint8_t in, char* out);
int varint_encode(uint16_t in, char* out);
int varint_encode(uint32_t in, char* out);
int varint_encode(uint64_t in, char* out);


