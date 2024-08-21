CC:=gcc

fopen_test: fopen_test.c
# gcc -o fopen_test fopen_test.c
	-$(CC) -o $@ $^
# ./fopen_test
	-./$@
# rm ./fopen_test
	-rm ./$@

fclose_test: fclose_test.c 
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

fputc_test: fputc_test.c 
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

fputs_test: fputs_test.c 
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

fprintf_test: fprintf_test.c 
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@