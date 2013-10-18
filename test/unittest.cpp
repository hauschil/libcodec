extern int  unittest_slip();
extern int unittest_zigzag();
extern int unittest_varint();
int main(int argc, char* args) {
	unittest_zigzag();
	unittest_varint();
	unittest_slip();
	return (0);
}
