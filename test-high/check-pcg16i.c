#define XX_PREDECLS

#define XX_INFO \
            "pcg16i_random_r:\n" \
            "      -  result:      16-bit unsigned int (uint16_t)\n" \
            "      -  period:      2^16   (* 2^15 streams)\n" \
            "      -  state type:  pcg16i_random_t (%zu bytes)\n" \
            "      -  output func: RXS-M-XS\n" \
            "\n", sizeof(pcg16i_random_t)
            
#define XX_NUMBITS                  "  16bit:"
#define XX_NUMVALUES                10
#define XX_NUMWRAP                  10
#define XX_PRINT_RNGVAL(value)      printf(" 0x%04x", value)
#define XX_RAND_DECL                pcg16i_random_t rng;
#define XX_SEEDSDECL(seeds)         uint16_t seeds[2];
#define XX_SRANDOM_SEEDARGS(seeds)  seeds[0], seeds[1]
#define XX_SRANDOM_SEEDCONSTS       42u, 54u
#define XX_SRANDOM(...)             \
            pcg16i_srandom_r(&rng, __VA_ARGS__)
#define XX_RANDOM()                 \
            pcg16i_random_r(&rng)
#define XX_BOUNDEDRAND(bound)       \
            pcg16i_boundedrand_r(&rng, bound)
#define XX_ADVANCE(delta)           \
            pcg16i_advance_r(&rng, delta)

#include "pcg_variants.h"
#include "../test-low/check-base.c"
