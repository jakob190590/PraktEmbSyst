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
// @Date          12.06.2012 15:16:59
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
// @Date          12.06.2012 15:16:59
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
// @Date          12.06.2012 15:16:59
//
//****************************************************************************

#define CC2_vStopTmr(TimerNr)  CC2_vStop(TimerNr,R)
#define CC2_vStop(TimerNr,R) TimerNr##R = 0                     


//****************************************************************************
// @Macro         CC2_vSetCCxReg(RegName,Value)
//
//----------------------------------------------------------------------------
// @Description   This macro loads the selected capture/compare register
//                with the parameter Value.
//                
//                The following definitions are available for RegName
//                (only for enabled CAPCOM channels):
//                0 - 0 (see @Defines in header file)
//
//----------------------------------------------------------------------------
// @Returnvalue   none
//
//----------------------------------------------------------------------------
// @Parameters    Name of the CAPCOM channel to be used
// @Parameters    16-bit Value with which the CCx register is to be loaded
//
//----------------------------------------------------------------------------
// @Date          12.06.2012 15:16:59
//
//****************************************************************************

#define CC2_vSetCCxReg(RegName,Value) RegName = Value



// USER CODE BEGIN (CC2Header,2)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

#define TIMER_7 T7
#define TIMER_8 T8

// Defines for enabled CAPCOM2 channels:

#define CC_16 CC16
#define CC_17 CC17
#define CC_18 CC18
#define CC_19 CC19


// USER CODE BEGIN (CC2Header,3)

// Timer 7 Startwert, dass er 5000 * 0.4 us = 2 ms läuft!
#define T7RELOAD 0xEC77

// USER CODE END


//****************************************************************************
// @Interrupt Vectors
//****************************************************************************

#define T7INT     0x3D
#define CC16INT   0x30
#define CC17INT   0x31
#define CC18INT   0x32
#define CC19INT   0x33


// USER CODE BEGIN (CC2Header,4)

// USER CODE END

