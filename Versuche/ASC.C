//****************************************************************************
// @Module        Asynchronous / Synchronous Serial Interface (ASC)
// @Filename      ASC.C
// @Project       Prakt.dav
//----------------------------------------------------------------------------
// @Controller    Infineon C164CI-8E
//
// @Compiler      KEIL C166
//
// @Codegenerator DAvE 2-0-0
//
// @Description   This file contains all functions that use the
//                Asynchronous / Synchronous Serial Interface.
//
//----------------------------------------------------------------------------
// @Date          20.05.2012 17:17:05
//
//****************************************************************************


//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"

// USER CODE BEGIN (ASC_General,1)

// USER CODE END


//***************************************************************************
// @Global Variables
//***************************************************************************

// USER CODE BEGIN (ASC_General,2)

// Gehoert ned ins Header file, sondern nur in dieses Modul
#define BUFSIZE 24

// 4 x 24 Zeichen Buffer
// Die ersten 4 Zeichen bleiben immer unveraendert
static char buffer[ROWCOUNT][BUFSIZE] = {
		{ '\x1B', 'O', 1, 1 },
		{ '\x1B', 'O', 1, 2 },
		{ '\x1B', 'O', 1, 3 },
		{ '\x1B', 'O', 1, 4 } };

static char index = 0;

static char next[ROWCOUNT];
static char size = 0;

static bit myIEN; // my Interrupt Enable (Transmit Buffer Interrupt)

// Forward Deklaration
static void SendChar();

// USER CODE END


//****************************************************************************
// @Function      void ASC_vInit(void)
//
//----------------------------------------------------------------------------
// @Description   This function initializes the ASC component. It effects all
//                necessary configurations of the SFR, depending on the selected
//                operating mode. The configuration determines whether the ASC
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
// @Date          20.05.2012 17:17:05
//
//****************************************************************************

void ASC_vInit(void)
{
  ///  8-bit data asynchronous operation
  ///  two stop bits
  ///  divide clock by reload value + constant
  ///  receiver disabled
  S0CON  = 0x0009;

  //   ASC baudrate reload register
  ///  baudrate =  9615,38 Baud
  S0BG   = 0x0040;

  ///  enable transmit buffer interrupt
  ///  transmit buffer interrupt priority level(ILVL) = 4
  ///  transmit buffer interrupt group level (GLVL) = 1
  S0TBIC = 0x0051;

  P3    |= 0x0400;    //  set P3.10 output latch (TXD0)
  DP3   |= 0x0400;    /// set P3.10 direction control (TXD0 output)


  // USER CODE BEGIN (ASC_Init,1)

  // USER CODE END

  S0R    = 1;         //  enable baudrate generator
}


//****************************************************************************
// @Function      void ASC_vSendData(uword Data)
//
//----------------------------------------------------------------------------
// @Description   This function writes a send data initialization word into
//                the S0TBUF register.
//                
//                Note:
//                In a multiprocessor system the master with this function
//                has the possibility to send data to the selected slave. To
//                achieve this, the 9th bit must set on zero.
//
//----------------------------------------------------------------------------
// @Returnvalue   none
//
//----------------------------------------------------------------------------
// @Parameters    data to be written into the S0TBUF register
//
//----------------------------------------------------------------------------
// @Date          20.05.2012 17:17:05
//
//****************************************************************************

void ASC_vSendData(uword Data)
{
  S0TBIR = 0;           // reset transmit buffer interrupt request flag
  S0TBUF = Data;        // load transmit buffer register
}


//****************************************************************************
// @Function      void ASC_viIsrTxBuf(void) interrupt S0TBINT
//
//----------------------------------------------------------------------------
// @Description   This is the transmit buffer interrupt service routine for
//                the ASC0. It is called if the content of the TX-buffer has
//                been loaded into the TX-shift register.
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
// @Date          20.05.2012 17:17:05
//
//****************************************************************************

void ASC_viIsrTxBuf(void) interrupt S0TBINT
{
  // USER CODE BEGIN (ASC_IsrTxBuf,1)

	if (myIEN)
		SendChar();

  // USER CODE END
}




// USER CODE BEGIN (ASC_General,3)

void DoPrintZ(int iZnr, char *pBuf)
{
	char *text = &buffer[--iZnr][4]; // iZnr als index anpassen
	int i = 0;

	// signalisieren, dass naechster Interrupt erst
	// mal kein weiteres zeichen mehr senden soll!
	myIEN = 0;
  
  
	// Argument in buffer uebertragen
	while (pBuf[i] && i < COLCOUNT)
	{
		text[i] = pBuf[i];
		i++;
	}
  
	// Mit Leerzeichen auffuellen
	while (i < COLCOUNT)
		text[i++] = ' ';



	if (size == 0) // momentan nichts zu senden
	{
		*next = (char) iZnr;
		size = 1;
	}
	else if (*next == iZnr) // zeile momentan in bearbeitung
	{
		if (index >= 4) // escape-sequenz schon komplett hinter sich gelassen und schon im text		
			index = 0; // index zuruecksetzen
	}
	else
 	{
		for (i = 1; i < size; i++)
			if (next[i] == iZnr)
				break;
		if (i == size) // nicht gefunden
			next[size++] = (char) iZnr; // hinten anhaengen
	}

	myIEN = 1;
	SendChar();

}

static void SendChar()
{
	if (size && index < BUFSIZE)
	{	
		char c = buffer[*next][index++];
		ASC_vSendData(c);
		if (index == BUFSIZE)
		{
			memmove(next, next + 1, --size);		
			index = 0;
		}
	}
}

void ClrScr()
{
	size = 0;
	ASC_vSendData('\x0C');
}

// USER CODE END

