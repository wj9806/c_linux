CC:=gcc

thread_create_test: thread_create_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

terminate_test: terminate_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

thread_detach_test: thread_detach_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

thread_cancel_test: thread_cancel_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

thread_cancel_async_test: thread_cancel_async_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

thread_cancel_disable_test: thread_cancel_disable_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

race_condition_test: race_condition_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

mutex_test: mutex_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

rwlock_test: rwlock_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

condition_test: condition_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

unamed_sem_thread: unamed_sem_thread.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

unamed_sem_process: unamed_sem_process.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@


unamed_sem_count_thread: unamed_sem_count_thread.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

unamed_sem_count_process: unamed_sem_count_process.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

named_sem_thread: named_sem_thread.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

named_sem_count_process: named_sem_count_process.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

thread_pool_test: thread_pool_test.c
	-$(CC) -o $@ $^ `pkg-config --cflags --libs glib-2.0`
	-./$@
	-rm ./$@