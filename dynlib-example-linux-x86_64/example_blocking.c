#include <stdlib.h>
#include <stdio.h>
#include "./wstunnel.h"
#include <string.h>
#include <unistd.h>
#include <signal.h>

int main(void) {
    signal(SIGPIPE, SIG_IGN); // to ignore broken pipe in c (it would be handle by wstunnel)
 
    // You will responsible to create thread and stop it by your self
    run_wstunnel_blocking("server wss://[::]:8585");

    printf("it will not print beacuase of blocking\n");
 
    return 0;
}
