#include "include/assembly.hpp"
#include "include/gcc_builtin.hpp"
#include "include/signal.hpp"

static unsigned int rv = 1;

typedef unsigned int (*func_type)(void);

void FORCE_NOINLINE helper(func_type fp) {
  rv = fp();
}

int main()
{
  unsigned char m[] = FUNC_MACHINE_CODE;
  rv = m[0];

  signal(SIGSEGV, sigsegv_handler); // catch SIGSEGV
  helper((func_type)(&m));
  return rv;
}