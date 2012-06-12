//****************************************************************************
// @Module        Interrupt Controller
// @Filename      INT.H
// @Project       Prakt.dav
//----------------------------------------------------------------------------
// @Controller    Infineon C164CI-8E
//
// @Compiler      KEIL C166
//
// @Codegenerator DAvE 2-0-0
//
// @Description   This file contains all function prototypes and macros for
//                the Interrupt Controller.
//
//----------------------------------------------------------------------------
// @Date          12.06.2012 15:16:59
//
//****************************************************************************

//****************************************************************************
// @Prototypes of global functions
//****************************************************************************



// USER CODE BEGIN (Header,1)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

//****************************************************************************
// @Macro         INT_vSetPecCount(Nr,Value)
//
//----------------------------------------------------------------------------
// @Description   This macro loads the COUNT field of PECCx with the parameter
//                value.
//                During each PEC transfer this counter is decremented
//                (if 0xFF > COUNT > 0). If the counter reaches 0, the normal
//                interrupt service routine is executed, in which the PEC
//                counter then can be reloaded with this function. If COUNT
//                is set at 0xFF the PEC counter is switched off.
//
//----------------------------------------------------------------------------
// @Returnvalue   none
//
//----------------------------------------------------------------------------
// @Parameters    number of PEC channel (0-7) whose count value is to be changed
// @Parameters    8-bit value for the PEC transfer counter field (0 .. 255)
//
//----------------------------------------------------------------------------
// @Date          12.06.2012 15:16:59
//
//****************************************************************************

#define INT_vSetPecCount(Nr,Value) PECC##Nr = (PECC##Nr & 0xFF00) | Value


//****************************************************************************
// @Macro         INT_vSetPecDesP(Nr,Address)
//
//----------------------------------------------------------------------------
// @Description   This macro sets the destination pointer for the 
//                chosen PEC channel.
//                Note:
//                The address of the variable must be in segment 0 (data
//                page 0 through 3).
//
//----------------------------------------------------------------------------
// @Returnvalue   none
//
//----------------------------------------------------------------------------
// @Parameters    number of PEC channel (0-7) whose source address is to be set
// @Parameters    destination address of the chosen PEC channel
//
//----------------------------------------------------------------------------
// @Date          12.06.2012 15:16:59
//
//****************************************************************************

#define INT_vSetPecDesP(Nr,Address)   DSTP##Nr = _sof_(Address)



// USER CODE BEGIN (Header,2)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************



// USER CODE BEGIN (Header,3)

// USER CODE END


/****************************************************************************
* @Interrupt vectors                                                         
****************************************************************************/

#define CC8INT    0x18
#define CC9INT    0x19
#define CC10INT   0x1A
#define CC11INT   0x1B


// USER CODE BEGIN (Header,4)

// USER CODE END


