//****************************************************************************
// @Module        Main
// @Filename      MAIN.C
// @Project       Prakt.dav
//----------------------------------------------------------------------------
// @Controller    Infineon C164CI-8E
//
// @Compiler      KEIL C166
//
// @Codegenerator DAvE 2-0-0
//
// @Description   This file contains the Project initialization function.
//
//----------------------------------------------------------------------------
// @Date          23.04.2012 17:51:39
//
//****************************************************************************

/*
******************************************************************************
@Note




******************************************************************************
*/

//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"

// USER CODE BEGIN (Main,0)

#include <stdio.h>
#include <stdlib.h>

// USER CODE END


//***************************************************************************
// @Global Variables
//***************************************************************************

// USER CODE BEGIN (Main,3)

// USER CODE END


//****************************************************************************
// @Function      void Project_Init(void)
//
//----------------------------------------------------------------------------
// @Description   This function initializes the microcontroller.
//
//----------------------------------------------------------------------------
// @Returnvalue   none
//
//----------------------------------------------------------------------------
// @Parameters    none
//
//----------------------------------------------------------------------------
// @Date          23.04.2012 17:51:39
//
//****************************************************************************

void Project_Init(void)
{

  // USER CODE BEGIN (Project_Init,0)

  // USER CODE END

  /// the following initialization is made by the compiler EDE when you
  /// import the DAvE project

  /// --- initialization of the SYSCON Register ---
  ///- 256 words system stack
  ///- the internal ROM area is mapped to segment 1
  ///- the segmentation is enabled (CSP is saved/restored during interrupt entry/exit)
  ///- the internal ROM is disabled: accesses to the ROM area use the external bus
  ///- the pin #BHE (byte high enable) is enabled
  ///- the system clock output is disabled
  ///- the pin #WR acts as #WRL and pin #BHE acts as #WRH
  ///- the on-chip X-Peripherals are enabled and can be accessed
  ///- pin #RSTIN is an input only
  ///- the on-chip oscillator watchdog is disabled
  ///- latched CS mode; CS signals are latch internally


  /// --- initialization of the BUSCON 0-4 and ADRRSEL Registers 1-4 ---

  /// ---------- external bus 0 is enabled ----------
  ///- 16-bit multiplexed bus
  ///- memory cycle time control: 15 waitstates
  ///- read/write delay control: activate signal 1 TCL after falling edge of ALE  
  ///- chip select mode: address chip select 
  ///- memory tristate control: 1 waitstate
  ///- ALE lengthening control: lengthened ALE signal


  // initializes the IO ports
  IO_vInit();

  // initializes the Asynchronous/Synchronous Serial Interface (ASC)
  ASC_vInit();

  // initializes the General Purpose Timer Unit 1 (GPT1)
  GT1_vInit();

  // USER CODE BEGIN (Project_Init,1)

  // USER CODE END

  /// globally enable interrupts
  IEN = 1;
}


//****************************************************************************
// @Function      void main(void)
//
//----------------------------------------------------------------------------
// @Description   This is the main function.
//
//----------------------------------------------------------------------------
// @Returnvalue   none
//
//----------------------------------------------------------------------------
// @Parameters    none
//
//----------------------------------------------------------------------------
// @Date          23.04.2012 17:51:39
//
//****************************************************************************

void main(void)
{
  // USER CODE BEGIN (Main,1)
  int ledState = 0;	// LED Status
  bit oldState = 0;

  char s[40];
  // USER CODE END

  Project_Init();

  // USER CODE BEGIN (Main,2)
	
	ClrScr();
	DoPrintZ(1, "Hallo!");
	DoPrintZ(3, "Hallo Welt!");
	DoPrintZ(4, "Hallo Jakob______________________");
	DoPrintZ(1, "Hallo Raffi");
	DoPrintZ(2, "XXXXXXXXXXXXXXX");
	DoPrintZ(2, "Hallo Raffi");
	DoPrintZ(4, "Hallo Jakob");

	while(1)
	{ 	

		bit state = KeyDown();

		if(!oldState && state)
		{	switch(GetKey())
			{	case '1':		//printf("Taste 1 ist gedrückt!!\n\r");
								ledState ^= 0x80; 
								break;
				case '2':		//printf("Taste 2 ist gedrückt!!\n\r");
								ledState ^= 0x40;
								break;
				case '3':		//printf("Taste 3 ist gedrückt!!\n\r");
								ledState ^= 0x20;
								break;
				case '4':		//printf("Taste 4 ist gedrückt!!\n\r");
								ledState ^= 0x10;
								break;
				default:		//printf("Fehler bei der Tastenbestimmung!!\n\r");
								break;
			}
			IO_vWritePort(P1L,ledState);

				/*
			
			sprintf(s, "Taste %c ist gedrueckt", GetKey()); // mehr als 20 zeichen -> t sollte nicht mehr dabei sein; ohne fehler
			DoPrintZ(2, "Hallo Welt!"); // es muesste ohne flackern das zweite angezeigt werden, nichts mit hallo welt.
			DoPrintZ(2, s);
			  */
		}
		oldState = state;
	}

  // USER CODE END
}

