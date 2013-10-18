/*
 * varfloat.hpp
 *
 *  Created on: 18.10.2013
 *      Author: hauschil
 */

#ifndef VARFLOAT_HPP_
#define VARFLOAT_HPP_

void decompose_double(double in, int16_t* m, uint32_t* e){
	/**
	 * param m: will contain: v* mantissa
	 * param e: will contain the exponent
	 * Z=(-1)^{VZ}\cdot(1{,}0+M/2^{52})\cdot 2^{E - 1023}
	 */
	uint8_t  sign = in >> 63;
	uint16_t mantissa = (in >> 52) & ((1<<11)-1) ;
	uint64_t exponent = in & ((1<<52)-1);
	*m = (sign==0)?(mantissa):(-mantissa);
	*e = exponent;
}
void compose_double(int16_t m, uint32_t e, double* out){
	uint8_t sign;
	uint16_t mantissa;
	uint64_t exponent;
	if (m>=0){
		sign = 0;
		mantissa = m;
	}
	else{
		sign = 1;
		mantissa = -m;
	}
	uint64_t* ptr = (uint64_t*)out;
	*ptr = (sign<<63) | e << 52 | m;
}




#endif /* VARFLOAT_HPP_ */
