void about()
{
  const char compileDate[] = __DATE__ " at " __TIME__;
  while (abtChangeDone == false)
  {
    tft.setCursor(45, 50);
    tft.setTextSize(1);
    tft.print("DeskBoy Mk.7 by u/kaizer1419");
    tft.setCursor(5, 90);
    tft.print("This code was compiled on");
    tft.setCursor(50, 100);
    tft.print(String(compileDate));    

    tp = ts.getPoint();

    pinMode(A2, OUTPUT);
    pinMode(A1, OUTPUT);

    if (tp.z > LP)
    {
      abtChangeDone = true;
      tft.fillScreen(backB);
    }
  }
}
