void extras()
{
  tft.setTextSize(2);
  tft.drawRect(70, 30, 100, 40, tC);
  tft.setCursor(85, 40);
  tft.print("Alarms");
  if (connectedEsp)
  {
    tft.drawRect(70, 90, 100, 40, tC);
    tft.setCursor(85, 100);
    tft.print("Reddit");
  }
  tft.drawRect(70, 200, 100, 40, tC);
  tft.setCursor(95, 210);
  tft.print("EXIT");

  tp = ts.getPoint();

  pinMode(A2, OUTPUT);
  pinMode(A1, OUTPUT);

  if (tp.z > LP && tp.z < MP)
  {
    //tft.setCursor(0, 0);
    //tft.print(String(tp.x) + " " + String(tp.y));

    if ((tp.x >= 400 && tp.x <= 700) && (tp.y >= 800 && tp.y <= 900))
    {
      alarmChangeDone = false;
      tft.fillScreen(backB);
      alarms();
    }

    else if ((tp.x >= 400 && tp.x <= 700) && (tp.y >= 640 && tp.y <= 740) && connectedEsp)
    {
      karmaChangeDone = false;
      tft.fillScreen(backB);
      karmaDisplay();
    }

    else if ((tp.x >= 400 && tp.x <= 700) && (tp.y >= 370 && tp.y <= 470))
    {
      tft.fillScreen(backB);
      state = 0;
    }

    delay(70);
  }
}
