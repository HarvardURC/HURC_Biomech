#ifndef mcp23S08_h
#define mcp23S08_h

#include <stdbool.h>

#define mcp23S08_CS 9

//! \brief Select IO expander via SPI
void mcp1Select();

//! \brief Deselect IO expander via SPI
void mcp1Deselect();

//! \brief Initialize IO expander by assigning all pins as outputs
void mcp1Reset();

//! \brief Write value to IO expander pin
void mcpWrite(uint pin, bool val);

//! \brief Set IO direction of pin. 1 is an input
void mcpDir(uint pin, bool val);

//! \brief Reset IO expander and initialize CS gpio
void mcp23S08_init();

#endif
