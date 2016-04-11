#include "Serial.h"
#include "iodefine.h"
#include "HIT_common.h"
#include <string.h>
extern ST_SERIAL_DECODE stSerial_decode;
extern ST_SERIAL_DATA stSerial_data;     // 基本的东西
extern uint u32Error_count;              // 错误计数
extern uchar ucSerial_send_status;     // 判断到底要给上位机回复什么指令的控制位
extern uchar ucShake_success;          // 握手是否成功的标志量

uchar ucSerial_byte_len = 0;
uchar ucSerial_rec_shake[16] = {0};    //从上位机获取的握手信息
uint u32Package_count = 0;            // 包计数           
uint uiRec_bytes_num = 0;                  // 控制接收的字节数
uchar ucDataBytes_Len = 0;                 // 接收的数据位长度   ？？ 需要修改的变量
uchar ucSerial_shake_send_dataBits[2] = {2, 0};   // 发送的数据： 握手指令
uchar ucSerial_shake_send_bytes[6] = {0};      // 握手的所有字节数组
uchar ucSerial_send_dataBits[22] = {0};        // 发送的数据：工作的六个角度
uchar ucSerial_send_bytes[26] = {0};           // 正常工作所有的字节数组
void Sci6ReFunc()
{
}
void Sci6TrFunc()
{
}
/****************** 串口的解析中断 *****************/
void serial_loop(){     // 		
	

	uiRec_bytes_num = 16;  
	if(serial_receive(ucSerial_rec_shake, uiRec_bytes_num))   // 串口接收
	{
		serial_decode(ucSerial_rec_shake, &stSerial_decode, uiRec_bytes_num);
	}
	//SCI6.RDR = 0;

	switch(ucSerial_send_status){          //串口发送
		case 0:        //IDLE state
				break;            
		case 1:	  // shake with upper machine
				SCI0.SCR.BYTE = 0x04;
				ucDataBytes_Len = 2;
				serial_build_protocol(ucSerial_shake_send_dataBits, ucSerial_shake_send_bytes, ucDataBytes_Len);  // 
				serial_send(ucSerial_shake_send_bytes, ucDataBytes_Len+4);//R_PG_SCI_StartSending_C2(ucSerial_shake_send_bytes, 6);
				/***
				if (SCI0.SSR.BIT.ORER){
					SCI0.SSR.BIT.ORER = 0;
				}***/
				ucSerial_send_status = 0;
				break;			
		case 2:   // connection work 
				if (ucShake_success){
					SCI0.SCR.BYTE = 0x04;
					u32Package_count++;
					stSerial_data.package_count = u32Package_count;
					ucDataBytes_Len = 22;
					
					serial_encode(stSerial_data, ucSerial_send_dataBits); 
					serial_build_protocol(ucSerial_send_dataBits, ucSerial_send_bytes, ucDataBytes_Len);  // 
					serial_send(ucSerial_send_bytes, ucDataBytes_Len+4);  
					ucSerial_send_status = 0;
				
				}
			
				break;
	}	
	if (SCI6.SSR.BIT.ORER == 1)    // 缓存满置零
	{
		SCI6.SSR.BIT.ORER = 0;
	}
	SCI6.SSR.BIT.TEND = 0X00;
}
/***************   串口发送 **********************/
void serial_send(uchar *ucArrData, uchar ucBytes_len)
{
	R_PG_SCI_SendAllData_C6(ucArrData, ucBytes_len);//R_PG_SCI_StartSending_C2(ucArrData, ucBytes_len);              // 通过SCI的方式将数组发送出去
	//SCI6.SSR.BIT.TDRE = 0X01;

}

/********************* 串口接收 **********************************/
bool serial_receive(uchar * ucSerial_datas, uint uiCount){

	bool blResult = 0;
	int isCount = 0;
	R_PG_SCI_StartReceiving_C6(ucSerial_datas, uiCount);
	SCI2.SSR.BIT.RDRF = 0;
	
	for(isCount = 0 ; isCount < uiCount; isCount++)
	{
		if(ucSerial_datas[isCount] != 0)
			blResult = 1;
			break;	
	}
	return blResult;
}

