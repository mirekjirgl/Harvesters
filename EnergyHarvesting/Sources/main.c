/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "LED.h"
#include "WAIT1.h"
#include "CsIO1.h"
#include "IO1.h"
#include "MOSI.h"
#include "MISO.h"
#include "SCL.h"
#include "CS.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include <stdio.h>

void SPI_write_byte(char SPI_addr, char SPI_byte)
{
	char i;
	char shift = 64;
	
	// Initialization
	MOSI_SetVal(MOSI_Init((LDD_TUserData*) NULL));
	SCL_ClrVal(SCL_Init((LDD_TUserData*) NULL));
	CS_ClrVal(CS_Init((LDD_TUserData*) NULL));
	
	WAIT1_Wait10Cycles();
	
	// Address and writing
	CS_SetVal(CS_Init((LDD_TUserData*) NULL));
	asm("nop");
	MOSI_ClrVal(MOSI_Init((LDD_TUserData*) NULL));
	asm("nop");
	SCL_SetVal(SCL_Init((LDD_TUserData*) NULL));
	asm("nop");
	SCL_ClrVal(SCL_Init((LDD_TUserData*) NULL));
	asm("nop");
	
	for(i=0;i<7;i++)
	{
		MOSI_PutVal(MOSI_Init((LDD_TUserData*) NULL), 1 && (SPI_addr&(shift)));
		asm("nop");
		//printf("%d", 1 && (SPI_addr&(shift)));
		SCL_SetVal(SCL_Init((LDD_TUserData*) NULL));
		asm("nop");
		SCL_ClrVal(SCL_Init((LDD_TUserData*) NULL));
		asm("nop");
		shift >>= 1;
	}
	
	// Data
	shift = 128;
	
	for(i=0;i<8;i++)
	{
		MOSI_PutVal(MOSI_Init((LDD_TUserData*) NULL), 1 && (SPI_byte&(shift)));
		//printf("\r\n%d", 1 && (SPI_byte&(shift)));
		asm("nop");
		SCL_SetVal(SCL_Init((LDD_TUserData*) NULL));
		asm("nop");
		SCL_ClrVal(SCL_Init((LDD_TUserData*) NULL));
		asm("nop");
		shift >>= 1;
	}	
	
	CS_ClrVal(CS_Init((LDD_TUserData*) NULL));
}

char SPI_read_byte(char SPI_addr)
{
	char i, SPI_byte, data_tmp[8];
	char shift = 64;
	
	// Initialization
	MOSI_SetVal(MOSI_Init((LDD_TUserData*) NULL));
	SCL_ClrVal(SCL_Init((LDD_TUserData*) NULL));
	CS_ClrVal(CS_Init((LDD_TUserData*) NULL));
	
	WAIT1_Wait10Cycles();
	
	// Address and reading
	CS_SetVal(CS_Init((LDD_TUserData*) NULL));
	asm("nop");
	MOSI_SetVal(MOSI_Init((LDD_TUserData*) NULL));
	asm("nop");
	SCL_SetVal(SCL_Init((LDD_TUserData*) NULL));
	asm("nop");
	SCL_ClrVal(SCL_Init((LDD_TUserData*) NULL));
	asm("nop");
	
	for(i=0;i<7;i++)
	{
		MOSI_PutVal(MOSI_Init((LDD_TUserData*) NULL), 1 && (SPI_addr&(shift)));
		asm("nop");
		SCL_SetVal(SCL_Init((LDD_TUserData*) NULL));
		asm("nop");
		SCL_ClrVal(SCL_Init((LDD_TUserData*) NULL));
		asm("nop");
		shift >>= 1;
	}
	
	// Data
	for(i=0;i<8;i++)
	{
		data_tmp[i] = (MISO_GetVal(MISO_Init((LDD_TUserData*) NULL)));
		asm("nop");
		SCL_SetVal(SCL_Init((LDD_TUserData*) NULL));
		asm("nop");
		SCL_ClrVal(SCL_Init((LDD_TUserData*) NULL));
		asm("nop");
		//printf("%d\r\n", data_tmp[i]);
	}
	
	// Creating SPI_byte
	SPI_byte = 0;
	for(i=0;i<8;i++)
	{
		SPI_byte |= data_tmp[i];
		SPI_byte <<= 1;
	}
	
	CS_ClrVal(CS_Init((LDD_TUserData*) NULL));
	return SPI_byte>>=1;
}


/* main */
int main(void)
{
  /* Local variable definition*/

	
  /*** Processor Expert internal initialization. ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization. ***/

  /* Write your code here */
  
  // Start
  printf("START\r\n");

  // Cteni registru
  printf("dev_status (0x22 ro): 0x%x\r\n", SPI_read_byte(0x22));
  printf("storage_status (0x23 ro): 0x%x\r\n", SPI_read_byte(0x23));
  printf("mpp_ratio (0x12 rw): 0x%x\r\n", SPI_read_byte(0x12));
  printf("reg_ldo_cfg (0x0E rw): 0x%x\r\n", SPI_read_byte(0x0E));
  printf("reg_pwr_cfg (0x0F rw): 0x%x\r\n", SPI_read_byte(0x0F));
  printf("reg_aux_cfg (0x10 rw): 0x%x\r\n", SPI_read_byte(0x10));
  printf("reg_aux_gnd_cfg (0x11 rw): 0x%x\r\n", SPI_read_byte(0x11));
  printf("reg_pwr_mgt (0x19 rw): 0x%x\r\n", SPI_read_byte(0x19));
  printf("primary_cell_cfg (0x06 rw): 0x%x\r\n", SPI_read_byte(0x06));
  printf("sleep_wake-up_reg (0x13 rw): 0x%x\r\n", SPI_read_byte(0x13));
  printf("sleep_reg_lo (0x14 rw): 0x%x\r\n", SPI_read_byte(0x14));
  printf("sleep_reg_mid (0x15 rw): 0x%x\r\n", SPI_read_byte(0x15));
  printf("sleep_reg_hi (0x16 rw): 0x%x\r\n", SPI_read_byte(0x16));
  printf("reg_lux_cgf (0x1C rw): 0x%x\r\n", SPI_read_byte(0x1C));
  printf("reg_lux_result (0x1D ro): 0x%x\r\n", SPI_read_byte(0x1D));
  
  WAIT1_Waitms(100);
  
  // Nastaveni registru
  SPI_write_byte(0x1C, 0x20);
  WAIT1_Waitms(100);
  printf("reg_lux_cgf (0x1C rw): 0x%x\r\n", SPI_read_byte(0x1C));
  WAIT1_Waitms(100);
  printf("reg_lux_result (0x1D ro): 0x%x\r\n", SPI_read_byte(0x1D));
  
  
  
  printf("STOP\r\n");

  // LED blinking  
  for(;;){
	  LED_SetVal(LED_Init((LDD_TUserData*) NULL));
	  WAIT1_Waitms(1000);
	  LED_ClrVal(LED_Init((LDD_TUserData*) NULL));
	  WAIT1_Waitms(1000);
  }
  
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
}
