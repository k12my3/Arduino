
const int sensor = 23; //ADC GPIO pin
const double noloadvolt = 2.5;//apt no load voltage for current sens
const int mVperAmp = 66; //mv/A
const double AdcRes = 3.3/4096; //ADC resolution
const int loadsupplyvolt = 5; //load supply voltage
double voltage = 0;
double volts = 0;
double amps = 0;

void setup () 
{
  pinMode(sensor,INPUT) ;
  Serial.begin(115200) ;
  delay(10);
  Serial.println(F(" Init .... "));
}

void loop ()
{
  int result = analogRead (sensor);
  voltage = result * AdcRes ;
  Serial.print (" Voltage : ");
  Serial.println (voltage);
  volts = (voltage - noloadvolt);
  amps = (volts*1000)/mVperAmp ;
  float wattage = (5*amps) ;
  Serial.print (amps);
  Serial.println (" Amps ");
  Serial.print (wattage) ;
  Serial.println (" Watt ");
  delay(5000) ;
}
