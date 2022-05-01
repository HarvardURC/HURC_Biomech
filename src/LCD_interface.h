#ifndef LCD_interface_h
#define LCD_interface_h

#include "hardware/pio.h"

#define LCD_PARALLEL_BASE 0

#define LCD_RST 1 // LCD Reset, MCP23S08 pin 1
#define LCD_RD 3 // Read strobe/clock (Active Low), MCP23S08 pin 3
#define LCD_WR 10 // Write strobe/clock (Active Low)
#define LCD_CD 4 // Command/Data (Command Low), MCP23S08 pin 4
#define LCD_CS 2 // Chip Select (Active Low), MCP23S08 pin 2

//! \brief Initialize LCD interface state machine and pins, write initialization commands
void LCD_init();

//! \brief Low-level function to write a data byte to the LCD
void LCD_dat(uint8_t byte);

//! \brief Low-level function to write a command to the LCD
void LCD_cmd(uint8_t byte);

//! \brief Fill the LCD with a color
void LCD_flood(uint32_t color);

//! \brief Optimized function to draw a rectangle of a certain color on the LCD
void LCD_rect(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color);

//! \brief Draw an image buffer to the LCD
void LCD_buffer(uint8_t *buf, uint16_t x, uint16_t y, uint16_t width, uint16_t height);

#endif