#include "pico/stdlib.h"
#include "pico/sync.h"
#include "mutexes.h"

void init_mutexes() {
  mutex_init(&spi_lockout);
}