#include "framework.h"

int framework_t(int argc, char *argv[])
{
    printf("NOTE: This test has memory leak because we don't release memory of log, conf and multiprocess-related stuffs.\n");
    printf("In fact, `mln_framework_init` should be the last function called in `main`, so we don't need to release anything.\n");

    struct mln_framework_attr cattr;
    cattr.argc = argc;
    cattr.argv = argv;
    cattr.global_init = NULL;
    cattr.main_thread = NULL;
    cattr.master_process = NULL;
    cattr.worker_process = NULL;
    return mln_framework_init(&cattr);
}
