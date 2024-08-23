CC:=gcc

system_test: system_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

fork_test: fork_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

fork_fd_test: fork_fd_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

EXE:=test_ex
execve_test: execve_test.c
	- gcc -o $(EXE) $(EXE).c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@ $(EXE)