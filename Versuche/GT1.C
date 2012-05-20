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
// @Date          20.05.2012 17:17:06
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

static int nTaste = 0xFF; // taste
static bit tFlag = 0; // taster flag
static bit iCnt = 0; // interrupt counter
static bit consumed; // key event consumed


#define BUFLEN 20 // Size des Buffers zur Mittelung (adBuff)
   
static uword adBuff[ADNUM][BUFLEN] = { 0 };	 // damit sollten alle Werte 0 sein.
static unsigned long sum[ADNUM] = { 0 };

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
// @Date          20.05.2012 17:17:06
//
//****************************************************************************

void GT1_vInit(void)
{
  /// ------------ Timer 3 Control Register ----------
  ///  timer 3 works in timer mode
  ///  prescaler factor is 8
  ///  up/down control bit is set
  ///  external up/down control is disabled
  T3CON = 0x0080;
  T3    = 0x09C3;  //  load timer 3 register

  ///  enable timer 3 interrupt
  ///  timer 3 interrupt priority level(ILVL) = 5
  ///  timer 3 interrupt group level (GLVL) = 0
  T3IC = 0x0054;

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
  ///  timer 4 works in reload mode 
  ///  any transition (rising and falling edge) of output toggle latch T3OTL
  T4CON = 0x0027;
  T4    = 0x09C3;  //  load timer 4 register



  // USER CODE BEGIN (GT1_Init,1)

  // USER CODE END


  T2R = 1;         //   set timer 2 run bit 
  T3R = 1;         //   set timer 3 run bit 
}


//****************************************************************************
// @Function      void GT1_viIsrTmr3(void) interrupt T3INT
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the GPT1 timer 3.
//                It is called up in the case of over or underflow of the 
//                timer 3 register.
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
// @Date          20.05.2012 17:17:06
//
//****************************************************************************

void GT1_viIsrTmr3(void) interrupt T3INT
{
  // USER CODE BEGIN (GT1_IsrTmr3,1)

	static char kanal = 0;
	static int index = 0;

	if (ADC_bConvReady())
	{
		
		sum[kanal] -= adBuff[kanal][index];
		adBuff[kanal][index] = ADC_uwReadConv() & 0x03FF;
		sum[kanal] += adBuff[kanal][index];

		if (kanal < (ADNUM - 1))
			kanal++;
		else
		{
			kanal = 0;
//			index = ++index%BUFLEN;


			if (index < (BUFLEN - 1))
				index++;
			else
				index = 0;						  	
		}

		ADC_vConfConv(FIXED, kanal);
		ADC_vStartConv();
	}

  // USER CODE END
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
// @Date          20.05.2012 17:17:06
//
//****************************************************************************

void GT1_viIsrTmr2(void) interrupt T2INT
{
  // USER CODE BEGIN (GT1_IsrTmr2,1)
	
	nTaste = P1H | 0x0F;
	if (nTaste != 0xFF) // Taste gedrueckt
	{
		if (iCnt == 0)
		{
			iCnt = 1;	
			consumed = 0;	
		}
		else // if (!consumed)
		{ 			
			tFlag = 1;
		}
	}
	else // Keine Taste gedrueckt
	{
		iCnt = 0;
		tFlag = 0;
	}

  // USER CODE END
}




// USER CODE BEGIN (GT1_General,3)

bit KeyDown(void)
{  	
	if (tFlag && !consumed)
	{
		consumed = 1;
		return 1;
	}

	return 0;
}

char GetKey(void)
{	
	switch(~nTaste & 0xFF)
	{	
		case 0x10:
			return '1';
		case 0x20:
			return '2';
		case 0x40:
			return '3';
		case 0x80:
			return '4';
		default: // dieser fall hat nicht einzutreten PUNKT
			return 0;
	}	
}


float fGibADmittel(char n)
{
	return (float) sum[n] / BUFLEN / 1023 * 5;
}

float fGibGewicht()
{
	int i;
	float summe = 0;
	for (i = 0; i < ADNUM; i++)
		summe += fGibADmittel(i);

	return summe / ADNUM;
}

// USER CODE END

