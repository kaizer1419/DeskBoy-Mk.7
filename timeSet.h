void timeChange()
{
  String hStr = "";
  String mStr = "";
  String dayStr = "";
  String monthStr = "";
  String yearStr = "";
  String setBufM = "";
  String setBufH = "";
  String setBufD = "";//DISPLayed
  String setBufMonth = "";
  String setBufYear = "";
  int tAssignM = 0;//to assign
  int tAssignH = 0;
  int tAssignD = 0;
  int tAssignMonth = 0; 
  int tAssignYear = 0;

  dt = rtc.now();
 
  hStr = String(dt.hour());
  mStr = String(dt.minute());
  dayStr = String(dt.day());
  monthStr = String(dt.month());
  yearStr = String(dt.year());

  tAssignH = hStr.toInt();
  tAssignM = mStr.toInt();
  tAssignD = dayStr.toInt();
  tAssignMonth = monthStr.toInt();
  tAssignYear = yearStr.toInt();

  //tft.drawRect(40, 30, 40, 40, tC);
  tft.setCursor(55, 45);
  tft.print("+");
  
  //tft.drawRect(160, 30, 40, 40, tC);
  tft.setCursor(175, 45);
  tft.print("-");

  //tft.drawRect(40, 90, 40, 40, tC);
  tft.setCursor(55, 105);
  tft.print("+");
  
  //tft.drawRect(160, 90, 40, 40, tC);
  tft.setCursor(175, 105);
  tft.print("-");

  //tft.drawRect(40, 150, 40, 40, tC);
  tft.setCursor(55, 165);
  tft.print("+");
  
  //tft.drawRect(160, 150, 40, 40, tC);
  tft.setCursor(175, 165);
  tft.print("-");

  //tft.drawRect(40, 210, 40, 40, tC);
  tft.setCursor(55, 225);
  tft.print("+");
  
  //tft.drawRect(160, 210, 40, 40, tC);
  tft.setCursor(175, 225);
  tft.print("-");

  //tft.drawRect(40, 270, 40, 40, tC);
  tft.setCursor(55, 285);
  tft.print("+");
  
  //tft.drawRect(160, 270, 40, 40, tC);
  tft.setCursor(175, 285);
  tft.print("-");

  while (timeChangeDone == false)
  {
    tft.setTextSize(3);

    setBufM = String(tAssignM);
    setBufH = String(tAssignH);
    setBufD = String(tAssignD);
    setBufMonth = String(tAssignMonth);
    setBufYear = String(tAssignYear);

    if (setBufM.length() < 2)
    {
      setBufM = "0" + setBufM;
    }

    if (setBufH.length() < 2)
    {
      setBufH = "0" + setBufH;
    }

    if (setBufD.length() < 2)
    {
      setBufD = "0" + setBufD;
    }

    if (setBufMonth.length() < 2)
    {
      setBufMonth = "0" + setBufMonth;
    }

    tft.setCursor(105, 40);
    tft.print(setBufH);
    tft.setCursor(105, 100);
    tft.print(setBufM);
    tft.setCursor(105, 160);
    tft.print(setBufD);
    tft.setCursor(105, 220);
    tft.print(setBufMonth);
    tft.setCursor(110, 290);
    tft.setTextSize(1);
    tft.print(setBufYear);
    tft.setTextSize(2);

    tp = ts.getPoint();

    pinMode(A2, OUTPUT);
    pinMode(A1, OUTPUT);

    if (tp.z > LP && tp.z < MP)
    {
      //tft.setTextSize(2);
      //tft.setCursor(0, 0);
      //tft.print(String(tp.x) + " " + String(tp.y) + " ");

      if ((tp.x >= 300 && tp.x <= 430) && (tp.y >= 790 && tp.y <= 880) && tAssignH < 23)
      {
        tAssignH++;
      }

      else if ((tp.x >= 680 && tp.x <= 790) && (tp.y >= 790 && tp.y <= 880) && tAssignH > 0)
      {
        tAssignH--;
      }

      else if ((tp.x >= 300 && tp.x <= 430) && (tp.y >= 630 && tp.y <= 740) && tAssignM < 59)
      {
        tAssignM++;
      }

      else if ((tp.x >= 680 && tp.x <= 790) && (tp.y >= 630 && tp.y <= 740) && tAssignM > 0)
      {
        tAssignM--;
      }

      else if ((tp.x >= 300 && tp.x <= 430) && (tp.y >= 500 && tp.y <= 600) && tAssignD < 31)
      {
        tAssignD++;
      }

      else if ((tp.x >= 680 && tp.x <= 790) && (tp.y >= 500 && tp.y <= 600) && tAssignD > 1)
      {
        tAssignD--;
      }

      else if ((tp.x >= 300 && tp.x <= 430) && (tp.y >= 340 && tp.y <= 440) && tAssignMonth < 12)
      {
        tAssignMonth++;
      }

      else if ((tp.x >= 680 && tp.x <= 790) && (tp.y >= 340 && tp.y <= 440) && tAssignMonth > 1)
      {
        tAssignMonth--;
      }

      else if ((tp.x >= 300 && tp.x <= 430) && (tp.y >= 200 && tp.y <= 300))
      {
        tAssignYear++;
      }

      else if ((tp.x >= 680 && tp.x <= 790) && (tp.y >= 200 && tp.y <= 300) && tAssignYear > 1)
      {
        tAssignYear--;
      }


      else if((tp.x >= 200 && tp.x <= 300) && (tp.y >= 150 && tp.y <= 230))
      {
        tft.fillScreen(backB);
        rtc.adjust(DateTime(tAssignYear, tAssignMonth, tAssignD, tAssignH, tAssignM, 0));
        timeChangeDone = true;
      }
      
      delay(70);
    }
  }
}
