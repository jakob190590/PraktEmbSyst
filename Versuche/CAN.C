//****************************************************************************
// @Module        CAN
// @Filename      CAN.C
// @Project       Prakt.dav
//----------------------------------------------------------------------------
// @Controller    Infineon C164CI-8E
//
// @Compiler      KEIL C166
//
// @Codegenerator DAvE 2-0-0
//
// @Description   This file contains all functions that use the CAN peripheral.
//                
//
//----------------------------------------------------------------------------
// @Date          12.06.2012 15:16:59
//
//****************************************************************************


//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"


// USER CODE BEGIN (CAN_General,1)

// USER CODE END


//***************************************************************************
// @Global Variables
//***************************************************************************

// USER CODE BEGIN (CAN_General,2)

union typ_uMy{
		char cArFrm[8];
		float fFrm;
	};
typedef union typ_uMy t_uMyDates;

static bit bCanFlag;

TCAN_Obj sRcvMyObj;
t_uMyDates uMyRcvDates, uMyTrmDates;

// USER CODE END


//****************************************************************************
// @Function      void CAN_vInit(void)
//
//----------------------------------------------------------------------------
// @Description   This function initializes the CAN component. It effects all
//                necessary configurations of the SFR, depending on the selected
//                operating mode. The configuration determines whether the CAN
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
// @Date          12.06.2012 15:16:59
//
//****************************************************************************

