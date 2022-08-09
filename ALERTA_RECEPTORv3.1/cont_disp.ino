void cont_disp () {
 
  
              if((temp<millis()&&temp3<millis())&&((Log==false)&&(Log3==true))){
               
                temp=millis()+2000;
                Log=true;
                Log3=false;
                      display.clearDisplay();
                     display.display();
                     display.drawBitmap(0, 0, roboticalog, 128, 64, SSD1306_WHITE);
                     display.display();
                     
                     //delay (500);
              }else if ((temp2<millis()&& temp<millis())&&((Log2==false)&&(Log3==false))){
                temp2=millis()+2000;
                Log=false;
                Log2=true;
                display.clearDisplay();
                     display.display();
                     display.drawBitmap(0, 0, camecalog, 128, 64, SSD1306_WHITE);
                     display.display();
                     
                     //delay (500);
              }else  if ((temp3<millis()&&temp2<millis())&&(Log2==true)&&(Log3==false)){
              temp3=millis()+2000;
                Log3=true;
                Log2=false;
                display.clearDisplay();
                     display.display();
                     display.drawBitmap(0, 0, iprodhalog, 128, 64, SSD1306_WHITE);
                     display.display();
                     
                     //delay (500);
                     }
}
