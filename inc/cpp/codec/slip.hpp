/*
 * slip.hpp
 *
 *  Created on: 17.10.2013
 *      Author: hauschil
 */
#pragma once
#ifndef SLIP_HPP_
#define SLIP_HPP_
int slip_encode(const char* in, int n, char* out);
int slip_decode(const char* in, int n, char* out);
#endif /* SLIP_HPP_ */
