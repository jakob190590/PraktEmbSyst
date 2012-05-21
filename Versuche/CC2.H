//****************************************************************************
// @Module        CC2
// @Filename      CC2.H
// @Project       Prakt.dav
//----------------------------------------------------------------------------
// @Controller    Infineon C164CI-8E
//
// @Compiler      KEIL C166
//
// @Codegenerator DAvE 2-0-0
//
// @Description   This file contains all function prototypes and macros for
//                the Capture Compare unit 2.
//
//----------------------------------------------------------------------------
// @Date          21.05.2012 10:38:34
//
//****************************************************************************

//****************************************************************************
// @Prototypes of global functions
//****************************************************************************

void CC2_vInit(void);


// USER CODE BEGIN (CC2Header,1)

void StartTemp();

bit bTempDa();

float fGetTemp();

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

//****************************************************************************
// @Macro         CC2_vStartTmr(TimerNr)
//
//----------------------------------------------------------------------------
// @Description   This macro starts the selected CAPCOM timer.
//                The timer continues counting from where it stopped.
//                
//                The following definitions for TimerNr are available:
//                TIMER_7
//                TIMER_8
//
//----------------------------------------------------------------------------
// @Returnvalue   none
//
//----------------------------------------------------------------------------
// @Parameters    Name of the CAPCOM timer to be used
//
//----------------------------------------------------------------------------
// @Date          21.05.2012 10:38:34
//
//****************************************************************************

#define CC2_vStartTmr(TimerNr)  CC2_vStart(TimerNr,R)
#define CC2_vStart(TimerNr,R) TimerNr##R = 1


//****************************************************************************
// @Macro         CC2_vStopTmr(TimerNr)
//
//----------------------------------------------------------------------------
// @Description   This macro stops the selected CAPCOM timer.
//                The content of the timer register remains unchanged.
//                
//                The following definitions for TimerNr are available:
//                TIMER_7
//                TIMER_8
//
//----------------------------------------------------------------------------
// @Returnvalue   none
//
//----------------------------------------------------------------------------
// @Parameters    Name of the CAPCOM timer to be used
//
//----------------------------------------------------------------------------
// @Date          21.05.2012 10:38:34
//
//****************************************************************************

#define CC2_vStopTmr(TimerNr)  CC2_vStop(TimerNr,R)
#define CC2_vStop(TimerNr,R) TimerNr##R = 0                     



// USER CODE BEGIN (CC2Header,2)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

#define TIMER_7 T7
#define TIMER_8 T8

// Defines for enabled CAPCOM2 channels:

#define CC_18 CC18
#define CC_19 CC19


// USER CODE BEGIN (CC2Header,3)

// USER CODE END


//****************************************************************************
// @Interrupt Vectors
//****************************************************************************

#define CC19INT   0x33


// USER CODE BEGIN (CC2Header,4)

// USER CODE END