/*************** 串口编码 **********************/
/************* serial protocol *****************
1	起始字节	2	0x55AA	
2	数据长度	1	0x18	
3~6	包计数	4		
7	xx头工作状态信号	1	该字节由高到低依次为D7、D6…、 
D0=0 未捕获     D0=1捕获
D1=0无光电信号  D1=1有光电信号
D2=0无光电信号  D2=1有光电信号
D3=0未进入盲区  D3=1进入盲区	
8	码型	1	见表4	
9~10	俯仰框架角	2	度	-17.5~+17.5	100	
11~12	偏航框架角	2	度	-17.5~+17.5	100	
13~14	俯仰视线角速度	2	度/秒	-10~+10	100	
15~16	偏航视线角速度	2		-10~+10	100	
17~18	俯仰跟踪角偏差	2	度	-15~+15	100	
19~20	偏航跟踪角偏差	2	度	-15~+15	100	
21~24	备用	4				
25	校验和	1	************************************/
void serial_encode(const ST_SERIAL_DATA stSerial_data, uchar *ucSerial_send_dataBits)    
{	
	int uintGenetate_Count = 0;
	const float fpDeg_center[6] = {17.5, 17.5, 10, 10, 15, 15};          // 角度的均值，0 相当于-17.5°
	const float fpdeg[6] = {stSerial_data.elevation_deg, stSerial_data.sheer_deg,\
	 stSerial_data.elevation_view_deg_speed, stSerial_data.sheer_view_deg_speed,\
	 stSerial_data.elevation_trace_deg_offset, stSerial_data.sheer_trace_deg_offset};    // 各种传感器测出来的角度值
	int i32Scale = 100;             // 角度转换的比
	uint package_count = stSerial_data.package_count;
	uchar ucPackages[4] = {0};
		
	serial_u32toucArr(package_count, ucPackages);    // 将包计数转换成4个字节
	for (uintGenetate_Count=0; uintGenetate_Count < 4;uintGenetate_Count++){
		ucSerial_send_dataBits[uintGenetate_Count] = ucPackages[uintGenetate_Count];   // 将四个字节赋值串口数组
	}                              // 3~6. package count
	ucSerial_send_dataBits[4] = stSerial_data.work_status; 			//7. 工作状态
	ucSerial_send_dataBits[5] = stSerial_data.code_pattern;           //8. 码型	
                                           
	for(uintGenetate_Count = 0; uintGenetate_Count < 6; uintGenetate_Count++){
		uchar ucDegs[2] = {0};
		serial_fpdegtoucArr(fpdeg[uintGenetate_Count], fpDeg_center[uintGenetate_Count], i32Scale, ucDegs);
		ucSerial_send_dataBits[6 + uintGenetate_Count*2] = ucDegs[0];    //9~ 将字节数组中的角度值的低八位赋值给字节数组
		ucSerial_send_dataBits[7 + uintGenetate_Count*2] = ucDegs[1];    //10~ 将字节数组中的角度值的高八位赋值给字节数组
	}
}
/**************************************************
Function: // serial_build_protocol
Description: // 将数据位组合成符合协议的包
Input: // 数据位、包的指针
Others: // 
**************************************************/
void serial_build_protocol(uchar *ucSerial_datasBits, uchar *ucSerial_bytes, uchar ucDataBytes_Len)
{
	int i32count = 0;
	uint uiCheckout_sum = 0;
	uchar ucCheckout_count = 0;
	char ucCheckout_real = 0;  
		
	ucSerial_bytes[0] = 0x55;    // 1. headline1
	ucSerial_bytes[1] = 0xAA;    // 2. headline2
	ucSerial_bytes[2] = ucDataBytes_Len;    // 3.数据长度
	for (i32count = 0; i32count < ucDataBytes_Len; i32count++)
	{
		ucSerial_bytes[3 + i32count] = ucSerial_datasBits[i32count];          // 4. 数据位读入
	}
	ucSerial_bytes[3 + i32count] = serial_cal_checkout(ucSerial_datasBits, ucDataBytes_Len);  //校验和	
}
/****************** 串口解码 ********************/

