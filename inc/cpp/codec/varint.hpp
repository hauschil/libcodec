#pragma once

uint8_t varint_decode(const char* in, uint64_t* out);
uint8_t varint_encode(uint64_t in, char* out);
