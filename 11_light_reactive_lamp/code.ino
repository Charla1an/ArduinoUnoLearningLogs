int rPin=11;
int gPin=10;
int bPin=9;

int lightPin=A0;
int lightVal;
int day_th=150;
int night_th=80;

int potPin=A2;
int potInput;
int bright;

void setRGB(int r,int g,int b) {
  int red=255-(bright*r)/255;
  int green=255-(bright*g)/255;
  int blue=255-(bright*b)/255;
  analogWrite(rPin,red);
  analogWrite(gPin,green);
  analogWrite(bPin,blue);
}

void setup() {
  pinMode(rPin,OUTPUT);
  pinMode(gPin,OUTPUT);
  pinMode(bPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lightVal=analogRead(lightPin);
  potInput=analogRead(potPin);
  bright=map(potInput,1023,0,255,0);

  if (lightVal>day_th) {
    // Day mode - sky blue
    setRGB(145,200,240);
    delay(20);
  }

  else if (lightVal>night_th) {
    // Evening mode - warm orange
    setRGB(170,35,0);
    delay(20);
  }
  else {
    // Night mode - RGB fade cycle
    for (int i=0,j=0,k=255;i<255 && k>0;i=i+5,k=k-5) {
      lightVal = analogRead(lightPin);
      if (lightVal > night_th) {
        break;
      }
      setRGB(i,j,k);
      delay(50);
    }
    for (int i=255,j=0,k=0;i>0 && j<255;i=i-5,j=j+5) {
      lightVal = analogRead(lightPin);
      if (lightVal > night_th) {
        break;
      }
      setRGB(i,j,k);
      delay(50);
    }
    for (int i=0, j=255,k=0;j>0 && k<255;j=j-5,k=k+5) {
      lightVal = analogRead(lightPin);
      if (lightVal > night_th) {
        break;
      }
      setRGB(i,j,k);
      delay(50);
    }
  }
}
