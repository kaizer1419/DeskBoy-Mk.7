void karmaDisplay()
{

  if (gotKarma == false)
  {
    tft.setCursor(0, 0);
    tft.setTextSize(1);
    tft.print("Querying karma...");
    toDisplayKarma = karma();
    gotKarma = true;
    tft.fillScreen(backB);
  }

  tft.setTextSize(2);
  tft.drawRect(70, 210, 100, 40, tC);
  tft.setCursor(82, 225);
  tft.print("Refresh");

  while (karmaChangeDone == false)
  {
    tft.setTextSize(2);
    tft.setCursor(50, 50);
    tft.print("Karma: " + String(toDisplayKarma));

    tft.setTextSize(2);
    tft.drawRect(70, 210, 100, 40, tC);
    tft.setCursor(82, 225);
    tft.print("Refresh");

    tp = ts.getPoint();

    pinMode(A2, OUTPUT);
    pinMode(A1, OUTPUT);

    if (tp.z > LP && tp.z < MP)
    {
      if ((tp.x >= 200 && tp.x <= 300) && (tp.y >= 150 && tp.y <= 230))
      {
        tft.fillScreen(backB);
        karmaChangeDone = true;
      }

      else if ((tp.x >= 400 && tp.x <= 700) && (tp.y >= 330 && tp.y <= 430) && wifiWorking == true)
      {
        tft.setCursor(0, 0);
        tft.setTextSize(1);
        tft.print("Querying karma...");
        toDisplayKarma = karma();

        tft.fillScreen(backB);
      }
    }
  }
}
