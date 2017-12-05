#ifndef __USER_AT24CXX_H_
#define __USER_AT24CXX_H_

#define AT24_I2C_INTERFACE BOARD_AT24_I2C_INTERFACE // HAL I2C handler
#define AT24_DEV_ADDR 0x50 // 8-bit with trailing 0
#define AT24_SIZE 256 // Words

#define AT24CXX_MAX_TIMEOUT_TICKS 1000

typedef struct {
	HAL_LockTypeDef Lock;
	uint8_t TxFlag;
	uint8_t RxFlag;
} AT24_HandleTypeDef;

void AT24CXX_Init(AT24_HandleTypeDef * at24);
HAL_StatusTypeDef AT24CXX_Random_Read(AT24_HandleTypeDef * at24, uint16_t addr, uint8_t * pData);
HAL_StatusTypeDef AT24CXX_Sequencial_Read(AT24_HandleTypeDef * at24, uint16_t addr, uint8_t * pData, uint8_t length);

HAL_StatusTypeDef AT24CXX_Byte_Write(AT24_HandleTypeDef * at24, uint16_t addr, uint8_t * pData);
HAL_StatusTypeDef AT24CXX_Sequencial_Write(AT24_HandleTypeDef * at24, uint16_t addr, uint8_t * pData, uint8_t length);

#endif
