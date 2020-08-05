#include<AT89X52.H>
/********
								电机定义
*********/
#define Left_moto_Stop    {P1_1=0,P1_2=0;}
#define Left_moto_go      {P1_1=1,P1_2=0;}
#define Left_moto_back    {P1_1=0,P1_2=1;}
#define Right_moto_Stop   {P1_3=0,P1_4=0;}              
#define Right_moto_go     {P1_3=1,P1_4=0;}
#define Right_moto_back   {P1_3=0,P1_4=1;}
/*********
							 左右巡线
*********/
#define Left_1_led        P3_6
#define Right_1_led       P3_7
#define lift  P3_4
#definr rigth P3_5

void delay(i){
	while(i--);
}

void  front_run(void){
	 Left_moto_go; 
	 Right_moto_go;
	 delay(1000);
	 Left_moto_Stop;
	 Right_moto_Stop;
	 delay(2000);
}

void  back_run(void){

	 Left_moto_back;   
	 Right_moto_back; 
}

void  left_run(void){
	 Right_moto_go;   
	 Left_moto_back;
	 delay(800);
	 Left_moto_Stop;
	 Right_moto_Stop;
	 delay(800);
}

void  right_run(void){
	 Left_moto_go;
	 Right_moto_back;
	 delay(800);
	 Left_moto_Stop;
	 Right_moto_Stop;
	 delay(800);
}

void  stop(void){
	 Left_moto_Stop;
	 Right_moto_Stop;
}

//   主函数

void main(void){
	//unsigned char i;
	stop();
	while(1){
		if(Left_1_led==0&&Right_1_led==0){
					front_run();
		}
		else{
			if(Left_1_led==1&&Right_1_led==0){
					right_run();
					delay(1000);                
			}
			if(Right_1_led==1&&Left_1_led==0){  
					left_run();
					delay(1000);
		  }
			if(Right_1_led==1&&Left_1_led==1){
					stop();
					delay(2000);
		  }
		}
		   // 红外避障简易
		if(life == 1&& right == 1){
				back_run();
				delay(1000);
				right_run();
				delay(1000);
				fount_run();
		}
		else if (life == 0&& right == 1){
				back_run();
				delay(1000);
				left_run();
				delay(10000);
				fount_run();
		}
		else{
			back_run();
			delay(1000);
			right_run();
			delay(10000);
			fount_run();
		
		}
	}
}
