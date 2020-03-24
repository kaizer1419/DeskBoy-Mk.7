void settings()
{
  tft.setTextColor(tC, backB);
  
  tft.setTextSize(2);
  tft.drawRect(70, 30, 100, 40, tC);
  tft.setCursor(95, 40);
  tft.print("Time");
  tft.drawRect(70, 90, 100, 40, tC);
  tft.setCursor(80, 100);
  tft.print("Colours");
  tft.drawRect(70, 150, 100, 40, tC);
  tft.setCursor(90, 160);
  tft.print("About");
  tft.drawRect(70, 210, 100, 40, tC);
  tft.setCursor(95, 220);
  tft.print("WiFi");  

  tp = ts.getPoint();

  pinMode(A2, OUTPUT);
  pinMode(A1, OUTPUT);

  if (tp.z > LP && tp.z < MP)
  {
    //tft.setCursor(0, 0);
    //tft.print(String(tp.x) + " " + String(tp.y));

    if ((tp.x >= 400 && tp.x <= 700) && (tp.y >= 800 && tp.y <= 900))
    {
      timeChangeDone = false;
      tft.fillScreen(backB);
      timeChange();
    }

    else if((tp.x >= 400 && tp.x <= 700) && (tp.y >= 640 && tp.y <= 740))
    {
      colChangeDone = false;
      tft.fillScreen(backB);
      colChange();
    }
    
    else if((tp.x >= 400 && tp.x <= 700) && (tp.y >= 490 && tp.y <= 590))
    {
      abtChangeDone = false;
      tft.fillScreen(backB);
      about();
    }

    else if((tp.x >= 400 && tp.x <= 700) && (tp.y >= 330 && tp.y <= 430))
    {
      wifiChangeDone = false;
      tft.fillScreen(backB);
      wifiSettings();
    }
    
    else if ((tp.x >= 200 && tp.x <= 300) && (tp.y >= 150 && tp.y <= 230))
    {
      tft.fillScreen(backB);
      state = 0;
    }

    delay(70);
  }
}
