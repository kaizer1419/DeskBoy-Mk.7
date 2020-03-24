void MainMenu()
{

  String hStr = "";
  String mStr = "";
  String tempBuf = "";
  char fP[] = "    ";
  char f1P[] = "    ";
  char f2P[] = "    ";
  int minSinceOne = 0;

  int xTouch = 0;
  int yTouch = 0;

  dt = rtc.now();

  hStr = String(dt.hour());
  mStr = String(dt.minute());

  //hStr = "10";
  //mStr = "20";

  if (hStr.length() == 1)
  {
    hStr = "0" + hStr;
  }

  if (mStr.length() == 1)
  {
    mStr = "0" + mStr;
  }

  minSinceOne = timeCon(dt.hour(), dt.minute());

  boolean switchFlag = false;

  for (int k = 0; k <= 7; k++)
  {
    if (alms[k] == minSinceOne  && almsEn[k] == 1)
    {
      switchFlag = true;
      break;
    }
  }

  if (switchFlag == true)
  {
   tC = RED;
   //ttft.setTextColor(tC, backB);one(49, 4000, 50);
  }

  else
  {
   tC = STOCK;
  }

  tft.setTextColor(tC, backB);

  if (smartP == true)
  {
    pN = pCalc(minSinceOne);
  }

  pN1 = pN + 1;
  pN2 = pN + 2;

  if (dt.dayOfTheWeek() == 1)
  {
    strcpy_P(fP, (char *)pgm_read_word(&(MON[pN])));
    strcpy_P(f1P, (char *)pgm_read_word(&(MON[pN1])));
    strcpy_P(f2P, (char *)pgm_read_word(&(MON[pN2])));
  }

  else if (dt.dayOfTheWeek() == 2)
  {
    strcpy_P(fP, (char *)pgm_read_word(&(TUE[pN])));
    strcpy_P(f1P, (char *)pgm_read_word(&(TUE[pN1])));
    strcpy_P(f2P, (char *)pgm_read_word(&(TUE[pN2])));
  }

  else if (dt.dayOfTheWeek() == 3)
  {
    strcpy_P(fP, (char *)pgm_read_word(&(WED[pN])));
    strcpy_P(f1P, (char *)pgm_read_word(&(WED[pN1])));
    strcpy_P(f2P, (char *)pgm_read_word(&(WED[pN2])));

  }

  else if (dt.dayOfTheWeek() == 4)
  {
    strcpy_P(fP, (char *)pgm_read_word(&(THU[pN])));
    strcpy_P(f1P, (char *)pgm_read_word(&(THU[pN1])));
    strcpy_P(f2P, (char *)pgm_read_word(&(THU[pN2])));
  }

  else if (dt.dayOfTheWeek() == 5)
  {
    strcpy_P(fP, (char *)pgm_read_word(&(FRI[pN])));
    strcpy_P(f1P, (char *)pgm_read_word(&(FRI[pN1])));
    strcpy_P(f2P, (char *)pgm_read_word(&(FRI[pN2])));
  }

  else if (dt.dayOfTheWeek() == 6)
  {
    strcpy_P(fP, (char *)pgm_read_word(&(SAT[pN])));
    strcpy_P(f1P, (char *)pgm_read_word(&(SAT[pN1])));
    strcpy_P(f2P, (char *)pgm_read_word(&(SAT[pN2])));
  }

  else if (dt.dayOfTheWeek() == 0)
  {
    strcpy_P(fP, (char *)pgm_read_word(&(SUN[pN])));
    strcpy_P(f1P, (char *)pgm_read_word(&(SUN[pN1])));
    strcpy_P(f2P, (char *)pgm_read_word(&(SUN[pN2])));
  }

  //fP = rtc.getDOWStr(FORMAT_SHORT) + String(pN) + ".txt";
  //f1P = rtc.getDOWStr(FORMAT_SHORT) + String(pN) + ".txt";
  //f2P = rtc.getDOWStr(FORMAT_SHORT) + String(pN) + ".txt";

  //tempBuf = String((int)rtc.getTemp());

  if (tempBuf.length() == 1)
  {
    tempBuf = "0" + tempBuf;
  }

  tempBuf = tempBuf + "C";

  tft.setTextSize(7);
  tft.setTextColor(tC, backB);
  tft.setCursor(80, 50);
  tft.print(hStr);
  tft.setCursor(80, 110);
  tft.print(mStr);

  tft.setTextSize(2);
  tft.setTextColor(tC, backB);
  tft.setCursor(100, 10);
  tft.print(daysOfTheWeek[dt.dayOfTheWeek()]);
  tft.setCursor(10, 240);
  //tft.print("     ");
  tft.print(fP);
  tft.setCursor(100, 240);
  //tft.print("     ");
  tft.print(f1P);
  tft.setCursor(190, 240);
  //tft.print("     ");
  tft.print(f2P);

  tft.setCursor(90, 190);
  tft.print(String(dt.day()) + "/" + String(dt.month()));

  //tft.drawRect(0, 280, 50, 40, tC);
  //tft.drawRect(95, 280, 50, 40, tC);
  //tft.drawRect(190, 280, 50, 40, tC);
  //tft.drawRect(190, 10, 40, 40, tC);
  //tft.drawRect(10, 10, 40, 40, tC);

  tft.setCursor(205, 25);
  tft.print("*");
  tft.setCursor(25, 25);
  tft.print("+");

  tft.setCursor(20, 295);
  tft.print('<');
  tft.setCursor(212, 295);
  tft.print('>');
  tft.drawCircle(120, 300, 10, tC);

  tft.setCursor(80, 220);
  
  if(connectedEsp)
  {
    tft.print("WiFi On");
  }

  tp = ts.getPoint();

  pinMode(A2, OUTPUT);
  pinMode(A1, OUTPUT);

  //touch based stuff
  if (tp.z > LP && tp.z < MP)
  {
    //tft.setCursor(0, 60);
    //tft.print(String(tp.x) + " " + String(tp.y));

    if ((tp.x >= 780 && tp.x <= 915) && (tp.y >= 180 && tp.y <= 275) && pN < 11) //> button
    {
      smartP = false;
      pN ++;
    }

    else if ((tp.x >= 185 && tp.x <= 335) && (tp.y >= 180 && tp.y <= 275) && pN != 0 && (pCalc(minSinceOne) != 12))
    {
      smartP = false;
      pN --;
    }

    else if ((tp.x >= 490 && tp.x <= 640) && (tp.y >= 180 && tp.y <= 275))
    {
      smartP = true;
    }

    else if ((tp.x >= 230 && tp.x <= 350) && (tp.y >= 840 && tp.y <= 940))
    {
      state = 2;
      tft.fillScreen(backB);
    }

    else if ((tp.x >= 760 && tp.x <= 880) && (tp.y >= 840 && tp.y <= 940))
    {
      state = 1;
      tft.fillScreen(backB);
    }

    //delay(70);
  }
}
