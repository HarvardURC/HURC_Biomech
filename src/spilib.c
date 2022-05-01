#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "spilib.h"

void spilib_init() {
  spi_init(SPI_PORT, 2000000); //10 Mhz operation
  gpio_set_function(PIN_MISO, GPIO_FUNC_SPI);
  gpio_set_function(PIN_SCK, GPIO_FUNC_SPI);
  gpio_set_function(PIN_MOSI, GPIO_FUNC_SPI);
}