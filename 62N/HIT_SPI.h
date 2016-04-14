#ifndef HIT_SPI_H
#define HIT_SPI_H
#include "typedefine.h"

#define SPI_CHECK_62T 0
#define SPI_SEND_CMD 1

void spi_Setup();
void spi1_Setup();
void SPI_62TA_loop();
void SPI_62TB_loop();
#endif