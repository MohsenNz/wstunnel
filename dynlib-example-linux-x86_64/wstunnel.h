#ifndef SOMELIBNAME
#define SOMELIBNAME

#include <stdint.h>

// Opaque type for Handle
typedef struct _handle_opaque_type Handle;

void run_wstunnel_blocking( char *s );
Handle *run_wstunnel_nonblocking( char *s );
void stop_wstunnel( Handle *h );

#endif
