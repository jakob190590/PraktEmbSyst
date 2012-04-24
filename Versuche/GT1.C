//****************************************************************************
// @Module        General Purpose Timer Unit 1
// @Filename      GT1.C
// @Project       Prakt.dav
//----------------------------------------------------------------------------
// @Controller    Infineon C164CI-8E
//
// @Compiler      KEIL C166
//
// @Codegenerator DAvE 2-0-0
//
// @Description   This file contains all functions that use the GPT1 unit.
//                
//
//----------------------------------------------------------------------------
// @Date          23.04.2012 17:51:39
//
//****************************************************************************


//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"

// USER CODE BEGIN (GT1_General,1)

// USER CODE END


//***************************************************************************
// @Global Variables
//***************************************************************************

// USER CODE BEGIN (GT1_General,2)

static int nTaste, aTaste = 0xF0; // neue und alte taste
static bit tFlag = 0; // taster flag
static bit iCnt = 0; // interrupt counter

// USER CODE END


//****************************************************************************
// @Function      void GT1_vInit(void)
//
//----------------------------------------------------------------------------
// @Description   This function initializes the GPT1 component. It effects all
//                necessary configurations of the SFR, depending on the selected
//                operating mode. The configuration determines whether the GPT1
//                interrupts are to be released, and the priority of the 
//                released interrupt.
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

void GT1_vInit(void)
{
  /// ------------ Timer 3 Control Register ----------
  ///  timer 3 works in timer mode
  ///  prescaler factor is 8
  ///  timer 3 run bit is reset
  ///  up/down control bit is reset 
  ///  external up/down control is disabled
  T3CON = 0x0000;
  T3    = 0x0000;  //  load timer 3 register

  /// ---------- Timer 2 Control Register ----------
  ///  timer 2 works in timer mode
  ///  prescaler factor is 8
  ///  up/down control bit is reset 
  ///  external up/down control is disabled
  T2CON = 0x0000;
  T2    = 0x0000;  //  load timer 2 register

  ///  enable timer 2 interrupt
  ///  timer 2 interrupt priority level(ILVL) = 4
  ///  timer 2 interrupt group level (GLVL) = 0
  T2IC = 0x0050;

  /// ---------- Timer 4 Control Register ----------
  ///  timer 4 works in timer mode
  ///  prescaler factor is 8
  ///  timer 4 run bit is reset
  ///  up/down control bit is reset 
  ///  external up/down control is disabled
  T4CON = 0x0000;
  T4    = 0x0000;  //  load timer 4 register



  // USER CODE BEGIN (GT1_Init,1)

  // USER CODE END


  T2R = 1;         //   set timer 2 run bit 
}


//****************************************************************************
// @Function      void GT1_viIsrTmr2(void) interrupt T2INT
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the GPT1 timer 2.
//                It is called up when the timer 2 register over or under-
//                flows or if timer 3 is reloaded with the content of timer 2
//                (external signal or T3 over/underflow) or if an external
//                capture event arrives.
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
// @Date          23.04.2012 17:51:39
//
//****************************************************************************

void GT1_viIsrTmr2(void) interrupt T2INT
{
  // USER CODE BEGIN (GT1_IsrTmr2,1)
	
	nTaste = P1H & 0xF0;
	if (nTaste != 0xF0 && nTaste == aTaste)
	{
		if (iCnt == 0)
		{
			iCnt = 1;			
		}
		else
		{
			iCnt = 0;
			tFlag = 1;
		}
	}
	else
	{
		iCnt = 0;
		tFlag = 0;
	}

	aTaste = nTaste;

  // USER CODE END
}




// USER CODE BEGIN (GT1_General,3)

bit KeyDown(void)
{
	return tFlag;
}

char GetKey(void)
{	
	switch(nTaste)
	{	
		case 0xE0:
			return '1';
		case 0xD0:
			return '2';
		case 0xB0:
			return '3';
		case 0x70:
			return '4';
		default: // dieser fall hat nicht einzutreten PUNKT
			return 0;
	}	
}

// USER CODE END

