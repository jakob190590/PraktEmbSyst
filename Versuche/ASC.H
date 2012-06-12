//****************************************************************************
// @Module        Asynchronous / Synchronous Serial Interface (ASC)
// @Filename      ASC.H
// @Project       Prakt.dav
//----------------------------------------------------------------------------
// @Controller    Infineon C164CI-8E
//
// @Compiler      KEIL C166
//
// @Codegenerator DAvE 2-0-0
//
// @Description   This file contains all function prototypes and macros for
//                the Asynchronous / Synchronous Serial Interface.
//
//----------------------------------------------------------------------------
// @Date          12.06.2012 15:16:59
//
//****************************************************************************

//****************************************************************************
// @Prototypes of global functions
//****************************************************************************

void ASC_vInit(void);
void ASC_vSendData(uword Data);


// USER CODE BEGIN (ASCHeader,1)

void DoPrintZ(int iZnr, char *pBuf);

void ClrScr();

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************


// USER CODE BEGIN (ASCHeader,2)

// USER CODE END


//***************************************************************************
// @Defines
//***************************************************************************


// USER CODE BEGIN (ASCHeader,4)

#define COLCOUNT 20
#define ROWCOUNT 4

// USER CODE END


//****************************************************************************
// @Interrupt Vectors
//****************************************************************************

#define S0TBINT   0x47


// USER CODE BEGIN (ASCHeader,3)

// USER CODE END


