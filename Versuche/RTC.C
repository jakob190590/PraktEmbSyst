//****************************************************************************
// @Module        RTC
// @Filename      RTC.C
// @Project       Prakt.dav
//----------------------------------------------------------------------------
// @Controller    Infineon C164CI-8E
//
// @Compiler      KEIL C166
//
// @Codegenerator DAvE 2-0-0
//
// @Description   This file contains functions that use the
//                Real Time Clock.
//
//----------------------------------------------------------------------------
// @Date          05.06.2012 15:19:16
//
//****************************************************************************


//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"

// USER CODE BEGIN (RTC_General,1)

#include <stdio.h>

// USER CODE END


//***************************************************************************
// @Global Variables
//***************************************************************************

// USER CODE BEGIN (RTC_General,2)

extern bit refresh; // refresh complete display

extern char kanal;	// Analogkanal

extern char stufe; // Geschw.stufe fuer Motor

extern unsigned drehzahl; // Motordrehzahl

// USER CODE END


//****************************************************************************
// @Function      void RTC_vInit(void)
//
//----------------------------------------------------------------------------
// @Description   This function initializes the real time clock. It
//                effects all necessary configurations of the SFR.
//                The configuration determines whether the RTC
//                interrupt is to be released, and the priority of 
//                the released interrupt.
//
//----------------------------------------------------------------------------
// @Returnvalue   none
//
//----------------------------------------------------------------------------
// @Parameters    none
//
//----------------------------------------------------------------------------
// @Date          05.06.2012 15:19:16
//
//****************************************************************************

void RTC_vInit(void)
{

  ///  enable RTC interrupt
  ///  RTC interrupt priority level(ILVL) = 6
  ///  RTC interrupt group level (GLVL) = 0
  XP3IC = 0x0058;


  RTCIE  = 1;   //  enable RTC interrupt in sub-node register

  /// ----- Timer 14 reload register ----
  /// time base = 999,987 ms
  T14REL = 0xB3B5;
  T14    = 0xB3B5;

  // USER CODE BEGIN (RTC_Init,1)

  // USER CODE END

}


//****************************************************************************
// @Function      void RTC_viIsr(void) interrupt XP3INT
//
//----------------------------------------------------------------------------
// @Description   This is the RTC interrupt service routine. It is called
//                up when the timer 14 register overflows and is reloaded.
//                This interrupt request may eg. be used to provide a system 
//                time tick independent of the CPU frequency, or to wake up
//                regularly from idle mode.
//                
//                Please note that you have to add application specific
//                code to this function.
//
//----------------------------------------------------------------------------
// @Returnvalue   none
//
//----------------------------------------------------------------------------
// @Parameters    none
//
//----------------------------------------------------------------------------
// @Date          05.06.2012 15:19:16
//
//****************************************************************************

void RTC_viIsr(void) interrupt XP3INT
{
  // USER CODE BEGIN (RTC_Isr,0)

  // USER CODE END

  if(RTCIR)      // if RTC interrupt request
  {
    // USER CODE BEGIN (RTC_Isr,2)

		// Displayausgaben erneuern in main:
		// refresh-Flag setzen
		refresh = 0xF; // REFRESH_Z1 | REFRESH_Z2 | REFRESH_Z3 | REFRESH_Z4;

    // USER CODE END

    RTCIR = 0;
  }

  // USER CODE BEGIN (RTC_Isr,3)

  // USER CODE END

}



// USER CODE BEGIN (RTC_General,3)

// Aktualisiert die Ausgabe(n) auf dem Display
void refreshDisplay(char refresh)
{
	char s[COLCOUNT + 1]; // 20 Zeichen fuers Display + '\0'

	if((refresh | REFRESH_Z1) == refresh)
	{
		sprintf(s, "Kanal %d: %5.2f", kanal, fGibADmittel(kanal));
		DoPrintZ(1, s);
	}
	
	if((refresh | REFRESH_Z2) == refresh)
	{	
		sprintf(s, "Gewicht: %5.2f", fGibGewicht());
		DoPrintZ(2, s);
	}

	if((refresh | REFRESH_Z3) == refresh)
	{		
		StartTemp();
		// Ausgabe in 3. Zeile erfolgt dann in main,
		// sobald die Messung erfolgt ist! (Nicht hier, 
		// weil's da noch nicht fertig waere.)
	}

	if((refresh | REFRESH_Z4) == refresh)
	{	
		sprintf(s, "Stufe %d: %d 1/min", stufe, drehzahl);
		DoPrintZ(4, s);
	}

}

// USER CODE END

