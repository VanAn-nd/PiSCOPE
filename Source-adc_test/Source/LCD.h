#include <stdint.h>
#include "pico/stdlib.h"

#define WHITE      0xFFFF
#define BLACK      0x0000
#define BLUE       0x001F
#define RED        0xF800
#define MAGENTA    0xF81F
#define GREEN      0x07E0
#define CYAN       0x7FFF
#define YELLOW     0xFFE0
#define GRAY       0X8430
#define BRED       0XF81F
#define GRED       0XFFE0
#define GBLUE      0X07FF
#define BROWN      0XBC40
#define BRRED      0XFC07
#define DARKBLUE   0X01CF
#define LIGHTBLUE  0X7D7C
#define GRAYBLUE   0X5458
#define LIGHTGREEN 0X841F
#define LGRAY      0XC618
#define LGRAYBLUE  0XA651
#define LBBLUE     0X2B12

#define ST7789_SWRESET 0x01
#define ST7789_SLPOUT  0x11
#define ST7789_COLMOD  0x3A
#define ST7789_MADCTL  0x36
#define ST7789_CASET   0x2A
#define ST7789_RASET   0x2B
#define ST7789_RAMWR   0x2C
#define ST7789_INVOFF  0x20
#define ST7789_INVON   0x21
#define ST7789_NORON   0x13
#define ST7789_DISPON  0x29
#define ST7789_DISPOFF 0x28
#define ST7789_PWR_CTRL_A 0xCB
#define ST7789_PWR_CTRL_B 0xCF
#define ST7789_DRIVER_TIMMING_A 0xE8
#define ST7789_DRIVER_TIMMING_B 0xEA
#define ST7789_MADCTL_MY  0x80
#define ST7789_MADCTL_MX  0x40
#define ST7789_MADCTL_MV  0x20
#define ST7789_MADCTL_ML  0x10
#define ST7789_MADCTL_RGB 0x00
#define ST7789_WIDTH 240
#define ST7789_HEIGHT 240

#define ILI9341_FRAMERATE_61_HZ 0x1F
#define ILI9341_FRAMERATE_63_HZ 0x1E
#define ILI9341_FRAMERATE_65_HZ 0x1D
#define ILI9341_FRAMERATE_68_HZ 0x1C
#define ILI9341_FRAMERATE_70_HZ 0x1B
#define ILI9341_FRAMERATE_73_HZ 0x1A
#define ILI9341_FRAMERATE_76_HZ 0x19
#define ILI9341_FRAMERATE_79_HZ 0x18
#define ILI9341_FRAMERATE_83_HZ 0x17
#define ILI9341_FRAMERATE_86_HZ 0x16
#define ILI9341_FRAMERATE_90_HZ 0x15
#define ILI9341_FRAMERATE_95_HZ 0x14
#define ILI9341_FRAMERATE_100_HZ 0x13
#define ILI9341_FRAMERATE_106_HZ 0x12
#define ILI9341_FRAMERATE_112_HZ 0x11
#define ILI9341_FRAMERATE_119_HZ 0x10

#define LCD_WIDTH  320
#define LCD_HEIGHT 240


#define SERIAL_CLK_DIV 2.f
//#define ST7789





#ifdef ST7789
    #define LCD_WIDTH  320
    #define LCD_HEIGHT 240
    #define BGR        0x012f
#else
    #define LCD_WIDTH  320
    #define LCD_HEIGHT 240
    #define BGR        0x19a9
#endif

typedef struct
{
    const uint8_t width;
    const uint8_t height;
    const uint8_t dot;
    const uint16_t *data;
} FontDef;

extern FontDef Font_7x10;
extern FontDef Font_11x18;
extern FontDef Font_16x26;

#define PIN_DIN 16
#define PIN_CLK 17
#define LCD_DC  18
#define LCD_RST 19


void LCD_Init();
void LCD_DrawPixel(uint16_t x, uint16_t y, uint16_t color);
void LCD_WriteChar(uint16_t x, uint16_t y, char ch, FontDef font, uint16_t color, uint16_t bgcolor);
void LCD_WriteString(uint16_t x, uint16_t y, const char *str, FontDef font, uint16_t color, uint16_t bgcolor);
void LCD_WriteNumber(uint16_t x, uint16_t y, int num, uint16_t color, uint16_t bgcolor);
void LCD_FillScreen(uint16_t color);
void LCD_FillRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
void LCD_DrawFastVLine(int16_t x, int16_t y1, int16_t y2, uint16_t color);
void LCD_DrawFastHLine(int16_t x1, int16_t x2, int16_t y, uint16_t color);
