extern int unittest(int, const char*);
extern int integrationtest(int, const char*);

int main(int argc, const char* argv){
	unittest(argc, argv);
	integrationtest(argc, argv);
}
