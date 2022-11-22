#define RCCAHB1EN *((unsigned volatile int *) 0x40023830)
#define gpiomodregister *((unsigned volatile int *) 0x40020c00)
#define gpiodataregister *((unsigned volatile int *) 0x40020c14)

// buse = 98+117+115+101= 431 so our mod4=3 = green 12
// bayraktar = 98+97+121+114+97+107+116+97+114 = 961 so our mod4 is 1 = blue 15

void delay(){ //function for blink delay
	int delay0 = 0x000FFFFF;
	while (delay0--){
		}
}
void init_leds () { RCCAHB1EN = 0x8; //clock gate
}
void turn_name_on(){
		gpiomodregister = 0x1000000;
		gpiodataregister = 0x1000;
}
void turn_surname_on(){
		gpiomodregister = 0x40000000;
		gpiodataregister = 0x8000;
}
void turn_name_off(){
		gpiodataregister=0x0000;
}
void turn_surname_off(){
		gpiodataregister=0x0000;
}

int main(){
init_leds();
int k,m;

k=0;
while(k<4){
turn_name_on();
delay();
turn_name_off();
delay();
k++;
}

m=0;
while(m<9){
turn_surname_on();
delay();
turn_surname_off();
delay();
m++;
}

return 0;
}
