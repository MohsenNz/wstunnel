# API

Wstunnel dynamic lib expose three functions:

```c
// It will start wstunnel and blocked on it
// You will responsible to create thread and stop it by yourself
void run_wstunnel_blocking( char *s );

// It will start wstunnel in a non-blocking way
// then you can stop the server with `stop_wstunnel()`
// by passing Handle back to it
Handle *run_wstunnel_nonblocking( char *s );

void stop_wstunnel( Handle *h );
```

You can pass all CLI arguments as `char *s` e.g:

```c
run_wstunnel_blocking("client --http-upgrade-path-prefix wstunnel -L udp://127.0.0.1:51820:127.0.0.1:51820 wss://85.239.61.247");
```

## Opaque type

We need to define opaque types to get RtHandle Type that comes from Rust.
See [here](https://en.wikipedia.org/wiki/Opaque_data_type) for more information about opaque types. 

E.g In Dart you can use [this](https://api.dart.dev/dart-ffi/Opaque-class.html).

Here it's our opaque type definition in C:

```c
typedef struct _handle_opaque_type Handle;
```

# Build project

```bash
cargo build
```

# Check .so file

```bash
ls target/debug/*.so 
```

Output should be: `libwstunnel.so`

# Compile example.c

```bash
cd dynlib-example-linux-x86_64
```

Compile blocking example:

```bash
gcc -Wall -g -O0 example_blocking.c -o example_blocking.out -I. -L../target/debug/ -lwstunnel
```

Compile non-blocking example:

```bash
gcc -Wall -g -O0 example_nonblocking.c -o example_nonblocking.out -I. -L../target/debug/ -lwstunnel
```

# Run example

Run blocking example:

```bash
LD_LIBRARY_PATH=../target/debug ./example_blocking.out
```

Run non-blocking example:

```bash
LD_LIBRARY_PATH=../target/debug ./example_nonblocking.out
```

They will run command `wstunnel server wss://[::]:8585`

You can connect to it with:
```bash
wstunnel client -L socks5://127.0.0.1:8888 --connection-min-idle 5 wss://localhost:8585
```