void CAN_vInit(void)
{

  //  ------------ CAN Control/Status Register --------------
  //  start the initialization of the CAN Modul

  BFLD(DP4,0x0020,0x0000);     // set P4.5 (CAN_RxD) to alternate input
                               // P4.6 (CAN_TxD) is set to output by hardware
  C1CSR  = 0x0041;  // set INIT and CCE

  ///  ------------ Bit Timing Register ---------------------
  /// baudrate =  100,000 KBaud
  /// there are 5 time quanta before sample point
  /// there are 4 time quanta after sample point
  /// the (re)synchronization jump width is 2 time quanta
  C1BTR  = 0x3449;  // set Bit Timing Register

  C1GMS  = 0xE0FF;  // set Global Mask Short Register

  C1UGML = 0xFFFF;  // set Upper Global Mask Long Register

  C1LGML = 0xF8FF;  // set Lower Global Mask Long Register


  //  ------------------------------------------------------------------------
  /// ----------------- Configure Message Object 1 ---------------------------
  //  ------------------------------------------------------------------------
  /// Message object 1 is valid
  /// enable receive interrupt
  CAN_OBJ[0].MCR  = 0x5599;    // set Message Control Register

  /// message direction is receive
  /// standard 11-bit identifier
  CAN_OBJ[0].MCFG = 0x00;      // set Message Configuration Register

  CAN_OBJ[0].UAR  = 0x6060;    // set Upper Arbitration Register
  CAN_OBJ[0].LAR  = 0x0000;    // set Lower Arbitration Register



  //  ------------------------------------------------------------------------
  /// ----------------- Configure Message Object 2 ---------------------------
  //  ------------------------------------------------------------------------
  /// Message object 2 is valid
  CAN_OBJ[1].MCR  = 0x5695;    // set Message Control Register

  /// message direction is transmit
  /// standard 11-bit identifier
  /// 8 valid data bytes
  CAN_OBJ[1].MCFG = 0x88;      // set Message Configuration Register

  CAN_OBJ[1].UAR  = 0x4042;    // set Upper Arbitration Register
  CAN_OBJ[1].LAR  = 0x0000;    // set Lower Arbitration Register

  CAN_OBJ[1].Data[0] = 0x00;   // set data byte 0
  CAN_OBJ[1].Data[1] = 0x00;   // set data byte 1
  CAN_OBJ[1].Data[2] = 0x00;   // set data byte 2
  CAN_OBJ[1].Data[3] = 0x00;   // set data byte 3
  CAN_OBJ[1].Data[4] = 0x00;   // set data byte 4
  CAN_OBJ[1].Data[5] = 0x00;   // set data byte 5
  CAN_OBJ[1].Data[6] = 0x00;   // set data byte 6
  CAN_OBJ[1].Data[7] = 0x00;   // set data byte 7


  //  ------------------------------------------------------------------------
  /// ----------------- Configure Message Object 3 ---------------------------
  //  ------------------------------------------------------------------------
  /// message object 3 is not valid
  CAN_OBJ[2].MCR  = 0x5555;    // set Message Control Register


  //  ------------------------------------------------------------------------
  /// ----------------- Configure Message Object 4 ---------------------------
  //  ------------------------------------------------------------------------
  /// message object 4 is not valid
  CAN_OBJ[3].MCR  = 0x5555;    // set Message Control Register


  //  ------------------------------------------------------------------------
  /// ----------------- Configure Message Object 5 ---------------------------
  //  ------------------------------------------------------------------------
  /// message object 5 is not valid
  CAN_OBJ[4].MCR  = 0x5555;    // set Message Control Register


  //  ------------------------------------------------------------------------
  /// ----------------- Configure Message Object 6 ---------------------------
  //  ------------------------------------------------------------------------
  /// message object 6 is not valid
  CAN_OBJ[5].MCR  = 0x5555;    // set Message Control Register


  //  ------------------------------------------------------------------------
  /// ----------------- Configure Message Object 7 ---------------------------
  //  ------------------------------------------------------------------------
  /// message object 7 is not valid
  CAN_OBJ[6].MCR  = 0x5555;    // set Message Control Register


  //  ------------------------------------------------------------------------
  /// ----------------- Configure Message Object 8 ---------------------------
  //  ------------------------------------------------------------------------
  /// message object 8 is not valid
  CAN_OBJ[7].MCR  = 0x5555;    // set Message Control Register


  //  ------------------------------------------------------------------------
  /// ----------------- Configure Message Object 9 ---------------------------
  //  ------------------------------------------------------------------------
  /// message object 9 is not valid
  CAN_OBJ[8].MCR  = 0x5555;    // set Message Control Register


  //  ------------------------------------------------------------------------
  /// ----------------- Configure Message Object 10 ---------------------------
  //  ------------------------------------------------------------------------
  /// message object 10 is not valid
  CAN_OBJ[9].MCR  = 0x5555;    // set Message Control Register


  //  ------------------------------------------------------------------------
  /// ----------------- Configure Message Object 11 ---------------------------
  //  ------------------------------------------------------------------------
  /// message object 11 is not valid
  CAN_OBJ[10].MCR  = 0x5555;    // set Message Control Register


  //  ------------------------------------------------------------------------
  /// ----------------- Configure Message Object 12 ---------------------------
  //  ------------------------------------------------------------------------
  /// message object 12 is not valid
  CAN_OBJ[11].MCR  = 0x5555;    // set Message Control Register


  //  ------------------------------------------------------------------------
  /// ----------------- Configure Message Object 13 ---------------------------
  //  ------------------------------------------------------------------------
  /// message object 13 is not valid
  CAN_OBJ[12].MCR  = 0x5555;    // set Message Control Register


  //  ------------------------------------------------------------------------
  /// ----------------- Configure Message Object 14 ---------------------------
  //  ------------------------------------------------------------------------
  /// message object 14 is not valid
  CAN_OBJ[13].MCR  = 0x5555;    // set Message Control Register


  //  ------------------------------------------------------------------------
  /// ----------------- Configure Message Object 15 ---------------------------
  //  ------------------------------------------------------------------------
  /// message object 15 is not valid
  CAN_OBJ[14].MCR  = 0x5555;    // set Message Control Register


  ///  enable CAN interrupt
  ///  CAN interrupt priority level(ILVL) = 3
  ///  CAN interrupt group level (GLVL) = 1
  XP0IC = 0x004D;


  // USER CODE BEGIN (CAN_Init,0)

  // USER CODE END

  /// ------------ CAN Control/Status Register --------------
  //  reset CCE and INIT
  /// enable interrupt generation from CAN Modul
  C1CSR = 0x0002;


  // USER CODE BEGIN (CAN_Init,1)

  // USER CODE END

}


//****************************************************************************
// @Function      void CAN_viIsr(void) interrupt XP0INT
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the CAN controller.
//                Depending on the configuration it is executed if:
//                - the busoff or the error warning status is reached 
//                  (EIE is set)
//                - a message has been sent or received successfully or a bus 
//                  error occurred (SIE is set)
//                - the bit INTPND (interrupt pending) in one of the message
//                  object control-registers is set (at Tx or Rx)
//                
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
// @Date          12.06.2012 15:16:59
//
//****************************************************************************

