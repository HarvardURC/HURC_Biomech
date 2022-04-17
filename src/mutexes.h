#ifndef mutexes
#define mutexes

#include "pico/sync.h"

mutex_t spi_lockout;

//! \brief Initialize mutexes for SPI and other structures
void init_mutexes();

#endif