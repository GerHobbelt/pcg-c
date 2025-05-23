#define XX_PREDECLS

#define XX_INFO \
            "pcg8si_random_r:\n" \
            "      -  result:      8-bit unsigned int (uint8_t)\n" \
            "      -  period:      2^8\n" \
            "      -  state type:  pcg8si_random_t (%zu bytes)\n" \
            "      -  output func: RXS-M-XS\n" \
            "\n", sizeof(pcg8si_random_t)
            
#define XX_NUMBITS                  "   8bit:"
#define XX_NUMVALUES                14
#define XX_NUMWRAP                  14
#define XX_PRINT_RNGVAL(value)      printf(" 0x%02x", value)
#define XX_RAND_DECL                pcg8si_random_t rng;
#define XX_SEEDSDECL(seeds)         uint8_t seeds[1];
#define XX_SRANDOM_SEEDARGS(seeds)  seeds[0]
#define XX_SRANDOM_SEEDCONSTS       42u
#define XX_SRANDOM(...)             \
            pcg8si_srandom_r(&rng, __VA_ARGS__)
#define XX_RANDOM()                 \
            pcg8si_random_r(&rng)
#define XX_BOUNDEDRAND(bound)       \
            pcg8si_boundedrand_r(&rng, bound)
#define XX_ADVANCE(delta)           \
            pcg8si_advance_r(&rng, delta)

#include "pcg_variants.h"
#include "../test-low/check-base.c"
