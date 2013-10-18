/* SLIP special character codes
 */
#define END             0xc0    /* indicates end of packet */
#define ESC             0xdb    /* indicates byte stuffing */
#define ESC_END         0xdc    /* ESC ESC_END means END data byte */
#define ESC_ESC         0xdd    /* ESC ESC_ESC means ESC data byte */

/* SEND_PACKET: sends a packet of length "len", starting at
 * location "p".
 */

int slip_encode(const char* in, int n, char* out) {
	int bytes_written = 0;
	const char* start_out = out;
	const char* start_in  = in;
	//const char* end_in	  = in+n;
	//write ends for starting the packet
	*out++ = END;
	//this is the real encoding
	for (const char* ptr = start_in; ptr < in + n; ptr++) {
		switch (*ptr) {
		case ESC:
			*out++ = ESC;
			*out++ = ESC_END;
			break;
		case END:
			*out++ = ESC;
			*out++ = ESC_ESC;
			break;
		default:
			*out++ = *ptr;
		}
	}

	*out++ = END; // write end for ending the packet
	bytes_written = out - start_out;
	return bytes_written;
}

int slip_decode(const char* in, int n, char* out) {
	int bytes_written = 0;
	const char* start_out = out;

	const char* start_in = in;
	const char* end_in = in + n;

	for (const char* ptr = start_in; ptr < end_in; ptr++) {
		switch (*ptr) {
		case ESC:
			ptr++;  //advance pointer
			switch (*ptr) {
			case ESC_END:
				*out++ = END;
				break;
			case ESC_ESC:
				*out++ = ESC;
				break;
			}
			break;
		case END:
			bytes_written = out - start_out;
			if (bytes_written > 0) // so its the start of the stream
				return bytes_written;
			break;
		default:
			*out++ = *ptr;
		}
	}
	return (-1); //we come here if no packet could be decoded and input buffer ended

}
