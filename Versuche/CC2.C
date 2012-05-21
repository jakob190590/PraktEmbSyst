//****************************************************************************
// @Module        CC2
// @Filename      CC2.C
// @Project       Prakt.dav
//----------------------------------------------------------------------------
// @Controller    Infineon C164CI-8E
//
// @Compiler      KEIL C166
//
// @Codegenerator DAvE 2-0-0
//
// @Description   This file contains all functions that use the CAPCOM 2
//                peripheral
//                
//
//----------------------------------------------------------------------------
// @Date          21.05.2012 10:38:34
//
//****************************************************************************


//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"

// USER CODE BEGIN (CC2_General,1)

// USER CODE END


//***************************************************************************
// @Global Variables
//***************************************************************************

// USER CODE BEGIN (CC2_General,2)

#define TEMPSAMPLES 50

static unsigned tds[TEMPSAMPLES]; // T_D s
static unsigned tps[TEMPSAMPLES]; // T_P s
static unsigned index = 0;
static bit syncing;

// USER CODE END


//****************************************************************************
// @Function      void CC2_vInit(void)
//
//----------------------------------------------------------------------------
// @Description   This function initializes the CAPCOM 2 component. It effects
//                all necessary configurations of the SFR, depending on the
//                selected operating mode. The configuration determines
//                whether the CAPCOM interrupts are to be released, and 
//                the priority of the released interrupt.
//
//----------------------------------------------------------------------------
// @Returnvalue   none
//
//----------------------------------------------------------------------------
// @Parameters    none
//
//----------------------------------------------------------------------------
// @Date          21.05.2012 10:38:34
//
//****************************************************************************

void CC2_vInit(void)
{
  /// ---- Timer 7 Configuration -------------
  ///  timer 7 works in timer mode
  ///  prescaler factor is 8
  ///  timer 7 run bit is reset

  /// ---- Timer 8 Configuration -------------
  ///  timer 8 works in timer mode
  ///  prescaler factor is 8

  T78CON = 0x0000;
  T7     = 0x0000;    // load timer 7 register
  T8     = 0x0000;    // load timer 8 register
  T7REL  = 0x0000;    // load timer 7 reload register
  T8REL  = 0x0000;    // load timer 8 reload register

  /// P8.2 is used as input for CAPCOM channel 18
  /// P8.3 is used as input for CAPCOM channel 19

  /// ---- Capture Compare Channel 16 -------------
  ///  disable capture compare channel 16

  /// ---- Capture Compare Channel 17 -------------
  ///  disable capture compare channel 17

  /// ---- Capture Compare Channel 18 -------------
  ///  capture on positive transition (rising edge) at pin CC18IO
  ///  CC18 allocated to timer T8

  /// ---- Capture Compare Channel 19 -------------
  ///  capture on negative transition (falling edge) at pin CC19IO
  ///  CC19 allocated to timer T8

  CCM4  = 0xA900;
  CC18  = 0x0000;  // load CC18 register
  CC19  = 0x0000;  // load CC19 register

  ///  enable CC19 interrupt
  ///  CC19 interrupt priority level(ILVL) = 7
  ///  CC19 interrupt group level (GLVL) = 1
  CC19IC = 0x005D;


  /// ---- Capture Compare Channel 24 -------------
  ///  disable capture compare channel 24

  /// ---- Capture Compare Channel 25 -------------
  ///  disable capture compare channel 25

  /// ---- Capture Compare Channel 26 -------------
  ///  disable capture compare channel 26

  /// ---- Capture Compare Channel 27 -------------
  ///  disable capture compare channel 27

  /// timer 8 is running
  T78CON |= 0x4000;


  // USER CODE BEGIN (CC2_Init,1)

	CC19IE = 0;

  // USER CODE END

}


//****************************************************************************
// @Function      void CC2_viIsrCC19(void) interrupt CC19INT
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the capture/
//                compare register CC19. If the content of the corresponding 
//                compare timer (configurable) equals the content of the
//                capture/compare register CC19 or if a capture event
//                occurs at the associated port pin, the interrupt request 
//                flag is set and an interrupt or PEC transfer is triggered
//                (only if enabled).
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
// @Date          21.05.2012 10:38:34
//
//****************************************************************************

void CC2_viIsrCC19(void) interrupt CC19INT
{
  // USER CODE BEGIN (CC2_IsrCC19,0)

	static unsigned int oldCC19 = 0;
	unsigned int CC19val = CC19;
	unsigned int CC18val = CC18;

	if (syncing)
		syncing = 0;

	else if (index < TEMPSAMPLES)
	{
		tds[index] = CC19val - CC18val;
		tps[index] = CC19val - oldCC19;		
		index++;
	}

	if (index == TEMPSAMPLES)
		// CC interrupt deaktivieren
		CC19IE = 0;

	oldCC19 = CC19;

  // USER CODE END
}



// USER CODE BEGIN (CC2_General,3)

void StartTemp()
{
	syncing = 1;
	index = 0;
	// CC interrupt aktivieren
	CC19IR = 0;	//reset pending interrupt
	CC19IE = 1;	// enable interrupt
}

bit bTempDa()
{
	if (index == TEMPSAMPLES)
	{
		index = 0;
		return 1;
	}
	return 0;
}

float fGetTemp()
{
	float td;
	float tp;

	// Summen der tds/tps
	unsigned stds = 0;
	unsigned stps = 0;
	int i;
	for (i = 0; i < TEMPSAMPLES; i++)
	{
		stds += tds[i];
		stps += tps[i];
	}
	td = (float) stds / TEMPSAMPLES;
	tp = (float) stps / TEMPSAMPLES;
	return ((td / tp - 0.32) / 0.0047);
}

// USER CODE END


