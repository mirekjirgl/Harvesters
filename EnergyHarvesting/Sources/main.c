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
#include "I2C2.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include <stdio.h>


/***** I2C communication *****/

LDD_TError I2C_read_reg(uint8_t I2C_addr, uint8_t *I2C_data, short I2C_dataSize)
{
	uint8_t res;
	LDD_TDeviceData *I2C_Dev;
	
	I2C_Dev = I2C2_Init((LDD_TUserData*) NULL);
	
	/* - Error code, possible codes:
		ERR_OK - OK
		ERR_DISABLED -  Device is disabled
		ERR_SPEED - This device does not work in the active clock configuration
		ERR_BUSY - The I2C device is now running
	*/
	
	res = I2C2_MasterSendBlock(I2C_Dev, &I2C_addr, 1U, LDD_I2C_NO_SEND_STOP);
	
	if (res != ERR_OK)
		return res;
	WAIT1_Waitms(20);
	
	res = I2C2_MasterReceiveBlock(I2C_Dev, I2C_data, I2C_dataSize, LDD_I2C_SEND_STOP);
	WAIT1_Waitms(20);
	
	return res;
}

LDD_TError I2C_write_reg(uint8_t I2C_addr, uint8_t I2C_val) 
{
    uint8_t buf[4], res;
    LDD_TDeviceData * I2C_Dev;
    
    I2C_Dev = I2C2_Init((LDD_TUserData*) NULL);
    
    unsigned char reg_protect_key_addr = 0x1B;
    unsigned char reg_protect_key_val;
    	
    if(I2C_addr >= 0x40)
    	reg_protect_key_val = 0xA5;
    else
    	reg_protect_key_val = 0x4B;

    buf[0] = reg_protect_key_addr;
    buf[1] = reg_protect_key_val;  	
    buf[2] = I2C_addr;
    buf[3] = I2C_val;
  	
  	res = I2C2_MasterSendBlock(I2C_Dev, &buf, 4U, LDD_I2C_SEND_STOP);
  	WAIT1_Waitms(20);
  	
	return res;
}


/***** SPI communication *****/

	// CPOL = 0, CPHA = 0

void SPI_write_byte(unsigned char SPI_addr, unsigned char SPI_byte)
{
	unsigned char i;
	unsigned char shift = 64;
	
	unsigned char reg_protect_key_addr = 0x1B;
	unsigned char reg_protect_key_val;
	
	if(SPI_addr >= 0x40)
		reg_protect_key_val = 0xA5;
	else
		reg_protect_key_val = 0x4B;
	
	
	// Writing the unlock sequence (write corresponding value to the reg_protect_key)
	
	// Initialisation
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
		MOSI_PutVal(MOSI_Init((LDD_TUserData*) NULL), 1 && (reg_protect_key_addr&(shift)));
		//printf("%d\r\n", 1 && (SPI_addr&(shift)));
		asm("nop");
		SCL_SetVal(SCL_Init((LDD_TUserData*) NULL));
		asm("nop");
		SCL_ClrVal(SCL_Init((LDD_TUserData*) NULL));
		asm("nop");
		shift >>= 1;
	}
	
	//printf("\r\n");
	WAIT1_Waitus(100);
	
	// Data writing
	shift = 128;
	
	for(i=0;i<8;i++)
	{
		MOSI_PutVal(MOSI_Init((LDD_TUserData*) NULL), 1 && (reg_protect_key_val&(shift)));	
		//printf("\r\n%d", 1 && (SPI_byte&(shift)));
		asm("nop");
		SCL_SetVal(SCL_Init((LDD_TUserData*) NULL));
		asm("nop");
		SCL_ClrVal(SCL_Init((LDD_TUserData*) NULL));
		asm("nop");
		shift >>= 1;
	}	
	
	
	// Data writing to the register
	
	shift = 64;
	
	// Address and writing command
		MOSI_ClrVal(MOSI_Init((LDD_TUserData*) NULL));
		asm("nop");
		SCL_SetVal(SCL_Init((LDD_TUserData*) NULL));
		asm("nop");
		SCL_ClrVal(SCL_Init((LDD_TUserData*) NULL));
		asm("nop");
		
		for(i=0;i<7;i++)
		{
			MOSI_PutVal(MOSI_Init((LDD_TUserData*) NULL), 1 && (SPI_addr&(shift)));
			//printf("%d\r\n", 1 && (SPI_addr&(shift)));
			asm("nop");
			SCL_SetVal(SCL_Init((LDD_TUserData*) NULL));
			asm("nop");
			SCL_ClrVal(SCL_Init((LDD_TUserData*) NULL));
			asm("nop");
			shift >>= 1;
		}
		
		printf("\r\n");
		WAIT1_Waitus(100);
		
		// Data writing
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

