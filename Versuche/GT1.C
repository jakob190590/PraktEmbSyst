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
// @Date          30.04.2012 14:50:52
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
// @Date          30.04.2012 14:50:52
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
  T3    = 0x0000;  //  load timer 3 register

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
  ///  timer T4 is disabled
  T4CON = 0x0020;
  T4    = 0x09C4;  //  load timer 4 register



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
// @Date          30.04.2012 14:50:52
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
// @Date          30.04.2012 14:50:52
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
		case 0x70:
			return '1';
		case 0xB0:
			return '2';
		case 0xD0:
			return '3';
		case 0xE0:
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

