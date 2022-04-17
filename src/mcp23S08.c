#include <stdio.h>

#include "mcp23S08.h"
#include "pico/stdlib.h"
#include "pico/sync.h"
#include "hardware/spi.h"
#include "spilib.h"
#include "mutexes.h"

uint8_t mcp1Status = 0;
uint8_t mcp1Dir = 0;

void mcp1Select() {
  asm volatile("nop \n nop \n nop");
  gpio_put(mcp23S08_CS, 0);  // Active low
  asm volatile("nop \n nop \n nop");
}

void mcp1Deselect() {
  asm volatile("nop \n nop \n nop");
  gpio_put(mcp23S08_CS, 1);  // Active low
  asm volatile("nop \n nop \n nop");
}

void mcp1Reset() {
  mcp1Select();
  uint8_t buf[] = {0b01000000, 0x00, 0b00000000}; //Last bit in address is R/W; 0 means write. Assigning all pins as outputs here
  spi_write_blocking(SPI_PORT, buf, 3);
  mcp1Deselect();
}

void mcpWrite(uint pin, bool val) {
  mutex_enter_blocking(&spi_lockout);
  mcp1Select();
  if(val) {
    mcp1Status |= 1<<pin;
  } else {
    mcp1Status &= ~(1<<pin);
  }
  uint8_t buf[] = {0b01000000, 0x0A, mcp1Status}; //Last bit in address is R/W; 0 means write.
  spi_write_blocking(SPI_PORT, buf, 3);
  mcp1Deselect();
  mutex_exit(&spi_lockout);
}

void mcpDir(uint pin, bool val) {
  mutex_enter_blocking(&spi_lockout);
  mcp1Select();
  if(val) {
    mcp1Dir |= 1<<pin;
  } else {
    mcp1Dir &= ~(1<<pin);
  }
  uint8_t buf[] = {0b01000000, 0x00, mcp1Dir}; //Last bit in address is R/W; 0 means write.
  spi_write_blocking(SPI_PORT, buf, 3);
  mcp1Deselect();
  mutex_exit(&spi_lockout);
}

void mcp23S08_init() {
  gpio_init(mcp23S08_CS);
  gpio_set_dir(mcp23S08_CS, GPIO_OUT);
  gpio_put(mcp23S08_CS, 1); //Active low
  mcp1Reset();
  mcpDir(0, 1);
  mcpDir(1, 1);
}