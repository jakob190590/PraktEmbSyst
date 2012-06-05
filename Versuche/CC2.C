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
// @Date          05.06.2012 15:19:14
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

static unsigned idata t18s[TEMPSAMPLES]; 
static unsigned idata t19s[TEMPSAMPLES];
static bit ready18 = 0;
static bit ready19 = 0;
static int offs; // Offset, fuer Index bei Differenzberechnung in fGetTemp()

static unsigned flanken = 0;

extern unsigned drehzahl;
extern unsigned compare16;

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
// @Date          05.06.2012 15:19:14
//
//****************************************************************************

void CC2_vInit(void)
{
  /// ---- Timer 7 Configuration -------------
  ///  timer 7 works in timer mode
  ///  prescaler factor is 8

  /// ---- Timer 8 Configuration -------------
  ///  timer 8 works in timer mode
  ///  prescaler factor is 8

  T78CON = 0x0000;
  T7     = 0xFFFF;    // load timer 7 register
  T8     = 0x0000;    // load timer 8 register
  T7REL  = 0xEC77;    // load timer 7 reload register
  T8REL  = 0x0000;    // load timer 8 reload register

  ///  enable timer 7 interrupt
  ///  timer 7 interrupt priority level(ILVL) = 7
  ///  timer 7 interrupt group level (GLVL) = 1
  T7IC = 0x005D;

  /// P8.0 is used as output for CAPCOM channel 16
  /// P8.1 is used as input for CAPCOM channel 17
  /// P8.2 is used as input for CAPCOM channel 18
  /// P8.3 is used as input for CAPCOM channel 19

  // initializes port 8 for the capture/compare channels
  P8   |= 0x0000;     //  set port data register
  ODP8 |= 0x0000;     //  set port open drain control register
  DP8  |= 0x0001;     //  set port direction register


  /// ---- Capture Compare Channel 16 -------------
  ///  compare mode 3:  set output pin CC16IO on each match
  ///  CC16 allocated to timer T7

  /// ---- Capture Compare Channel 17 -------------
  ///  capture on positive transition (rising edge) at pin CC17IO
  ///  CC17 allocated to timer T7

  /// ---- Capture Compare Channel 18 -------------
  ///  capture on positive transition (rising edge) at pin CC18IO
  ///  CC18 allocated to timer T8

  /// ---- Capture Compare Channel 19 -------------
  ///  capture on negative transition (falling edge) at pin CC19IO
  ///  CC19 allocated to timer T8

  CCM4  = 0xA917;
  CC16  = 0x0000;  // load CC16 register
  CC17  = 0x0000;  // load CC17 register
  CC18  = 0x0000;  // load CC18 register
  CC19  = 0x0000;  // load CC19 register

  ///  enable CC16 interrupt
  ///  CC16 interrupt priority level(ILVL) = 7
  ///  CC16 interrupt group level (GLVL) = 0
  CC16IC = 0x005C;

  ///  enable CC17 interrupt
  ///  CC17 interrupt priority level(ILVL) = 7
  ///  CC17 interrupt group level (GLVL) = 2
  CC17IC = 0x005E;

  ///  enable CC18 interrupt
  ///  CC18 interrupt priority level(ILVL) = 14
  ///  CC18 interrupt group level (GLVL) = 0
  CC18IC = 0x0078;

  ///  use PEC channel 0 for CC18 interrupt
  ///  - count = 50
  ///  - word transfer
  ///  - increment destination pointer
  PECC0 = 0x0232;

  SRCP0 = _sof_(&CC18);
  /// User defined destination pointer is selected for PECC Channel 0

  ///  enable CC19 interrupt
  ///  CC19 interrupt priority level(ILVL) = 14
  ///  CC19 interrupt group level (GLVL) = 1
  CC19IC = 0x0079;

  ///  use PEC channel 1 for CC19 interrupt
  ///  - count = 50
  ///  - word transfer
  ///  - increment destination pointer
  PECC1 = 0x0232;

  SRCP1 = _sof_(&CC19);
  /// User defined destination pointer is selected for PECC Channel 1


  /// ---- Capture Compare Channel 24 -------------
  ///  disable capture compare channel 24

  /// ---- Capture Compare Channel 25 -------------
  ///  disable capture compare channel 25

  /// ---- Capture Compare Channel 26 -------------
  ///  disable capture compare channel 26

  /// ---- Capture Compare Channel 27 -------------
  ///  disable capture compare channel 27

  /// timer 7 is running
  /// timer 8 is running
  T78CON |= 0x4040;


  // USER CODE BEGIN (CC2_Init,1)
// DO NOT FORGET TO SET THE DESTINATION-POINTER FOR PECC CHANNEL 1
// DO NOT FORGET TO SET THE DESTINATION-POINTER FOR PECC CHANNEL 0

	// Destination Pointer und Count werden jedes mal in StartTemp gesetzt!

	CC18IE = 0;
	CC19IE = 0;
	
  // USER CODE END

}