void CAN_viIsr(void) interrupt XP0INT
{
  // USER CODE BEGIN (CAN_Isr,Var)

  // USER CODE END

  uword uwIntID;

  while (uwIntID = C1IR & 0x00ff)
  {
    switch (uwIntID & 0x00ff)
    {

     case 3: // Message Object 1 Interrupt

              if ((CAN_OBJ[0].MCR & 0x0300) == 0x0200)    // if NEWDAT set
              {

                if ((CAN_OBJ[0].MCR & 0x0c00) == 0x0800)  // if MSGLST set
                {
                  // Indicates that the CAN controller has stored a new 
                  // message into this object, while NEWDAT was still set,
                  // ie. the previously stored message is lost.

                  CAN_OBJ[0].MCR = 0xf7ff;  // reset MSGLST

                  // USER CODE BEGIN (CAN_IsrMsgLst,1)

                  // USER CODE END
                }
                else
                {
                  // The CAN controller has stored a new message
                  // into this object.

                  // USER CODE BEGIN (CAN_IsrRxOk,1)

					CAN_vGetMsgObj(1, &sRcvMyObj);
					bCanFlag = 1;

                  // USER CODE END
                }

                CAN_OBJ[0].MCR = 0xfdfd;  // reset NEWDAT, INTPND
              }

              break;

     default:
              break;
    }  // end switch()
  }    // end while
}      // end ISR


//****************************************************************************
// @Function      void CAN_vGetMsgObj(ubyte ObjNr, TCAN_Obj *pstObj)
//
//----------------------------------------------------------------------------
// @Description   This function fills the forwarded SW message object with the 
//                content of the chosen HW message object.
//                
//                The structure of the SW message object is defined in the 
//                header file CAN.H (see TCAN_Obj).
//
//----------------------------------------------------------------------------
// @Returnvalue   none
//
//----------------------------------------------------------------------------
// @Parameters    Number of the message object to be read (1-15)
// @Parameters    Pointer on a message object to be filled by this function.
//
//----------------------------------------------------------------------------
// @Date          12.06.2012 15:16:59
//
//****************************************************************************

void CAN_vGetMsgObj(ubyte ObjNr, TCAN_Obj *pstObj)
{
  ubyte i;
  ulong v;

  pstObj->ubMsgCfg = CAN_OBJ[ObjNr-1].MCFG;

  v = 0;
  if(CAN_OBJ[ObjNr-1].MCFG & 0x04)  // extended identifier
  {
    v += (CAN_OBJ[ObjNr-1].LAR & 0xf800) >> 11;  // ID  4.. 0
    v += (CAN_OBJ[ObjNr-1].LAR & 0x00ff) <<  5;  // ID 12.. 5
    v += (ulong)(CAN_OBJ[ObjNr-1].UAR & 0xff00) <<  5;  // ID 13..20
    v += (ulong)(CAN_OBJ[ObjNr-1].UAR & 0x00ff) << 21;  // ID 21..28
  }
  else                              // standard identifier 
  {
    v += (CAN_OBJ[ObjNr-1].UAR & 0xe000) >> 13;  // ID 18..20
    v += (CAN_OBJ[ObjNr-1].UAR & 0x00ff) <<  3;  // ID 21..28
  }
  pstObj->ulArbitr = v;

  for(i = 0; i < (CAN_OBJ[ObjNr-1].MCFG & 0xf0) >> 4; i++)
  {
    pstObj->ubData[i] = CAN_OBJ[ObjNr-1].Data[i];
  }

  pstObj->ubUser = CAN_OBJ[ObjNr-1].Customer;

  if(ObjNr < 15 || (CAN_OBJ[ObjNr-1].MCR & 0x000c) != 0x0008)
  {
    CAN_OBJ[ObjNr-1].MCR = 0xfdff;  // reset NEWDAT
  }
}


