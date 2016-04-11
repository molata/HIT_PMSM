#ifndef HITHARDWARESETUPH
#define HITHARDWARESETUPH

void SCI2_setup();    //初始化SCI
void Clock_setup();   //初始化时钟
void CMT0_setuo();    // 初始化CMT0
void Exinterrupt_setup();   // 初始化外部中断
void GPT_setup();       //初始化GPT
void System_setup();    //系统初始化---后期需要修改
#endif