unsigned char SPI_read_byte(unsigned char SPI_addr)
{
	unsigned char i, SPI_byte, data_tmp[8];
	unsigned char shift = 64;
	
	// Initialization	
	MOSI_SetVal(MOSI_Init((LDD_TUserData*) NULL));
	SCL_ClrVal(SCL_Init((LDD_TUserData*) NULL));
	CS_ClrVal(CS_Init((LDD_TUserData*) NULL));
	
	WAIT1_Wait10Cycles();
	
	// Address and reading command
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
	
	WAIT1_Waitus(100);
	
	// Data reading
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
		if(i<7)		
			SPI_byte <<= 1;
	}
	
	CS_ClrVal(CS_Init((LDD_TUserData*) NULL));
	return SPI_byte;
}

/***** main *****/
int main(void)
 {
  /* Local variable definition*/
  unsigned int reg_value = 0x0;
  unsigned int reg_addr = 0x0;

  LDD_TError I2C_error=0;
  unsigned char I2C_data[1];
  
  unsigned int control_char = 0;
  
  /*** Processor Expert internal initialization. ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization. ***/

  /* Write your code here */
  
  // Start
  printf("Vypis hodnot registru\r\n");
  printf("\r\n");
  
  printf("Vyberte typ komunikace: 1-SPI, 2-I2C.\r\n");
  scanf("%d", &control_char);

  if(control_char ==1)
  {
 	  // Reading registers  
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
	  printf("\r\n");
	  
	  control_char = 0;
	  
	  printf("Pro zapis registru (nebo EEPROM) zadej 1, pro cteni registru (nebo EEPROM) zadej 2, pro ukonceni zadej 0.\r\n");
	  scanf("%d", &control_char);
	  
	  //printf("%d\r\n", control_char);
	  
	  while(control_char != 0)
	  {
		  if(control_char == 1)
		  {
			  // Register settings
			  printf("Zadej adresu registru: \r\n");
			  scanf("%x", &reg_addr);
			  printf("Zadej hodnotu registru 0x%x:\r\n",reg_addr);
			  scanf("%x", &reg_value);
			  printf("Zadal jsi hodnotu registru 0x%x:\r\n",reg_value);
			  SPI_write_byte(reg_addr, reg_value);
			  WAIT1_Waitms(100);
			  printf("Zapsal jsi hodnotu 0x%x do registru 0x%x:\r\n",SPI_read_byte(reg_addr), reg_addr);
			  printf("\r\n");
			  
			  printf("Zapsat do dalsiho registru? (ano-1, cteni-2, konec-0)\r\n");
			  scanf("%d", &control_char);
		  }
	
		  if(control_char == 2)
		  {
			  // Register reading
			  printf("Zadej adresu registru: \r\n");
			  scanf("%x", &reg_addr);
			  printf("Hodnota registru 0x%x je 0x%x:\r\n",reg_addr, SPI_read_byte(reg_addr));
			 
			  printf("Cist dalsi registr? (ano-2, zapis-1, konec-0)\r\n");
			  scanf("%d", &control_char);
		  }
	  }
  }
  

  
  if(control_char == 2)
  {
	  I2C_data[0] = 0x00;
	  
	  // Reading registers
	  	  I2C_error = I2C_read_reg(0x22, I2C_data, 1U);
	  	  printf("dev_status (0x22 ro): 0x%x\r\n", I2C_data[0]);
	  	I2C_error = I2C_read_reg(0x23, I2C_data, 1U);
	  	  printf("storage_status (0x23 ro): 0x%x\r\n", I2C_data[0]);
	  	I2C_error = I2C_read_reg(0x12, I2C_data, 1U);
	  	  printf("mpp_ratio (0x12 rw): 0x%x\r\n", I2C_data[0]);
	  	I2C_error = I2C_read_reg(0x0e, I2C_data, 1U);
	  	  printf("reg_ldo_cfg (0x0E rw): 0x%x\r\n", I2C_data[0]);
	  	I2C_error = I2C_read_reg(0x0f, I2C_data, 1U);
	  	  printf("reg_pwr_cfg (0x0F rw): 0x%x\r\n", I2C_data[0]);
	  	I2C_error = I2C_read_reg(0x10, I2C_data, 1U);
	  	  printf("reg_aux_cfg (0x10 rw): 0x%x\r\n", I2C_data[0]);
	  	I2C_error = I2C_read_reg(0x11, I2C_data, 1U);
	  	  printf("reg_aux_gnd_cfg (0x11 rw): 0x%x\r\n", I2C_data[0]);
	  	I2C_error = I2C_read_reg(0x19, I2C_data, 1U);
	  	  printf("reg_pwr_mgt (0x19 rw): 0x%x\r\n", I2C_data[0]);
	  	I2C_error = I2C_read_reg(0x06, I2C_data, 1U);
	  	  printf("primary_cell_cfg (0x06 rw): 0x%x\r\n", I2C_data[0]);
	  	I2C_error = I2C_read_reg(0x13, I2C_data, 1U);
	  	  printf("sleep_wake-up_reg (0x13 rw): 0x%x\r\n", I2C_data[0]);
	  	I2C_error = I2C_read_reg(0x14, I2C_data, 1U);
	  	  printf("sleep_reg_lo (0x14 rw): 0x%x\r\n", I2C_data[0]);
	  	I2C_error = I2C_read_reg(0x15, I2C_data, 1U);
	  	  printf("sleep_reg_mid (0x15 rw): 0x%x\r\n", I2C_data[0]);
	  	I2C_error = I2C_read_reg(0x16, I2C_data, 1U);
	  	  printf("sleep_reg_hi (0x16 rw): 0x%x\r\n", I2C_data[0]);
	  	I2C_error = I2C_read_reg(0x1c, I2C_data, 1U);
	  	  printf("reg_lux_cgf (0x1C rw): 0x%x\r\n", I2C_data[0]);
	  	I2C_error = I2C_read_reg(0x1d, I2C_data, 1U);
	  	  printf("reg_lux_result (0x1D ro): 0x%x\r\n", I2C_data[0]);
	  	  printf("\r\n");
	  	  
	  	  control_char = 0;  

	  	printf("Pro zapis registru (nebo EEPROM) zadej 1, pro cteni registru (nebo EEPROM) zadej 2, pro ukonceni zadej 0.\r\n");
	    scanf("%d", &control_char);
	  		  
	  		  //printf("%d\r\n", control_char);
	  		  
	  		  while(control_char != 0)
	  		  {
	  			  if(control_char == 1)
	  			  {
	  				  // Register settings
	  				  printf("Zadej adresu registru: \r\n");
	  				  scanf("%x", &reg_addr);
	  				  printf("Zadej hodnotu registru 0x%x:\r\n",reg_addr);
	  				  scanf("%x", &reg_value);
	  				  printf("Zadal jsi hodnotu registru 0x%x:\r\n",reg_value);
	  				  I2C_write_reg(reg_addr, reg_value); 
	  				  WAIT1_Waitms(100);
	  				  I2C_read_reg(reg_addr, I2C_data, 1U);
	  				  printf("Zapsal jsi hodnotu 0x%x do registru 0x%x:\r\n",I2C_data[0], reg_addr);
	  				  printf("\r\n");
	  				  
	  				  printf("Zapsat do dalsiho registru? (ano-1, cteni-2, konec-0)\r\n");
	  				  scanf("%d", &control_char);
	  			  }
	  		
	  			  if(control_char == 2)
	  			  {
	  				  // Register reading
	  				  printf("Zadej adresu registru: \r\n");
	  				  scanf("%x", &reg_addr);
	  				  I2C_read_reg(reg_addr, I2C_data, 1U);
	  				  printf("Hodnota registru 0x%x je 0x%x:\r\n",reg_addr, I2C_data[0]);
	  				 
	  				  printf("Cist dalsi registr? (ano-2, zapis-1, konec-0)\r\n");
	  				  scanf("%d", &control_char);
	  			  }
	  		  }

	  /*
	  I2C_error = I2C_read_reg(0x15, data, 1U);
	  printf("Error: 0x%x \r\n",I2C_error);
	  printf("Reg. value: 0x%x\r\n",data[0]);
	  
	  
	  I2C_error = I2C_read_reg(0x10, data, 1U);
	  printf("Error: 0x%x \r\n",I2C_error);
	  printf("Reg. value: 0x%x\r\n",data[0]);
	   */
  }
   
  printf("Konec.\r\n");

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
