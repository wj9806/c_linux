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

waitpid_test: waitpid_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

process_test: process_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

unamed_pipe_test: unamed_pipe_test.c
	-$(CC) -o $@ $^
	-./$@ helloPipe
	-rm ./$@

	
fifo_read: fifo_read.c
	-$(CC) -o $@ $^

fifo_write: fifo_write.c
	-$(CC) -o $@ $^