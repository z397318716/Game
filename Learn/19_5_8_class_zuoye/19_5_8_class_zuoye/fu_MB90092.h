/*********************************************************************************************************
宏定义
********************************************************************************************************/
#define UCHAR unsigned char
#define UINT  unsigned int

//character color,normal mode and extended graphics mode
#define C_COLOR_BLACK   0x00  //color mode
#define C_COLOR_BLUE    0x01
#define C_COLOR_RED     0x02
#define C_COLOR_MAGENTA 0x03
#define C_COLOR_GREEN   0x04
#define C_COLOR_CYAN    0x05
#define C_COLOR_YELLOW  0x06
#define C_COLOR_WHITE   0x07

#define C_COLOR_GRAY0   0x00 //Monochrome mode,black
#define C_COLOR_GRAY1   0x10
#define C_COLOR_GRAY2   0x20
#define C_COLOR_GRAY3   0x30
#define C_COLOR_GRAY4   0x40
#define C_COLOR_GRAY5   0x50
#define C_COLOR_GRAY6   0x60
#define C_COLOR_GRAY7   0x70 //white

//background color,normal mode
#define B_COLOR_BLACK   0x00  //color mode
#define B_COLOR_BLUE    0x01
#define B_COLOR_RED     0x02
#define B_COLOR_MAGENTA 0x03
#define B_COLOR_GREEN   0x04
#define B_COLOR_CYAN    0x05
#define B_COLOR_YELLOW  0x06
#define B_COLOR_WHITE   0x07

#define B_COLOR_GRAY0   0x00 //Monochrome mode,black
#define B_COLOR_GRAY1   0x01
#define B_COLOR_GRAY2   0x02
#define B_COLOR_GRAY3   0x03
#define B_COLOR_GRAY4   0x04
#define B_COLOR_GRAY5   0x05
#define B_COLOR_GRAY6   0x06
#define B_COLOR_GRAY7   0x07 //white

//Synchronization control
#define SYN_INTERNAL    0x00
#define SYN_EXTERNAL    0x04
#define DEMO_SUM        0x07

/*********************************************************************************************************
函数声明
********************************************************************************************************/
void Delay_ms(UINT);
void MB90092_WriteByte(UCHAR);
void MB90092_ClearXY(UCHAR, UCHAR);
void MB90092_ClearRow(UCHAR);
void MB90092_ClearScreen();
void MB90092_DisChar(UCHAR, UCHAR, int, UCHAR, UCHAR, UCHAR, UCHAR);
void MB90092_DisColor(UCHAR);
void MainScreen_Init(UCHAR);
UCHAR ScanKey();

/*********************************************************************************************************
变量声明
********************************************************************************************************/
sbit CS = P1 ^ 4;
sbit CLK = P1 ^ 5;
sbit SIN = P1 ^ 6;

sbit EXT = P3 ^ 3;
sbit INT = P3 ^ 5;
sbit MODE = P3 ^ 2;

sbit ACC_0 = ACC ^ 0;