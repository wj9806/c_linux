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

shared_memory: shared_memory.c
	-$(CC) -o $@ $^
	-./$@ helloPipe
	-rm ./$@

father_son_mq_test: father_son_mq_test.c
	-$(CC) -o $@ $^
	-./$@ helloPipe
	-rm ./$@

signal_test: signal_test.c
	-$(CC) -o $@ $^
	-./$@ helloPipe
	-rm ./$@