//****************************************************************************
// @Function      void CC2_viIsrTmr7(void) interrupt T7INT
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the CAPCOM timer 7.
//                It is called when the timer 7 register overflows.
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
// @Date          05.06.2012 15:19:14
//
//****************************************************************************

void CC2_viIsrTmr7(void) interrupt T7INT
{
  // USER CODE BEGIN (CC2_IsrTmr7,0)

	static unsigned zaehler = 0;

	// Periode von 2 ms abgelaufen
	// P8.0 wird automatisch zurückgesetzt!	

	zaehler++;
	if (zaehler >= 500) // 500 == 1 s / 2 ms 
	{
		drehzahl = flanken * 2;
		flanken = 0;
		zaehler = 0;
	}

  // USER CODE END
}


//****************************************************************************
// @Function      void CC2_viIsrCC16(void) interrupt CC16INT
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the capture/
//                compare register CC16. If the content of the corresponding 
//                compare timer (configurable) equals the content of the
//                capture/compare register CC16 or if a capture event
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
// @Date          05.06.2012 15:19:14
//
//****************************************************************************

void CC2_viIsrCC16(void) interrupt CC16INT
{
  // USER CODE BEGIN (CC2_IsrCC16,0)

	// Compare-Wert neu setzen
	CC2_vSetCCxReg(CC_16, compare16);

  // USER CODE END
}


//****************************************************************************
// @Function      void CC2_viIsrCC17(void) interrupt CC17INT
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the capture/
//                compare register CC17. If the content of the corresponding 
//                compare timer (configurable) equals the content of the
//                capture/compare register CC17 or if a capture event
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
// @Date          05.06.2012 15:19:14
//
//****************************************************************************

void CC2_viIsrCC17(void) interrupt CC17INT
{
  // USER CODE BEGIN (CC2_IsrCC17,0)

	flanken++;

  // USER CODE END
}


//****************************************************************************
// @Function      void CC2_viIsrCC18(void) interrupt CC18INT
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the capture/
//                compare register CC18. If the content of the corresponding 
//                compare timer (configurable) equals the content of the
//                capture/compare register CC18 or if a capture event
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
// @Date          05.06.2012 15:19:14
//
//****************************************************************************

void CC2_viIsrCC18(void) interrupt CC18INT
{
  // USER CODE BEGIN (CC2_IsrCC18,0)
		 	
	CC18IE = 0;
	offs = -1;
	ready18 = 1;

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
// @Date          05.06.2012 15:19:14
//
//****************************************************************************

void CC2_viIsrCC19(void) interrupt CC19INT
{
  // USER CODE BEGIN (CC2_IsrCC19,0)

	CC19IE = 0;		
	offs = 0;
	ready19 = 1;

  // USER CODE END
}



// USER CODE BEGIN (CC2_General,3)

void StartTemp()
{				   
	
	// PEC Dest. Pointer ist wohl nur 16 bit!
	// es fehlt Teil der Adresse: 0x80000 
	// Arrays "near" deklarieren oder so? -- scheint
	// (zumindest im Debugger) nichts zu helfen...

	// printf("t18s: %8x\nt19s: %8x\n", t18s, t19s);

	INT_vSetPecDesP(0, t18s); 
	INT_vSetPecDesP(1, t19s); 

	INT_vSetPecCount(0, TEMPSAMPLES);
	INT_vSetPecCount(1, TEMPSAMPLES);
	
	ready18 = 0;
	ready19 = 0;

	// CC interrupt aktivieren
	CC18IR = 0;	//reset pending interrupt
	CC18IE = 1;	// enable interrupt
	CC19IR = 0;	//reset pending interrupt
	CC19IE = 1;	// enable interrupt
}

bit bTempDa()
{
	if (ready18 && ready19)
	{
		ready18 = ready19 = 0;
		return 1;
	}
	return 0;
}

float fGetTemp()
{
	
	// Summen der tds/tps
	unsigned stds = 0;
	unsigned stps = 0;
	int i;
	for (i = 1; i < TEMPSAMPLES; i++)
	{
		stps += t19s[i] - t19s[i - 1];
		stds += t19s[i] - t18s[i + offs];
	}
	
	return ((float) stds / stps - 0.32) / 0.0047;
}

// USER CODE END


