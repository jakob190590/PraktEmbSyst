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
// @Date          05.06.2012 15:19:14
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

char kanal = 0;	// Analogkanal

char stufe = 1; // Geschw.stufe fuer Motor

unsigned drehzahl;

bit refresh = 0; // refresh complete display

unsigned compare16 = -500 * 1;

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
// @Date          05.06.2012 15:19:14
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

  // initializes the Analog/Digital Converter (ADC)
  ADC_vInit();

  // initializes the Capture/Compare Unit CAPCOM2
  CC2_vInit();

  // initializes the General Purpose Timer Unit 1 (GPT1)
  GT1_vInit();

  // initializes the Real Time Clock (RTC)
  RTC_vInit();

  // USER CODE BEGIN (Project_Init,1)

	// Compare-Wert neu setzen
	CC2_vSetCCxReg(CC_16, compare16);

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
// @Date          05.06.2012 15:19:14
//
//****************************************************************************

void main(void)
{
  // USER CODE BEGIN (Main,1)
	
	int ledState = 0;	// LED Status
	char s[COLCOUNT + 1]; // 20 Zeichen fuers Display + '\0'

  // USER CODE END

  Project_Init();

  // USER CODE BEGIN (Main,2)
	
	ClrScr();
	DoPrintZ(1, "Hallo!");

	while(1)
	{ 	
				
		if (KeyDown())
		{
			switch(GetKey())
			{

				case '1': 
		
					if (++kanal >= ADNUM) // kanal = ++kanal % ADNUM;
						kanal = 0;

					refreshDisplay(REFRESH_Z1);

					ledState ^= 0x10; 
					break;

				case '2':	
					
					refreshDisplay(REFRESH_Z2);
									
					ledState ^= 0x20;
					break;

				case '3':

					// Geschw.stufe erhoehen
					if (stufe < 10)
					{
						stufe++;
						compare16 = -500 * stufe;

						refreshDisplay(REFRESH_Z4);
					}
					
					ledState ^= 0x40;
					break;

				case '4':

					// Geschw.stufe erniedrigen
					if (stufe > 1)
					{
						stufe--;
						compare16 = -500 * stufe;

						refreshDisplay(REFRESH_Z4);
					}

					ledState ^= 0x80;
					break;
			}

			IO_vWritePort(P1L, ledState);

		}

		// refresh Flag wird von RTC gesetzt
		if (refresh)
		{
			refreshDisplay(REFRESH_ALL);
			refresh = 0;
		}

		// Messung wird durch StartTemp() angestoﬂen,
		// und angezeigt, sobald's fertig ist.
		if (bTempDa())
		{
			sprintf(s, "Temperatur: %5.2f", fGetTemp());
			DoPrintZ(3, s);
		}
	}

  // USER CODE END
}

