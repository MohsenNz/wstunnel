#include <stdlib.h>
#include <stdio.h>
#include "./wstunnel.h"
#include <string.h>
#include <unistd.h>
#include <signal.h>

int main(void) {
    signal(SIGPIPE, SIG_IGN); // to ignore broken pipe in c (it would be handle by wstunnel)

    // Start server
    printf("Starting server again on port 8585...\n");

    Handle *handle = run_wstunnel_nonblocking("server wss://[::]:8585");
    printf("it's print immediatly beacuase of non-blocking\n"); // \n is needed to ensure flush output
    printf("The server is up\n");
    printf("Address of handle: %p\n", (void *)handle);

    int r = is_wstunnel_running(handle);
    printf("running status: %i\n", r);

    char *error = check_wstunnel_error(handle);
    printf("possible error: %s\n", error);

    printf("Counting to 10...\n");
    sleep(10);


    // Stop server
    printf("Stoping the server...\n");

    stop_wstunnel(handle);
    printf("The server is down\n");

    printf("Counting to 10...\n");
    sleep(10);

    // Start server again
    printf("Starting server again on port 8686...\n");

    Handle *handle2 = run_wstunnel_nonblocking("server wss://[::]:8686");
    printf("The server is up\n");
    printf("Address of handle2: %p\n", (void *)handle2);

    printf("Counting to 10...\n");
    sleep(10);

    // Stop server
    printf("Stoping the server...\n");

    stop_wstunnel(handle2);
    printf("The server is down\n");

    return 0;
}
