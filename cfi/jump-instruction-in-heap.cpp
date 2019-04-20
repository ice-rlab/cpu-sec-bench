#include "include/assembly.hpp"
#include "include/signal.hpp"

static unsigned int rv = 1;

int main()
{
  unsigned char *m = new unsigned char [16];
  assign_fake_machine_code(m);
  PUSH_LABEL(xlabel);
  begin_catch_nx_exception(m);
  JMP_DAT(m);
  DECL_LABEL(xlabel);
  end_catch_nx_exception();
  rv--;
  return rv;
}
