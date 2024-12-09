//
// Created by wenhao on 12/10/2024.
//
#include "multithreadframework.h"
char text[1024];
mln_u32_t msec = 2000;

static int global_init(void);

static void worker_process(mln_event_t *ev);

static void print_handler(mln_event_t *ev, void *data);

int multithreadframework_t(int argc, char *argv[]) {
    struct mln_framework_attr cattr;
    cattr.argc = argc;
    cattr.argv = argv;
    cattr.global_init = global_init;
    cattr.main_thread = NULL;
    cattr.master_process = NULL;
    cattr.worker_process = worker_process;
    return mln_framework_init(&cattr);
}

static int global_init(void) {
    //global variable init function
    int n = snprintf(text, sizeof(text) - 1, "hello world\n");
    text[n] = 0;
    return 0;
}

static void worker_process(mln_event_t *ev) {
    //we can set event handler here
    //let's set a timer
    mln_event_timer_set(ev, msec, text, print_handler);
}

static void print_handler(mln_event_t *ev, void *data) {
    mln_log(debug, "%s\n", (char *)data);
    mln_event_timer_set(ev, msec, data, print_handler);
}
