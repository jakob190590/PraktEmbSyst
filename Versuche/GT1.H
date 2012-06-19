//****************************************************************************
// @Module        General Purpose Timer Unit 1
// @Filename      GT1.H
// @Project       Prakt.dav
//----------------------------------------------------------------------------
// @Controller    Infineon C164CI-8E
//
// @Compiler      KEIL C166
//
// @Codegenerator DAvE 2-0-0
//
// @Description   This file contains all function prototypes and macros for
//                the GPT1 unit.
//
//----------------------------------------------------------------------------
// @Date          05.06.2012 15:19:15
//
//****************************************************************************

//****************************************************************************
// @Prototypes of global functions
//****************************************************************************

void GT1_vInit(void);


// USER CODE BEGIN (Header,1)

bit KeyDown(void);
char GetKey(void);


float fGibADmittel(char);
float fGibGewicht();

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************


// USER CODE BEGIN (Header,2)

// USER CODE END


//***************************************************************************
// @Defines
//***************************************************************************

#define TIMER_2 T2
#define TIMER_3 T3
#define TIMER_4 T4


// USER CODE BEGIN (Header,3)

// USER CODE END


//***************************************************************************
// @Interrupt vectors
//***************************************************************************

#define T2INT   0x22
#define T3INT   0x23


// USER CODE BEGIN (Header,4)

// USER CODE END


