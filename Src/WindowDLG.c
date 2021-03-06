/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.32                          *
*        Compiled Oct  8 2015, 11:59:02                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END

#include "DIALOG.h"
#include "tim.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0   (GUI_ID_USER + 0x00)
#define ID_BUTTON_0   (GUI_ID_USER + 0x01)
#define ID_GRAPH_0   (GUI_ID_USER + 0x04)
#define ID_SLIDER_0   (GUI_ID_USER + 0x05)


// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 240, 400, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "hello", ID_BUTTON_0, 60, 18, 200, 40, 0, 0x0, 0 },
  { GRAPH_CreateIndirect, "Graph", ID_GRAPH_0, 0, 70, 320, 120, 0, 0x0, 0 },
  { SLIDER_CreateIndirect, "Slider", ID_SLIDER_0, 0, 210, 320, 30, 0, 0x0, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};
/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  int     NCode;
  int     Id;
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_BUTTON_0: // Notifications sent by 'hello'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_SLIDER_0: // Notifications sent by 'Slider'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateWindow
*/
WM_HWIN CreateWindow(void);
WM_HWIN CreateWindow(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

// USER START (Optionally insert additional public code)
void MainTask2(void) {
	//CreateWindow();
	U8 i = 0;
	PROGBAR_Handle hProgBar;
	GUI_SetColor(GUI_WHITE);
	GUI_DispStringAt("Progress bar", 100, 50);
	hProgBar = PROGBAR_Create(10, 90, 380, 60, WM_CF_SHOW);
	GUI_SetOrientation(GUI_ROTATION_180);
	while (1) {
		PROGBAR_SetBarColor(hProgBar, 0, GUI_GREEN);
		PROGBAR_SetValue(hProgBar, i);
		GUI_Exec();
		GUI_Delay(200);
		i++;
		if (i > 100) {
			i = 0;
			//break;
		}
	}
}
void MainTask(void) {
	//CreateWindow();
	U8 i = 0;
	PROGBAR_Handle RProgBar,GProgBar,BProgBar;
	RProgBar = PROGBAR_Create(10, 25, 200, 50, WM_CF_SHOW);
	GProgBar = PROGBAR_Create(10, 95, 200, 50, WM_CF_SHOW);
	BProgBar = PROGBAR_Create(10, 165, 200, 50, WM_CF_SHOW);
	PROGBAR_SKINFLEX_PROPS pProps;
	PROGBAR_GetSkinFlexProps(&pProps,0);
	while (1) {
		//Red
		pProps.aColorLowerL[0]=0x0029D4;//
		pProps.aColorLowerL[1]=0x1C33E2;//
		pProps.aColorUpperL[0]=0xCDCDFF;//
		pProps.aColorUpperL[1]=0x9CACEE;//
		PROGBAR_SetSkinFlexProps(&pProps,0);
		PROGBAR_SetText(RProgBar, "");
		PROGBAR_SetValue(RProgBar, i);
		GUI_Exec();
		//Green
		pProps.aColorLowerL[0]=0x29d400;//
		pProps.aColorLowerL[1]=0x33e21c;//
		pProps.aColorUpperL[0]=0xcdffcd;//
		pProps.aColorUpperL[1]=0xacee9c;//
		PROGBAR_SetSkinFlexProps(&pProps,0);
		PROGBAR_SetText(GProgBar, "");
		PROGBAR_SetValue(GProgBar, i);
		GUI_Exec();
		//Blue
		pProps.aColorLowerL[0]=0xD42900;//
		pProps.aColorLowerL[1]=0xE2331C;//
		pProps.aColorUpperL[0]=0xFFCDCD;//
		pProps.aColorUpperL[1]=0xEEAC9C;//
		PROGBAR_SetSkinFlexProps(&pProps,0);
		PROGBAR_SetText(BProgBar, "");
		PROGBAR_SetValue(BProgBar, i);
		GUI_Exec();
		GUI_Delay(200);
		if(TIM3->CNT<0x7FFF){
			TIM3->CNT=0x7FFF;
		}
		if(TIM3->CNT>0x8063){
			TIM3->CNT=0x8063;
		}
		i=TIM3->CNT-0x7FFF;
	}
}
// USER END

/*************************** End of file ****************************/
