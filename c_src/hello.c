#include "erl_nif.h"

static ERL_NIF_TERM world(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  return enif_make_string(env, "Hello world!", ERL_NIF_LATIN1);
}

static ErlNifFunc nif_funcs[] = {
  {"world", 0, world}
};

ErlNifEntry* nif_init(void);

ErlNifEntry* nif_init(void) {
  static ErlNifEntry entry = { 2,
                               6,
                               "hello",
                               sizeof(nif_funcs) / sizeof(*nif_funcs),
                               nif_funcs,
                               ((void *)0),
                               ((void *)0),
                               ((void *)0),
                               ((void *)0),
                               "beam.vanilla"
  };

  return &entry;
}

