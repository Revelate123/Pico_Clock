#include "pico/stdlib.h"
#include "time.h"
#include "EPD_2in13_V4.h"
#include "GUI_Paint.h"
#include "DEV_Config.h"
#include "Debug.h"
#include <stdlib.h>

int EPD_2in13_V4_test(void)
{

    Debug("EPD_2in13_V4_test Demo\r\n");
    if(DEV_Module_Init()!=0){
        return -1;
    }

    Debug("e-Paper Init and Clear...\r\n");
	EPD_2in13_V4_Init();
    EPD_2in13_V4_Clear();

    //Create a new image cache
    UBYTE *BlackImage;
    UWORD Imagesize = ((EPD_2in13_V4_WIDTH % 8 == 0)? (EPD_2in13_V4_WIDTH / 8 ): (EPD_2in13_V4_WIDTH / 8 + 1)) * EPD_2in13_V4_HEIGHT;
    if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        Debug("Failed to apply for black memory...\r\n");
        return -1;
    }
    Debug("Paint_NewImage\r\n");
    Paint_NewImage(BlackImage, EPD_2in13_V4_WIDTH, EPD_2in13_V4_HEIGHT, 90, WHITE);
	Paint_Clear(WHITE);





#if 1   //Partial refresh, example shows time
	Paint_NewImage(BlackImage, EPD_2in13_V4_WIDTH, EPD_2in13_V4_HEIGHT, 90, WHITE);  
    Debug("Partial refresh\r\n");
    Paint_SelectImage(BlackImage);
	
    PAINT_TIME sPaint_time;
    sPaint_time.Hour = 12;
    sPaint_time.Min = 34;
    sPaint_time.Sec = 56;
    while (true) {
        sPaint_time.Sec += 1;
        if (sPaint_time.Sec == 60) {
            sPaint_time.Min += 1;
            sPaint_time.Sec = 0;
            if (sPaint_time.Min == 60) {
                sPaint_time.Hour =  sPaint_time.Hour + 1;
                sPaint_time.Min = 0;
                if (sPaint_time.Hour == 24) {
                    sPaint_time.Hour = 0;
                    sPaint_time.Min = 0;
                    sPaint_time.Sec = 0;
                }
            }
        }
        Paint_ClearWindows(90, 50, 90 + Font24.Width * 7, 50 + Font20.Height, WHITE);
        Paint_DrawTime(90, 50, &sPaint_time, &Font24, WHITE, BLACK);

		EPD_2in13_V4_Display_Partial(BlackImage);
        DEV_Delay_ms(1000);//Analog clock 1s
    }
#endif

	Debug("Clear...\r\n");
	EPD_2in13_V4_Init();
    EPD_2in13_V4_Clear();
	
    Debug("Goto Sleep...\r\n");
    EPD_2in13_V4_Sleep();
    free(BlackImage);
    BlackImage = NULL;
    DEV_Delay_ms(2000);//important, at least 2s
    // close 5V
    Debug("close 5V, Module enters 0 power consumption ...\r\n");
    DEV_Module_Exit();
    return 0;
}
int main(void) {
	EPD_2in13_V4_test();


	return 0;
}