/********************** upper machine to slave  protocol *****************************
序号	名称	字节数	单位	范围(处理后)	比例尺	备注
1	起始字节	2	0x55AA	
2	数据长度	1	0x0C	
3~4	俯仰下倾角指令	2	度	-17.5~+17.5	100	
5~6	偏航下倾角指令	2	度	-17.5~+17.5	100	
7	捕获指令	1	0x55：捕获  0xFF:不捕获	1	
8	码型	1	见表4	1	
9~14	备用	6				
15	校验和	1			1	
****************************************************
校验和：有效数据长度和数据内容按字节累加和的低八位（1个字节）
*************************************************/
void serial_decode(const uchar *ucSerial_rec_bits, ST_SERIAL_DECODE *stSerial_decode, uchar ucByte_len)
{
	int i32Decode_count = 0;
	int i32Current_ArrSize = 0;
	int i32Clear_count = 0;
	uchar ucCurrent_byte = 0;
	for (i32Decode_count = 0; i32Decode_count < ucByte_len; i32Decode_count++){
		ucCurrent_byte = ucSerial_rec_bits[i32Decode_count];
		switch(stSerial_decode->ucSerial_decode_status){
			case 0:    // headline1
				if(ucCurrent_byte == 0x55){
					stSerial_decode->ucSerial_decode_status = 1; // 字节头校验通过
				}
				break;
			case 1:    // headline2
				if(ucCurrent_byte == 0xAA){
					stSerial_decode->ucSerial_decode_status = 2; // 字节头2校验通过
				}else {
					stSerial_decode->ucSerial_decode_status = 0;
					u32Error_count++;
				}
				break;
			case 2:    // data length
				stSerial_decode->ucSerial_data_length = ucCurrent_byte; // 得到数据长度
				stSerial_decode->ucSerial_decode_status = 3;  // 切换到接收到数据模式
				break;
			case 3:    // receive data				
				stSerial_decode->ucSerial_dataBits[stSerial_decode->ucSerial_cur_data_len] = ucCurrent_byte;  
				stSerial_decode->ucSerial_cur_data_len++;
				if(stSerial_decode->ucSerial_cur_data_len >= stSerial_decode->ucSerial_data_length){
					stSerial_decode->ucSerial_decode_status = 4;    //切换校验模式
				}
				break;
			case 4:     // checkout 
				if(serial_cal_checkout(stSerial_decode->ucSerial_dataBits, stSerial_decode->ucSerial_data_length) == ucCurrent_byte )  //校验和通过
				{
					if(stSerial_decode->ucSerial_data_length == 1 && stSerial_decode->ucSerial_dataBits[0] == 1){
						ucSerial_send_status = 1;
						ucShake_success = 1;
					}
					else {
						ucSerial_send_status = 2;
					}
				}
				else {
					u32Error_count++;
				}
				
				stSerial_decode->ucSerial_data_length = 0; // 状态机置0 ，循环重新开始
				stSerial_decode->ucSerial_decode_status = 0;
				stSerial_decode->ucSerial_cur_data_len = 0;
				memset(ucSerial_rec_bits,0,ucByte_len*sizeof(unsigned char));
				break;
			default:
				break;
		}
	}
	

}

/*************************************************
Function: // serial_u32toucArr
Description: // 将四个字节的数转换成四个字节的数组
Input: // 输入uint的数和获取的字节数组
Others: // 小在前的解析协议
*************************************************/
//static void serial_u32toucArr(uint uiData, uchar *ucByteArr)
void serial_u32toucArr(uint uiData, uchar *ucByteArr)
{
	ucByteArr[0] = uiData % 256;      // 低八位在前
	uiData = uiData / 256;            // 将后面的八位去掉
	ucByteArr[1] = uiData % 256; 	  
	uiData = uiData / 256;
	ucByteArr[2] = uiData % 256; 	     
	uiData = uiData / 256;
	ucByteArr[3] = uiData % 256; 	  
	uiData = uiData / 256;
}

/*************************************************
Function: // serial_fpdegtoucArr
Description: // 将角度float类型的转换成两个字节的数组
Input: // 输入角度，角度平均值，比例尺，待转换的字节数组
Others: // 协议同上
*************************************************/
//static void serial_fpdegtoucArr(float deg, float deg_center, int scale, uchar *ucByteArr)
void serial_fpdegtoucArr(float deg, float deg_center, int scale, uchar *ucByteArr)
{
	ucByteArr[0] = (ushort)((deg +deg_center) * scale)% 256;    // 低八位在前
	ucByteArr[1] = (ushort)((deg +deg_center) * scale) / 256;    // 高八位在后
}

/*************************************************
Function: // serial_cal_checkout
Description: // 串口校验和
Input: // 数据和数据长度和校验位s
Others: // 校验数据和数据长度，取低八位进行校验
*************************************************/
uchar serial_cal_checkout(const uchar *ucSerial_datasBits, const uchar ucDataBytes_Len)
{
	uint uiCheckout_sum = 0;
	uchar ucCheckout_count = 0;
	uchar ucCheckout_real;
	
	for (ucCheckout_count = 0 ; ucCheckout_count < ucDataBytes_Len; ucCheckout_count++){
		uiCheckout_sum += ucSerial_datasBits[ucCheckout_count];
	}
	uiCheckout_sum += ucDataBytes_Len;
	ucCheckout_real = uiCheckout_sum % 256;
	return ucCheckout_real;
}
