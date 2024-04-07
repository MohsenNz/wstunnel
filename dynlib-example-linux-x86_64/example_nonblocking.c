#include <stdlib.h>
#include <stdio.h>
#include "./wstunnel.h"
#include <string.h>
#include <unistd.h>
#include <signal.h>

int main(void) {
    signal(SIGPIPE, SIG_IGN); // to ignore broken pipe in c (it would be handle by wstunnel)

    // Start server
    Handle *handle = run_wstunnel_nonblocking("server wss://[::]:8585");

    printf("it's print immediatly beacuase of non-blocking\n"); // \n is needed to ensure flush output
    printf("The server is up\n");
    printf("Address of handle: %p\n", (void *)handle);
    printf("Counting to 10...\n");
    sleep(10);
    printf("Stoping the server...\n");

    // Stop server
    stop_wstunnel(handle);

    printf("The server is down\n");
    printf("Counting to 10...\n");
    sleep(10);

    return 0;
}