//****************************************************************************
// @Function      bit CAN_bRequestMsgObj(ubyte ObjNr)
//
//----------------------------------------------------------------------------
// @Description   If a TRANSMIT OBJECT is to be reconfigured it must first be
//                accessed. The access to the transmit object is exclusive.
//                This function checks whether the choosen message object is
//                still executing a transmit request, or if the object can 
//                be accessed exclusively.
//                After the message object is reserved, it can be reconfigured
//                by using the function CAN_vConfigMsgObj or CAN_vLoadData.
//                Both functions enable access to the object for the CAN
//                controller.
//                By calling the function CAN_vTransmit transfering of data
//                is started.
//
//----------------------------------------------------------------------------
// @Returnvalue   0 message object is busy (a transfer is actice), else 1
//
//----------------------------------------------------------------------------
// @Parameters    Number of the message object (1-14)
//
//----------------------------------------------------------------------------
// @Date          12.06.2012 15:16:59
//
//****************************************************************************

bit CAN_bRequestMsgObj(ubyte ObjNr)
{
  bit bReturn;

  bReturn = 0;
  if((CAN_OBJ[ObjNr-1].MCR & 0x3000) == 0x1000)  // if reset TXRQ 
  {
    CAN_OBJ[ObjNr-1].MCR = 0xfbff;               // set CPUUPD 
    bReturn = 1;
  }
  return(bReturn);
}


//****************************************************************************
// @Function      void CAN_vTransmit(ubyte ObjNr)
//
//----------------------------------------------------------------------------
// @Description   This function triggers the CAN controller to send the 
//                selected message.
//                If the selected message object is a TRANSMIT OBJECT then 
//                this function triggers the sending of a data frame.
//                If however the selected message object is a RECEIVE OBJECT
//                this function triggers the sending of a remote frame.
//
//----------------------------------------------------------------------------
// @Returnvalue   none
//
//----------------------------------------------------------------------------
// @Parameters    Number of the message object to be sent (1-14)
//
//----------------------------------------------------------------------------
// @Date          12.06.2012 15:16:59
//
//****************************************************************************

void CAN_vTransmit(ubyte ObjNr)
{
  CAN_OBJ[ObjNr-1].MCR = 0xe7ff;  // set TXRQ,reset CPUUPD
}


//****************************************************************************
// @Function      void CAN_vLoadData(ubyte ObjNr, ubyte *pubData)
//
//----------------------------------------------------------------------------
// @Description   If a harware TRANSMIT OBJECT has to be loaded with data
//                but not with a new identifier, this function may be used
//                instead of the function CAN_vConfigMsgObj.
//                The message object should be accessed by calling the function
//                CAN_bRequestMsgObj before calling this function. This
//                prevents the CAN controller from working with invalid data.
//
//----------------------------------------------------------------------------
// @Returnvalue   none
//
//----------------------------------------------------------------------------
// @Parameters    Number of the message object to be configured (1-15)
// @Parameters    Pointer on a data buffer
//
//----------------------------------------------------------------------------
// @Date          12.06.2012 15:16:59
//
//****************************************************************************

void CAN_vLoadData(ubyte ObjNr, ubyte *pubData)
{
  ubyte i;

  CAN_OBJ[ObjNr-1].MCR = 0xfaff;  // set CPUUPD and NEWDAT

  for(i = 0; i < (CAN_OBJ[ObjNr-1].MCFG & 0xf0) >> 4; i++)
  {
    CAN_OBJ[ObjNr-1].Data[i] = *(pubData++);
  }

  CAN_OBJ[ObjNr-1].MCR = 0xf7ff;  // reset CPUUPD
}




// USER CODE BEGIN (CAN_General,3)
			  
float fGiveCanValue() {
	//int i;
	memcpy(uMyRcvDates.cArFrm, sRcvMyObj.ubData, 8);
	//  uMyRcvDates.cArFrm[i] = sRcvMyDates.ubData[i];	
	bCanFlag = 0;
	return uMyRcvDates.fFrm;
}

void vMakeCanValue(float fWert) {
	if(CAN_bRequestMsgObj(2)) {		//ist Übertragung möglich?
		uMyTrmDates.fFrm = fWert;
		CAN_vLoadData(2, uMyTrmDates.cArFrm);
		CAN_vTransmit(2);
	}
}

bit bCanRok(void) {
	return bCanFlag;
}

// USER CODE END


