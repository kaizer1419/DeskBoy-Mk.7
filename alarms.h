void alarms()
{
  byte toAssignH = 0;
  byte toAssignM = 0;
  boolean toAssignE = false;
  unsigned int toAssignLoc = 0;//add 1 for minutes, 2 for enable or disable.
  int currentM = 0;
  int currentH = 0;
  String toDisplayLoc = "";
  String toDisplayH = "";
  String toDisplayM = "";
  boolean memChange = false;

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

  tft.drawRect(10, 260, 100, 40, tC);
  tft.setCursor(35, 270);
  tft.print("EXIT");

  tft.drawRect(130, 260, 100, 40, tC);
  tft.setCursor(155, 270);
  tft.print("ENBL");

  while (alarmChangeDone == false)
  {
    memChange = false;

    //load variables from memory
    toAssignH = readEEPROM(0x57, toAssignLoc);
    toAssignM = readEEPROM(0x57, toAssignLoc + 1);
    toAssignE = readEEPROM(0x57, toAssignLoc + 2);

    tft.fillRect(110, 210, 20, 20, backB);
    
    if (toAssignE == false)
    {
      tft.drawCircle(120, 220, 10, tC);
    }

    else
    {
      tft.fillCircle(120, 220, 10, tC);
    }

    
    if (toAssignH > 23)
    {
      toAssignH = 0;
    }

    if (toAssignM > 59)
    {
      toAssignM = 0;
    }

    toDisplayM = String(toAssignM);
    toDisplayH = String(toAssignH);

    if (toDisplayM.length() < 2)
    {
      toDisplayM = "0" + toDisplayM;
    }

    if (toDisplayH.length() < 2)
    {
      toDisplayH = "0" + toDisplayH;
    }

    tft.setCursor(105, 40);
    tft.print(toDisplayH);
    tft.setCursor(105, 100);
    tft.print(toDisplayM);
    tft.setCursor(110, 160);
    tft.print(String((toAssignLoc / 3) + 1));

    tp = ts.getPoint();

    pinMode(A2, OUTPUT);
    pinMode(A1, OUTPUT);

    if (tp.z > LP && tp.z < MP)
    {
      //tft.setCursor(0, 0);
      //tft.print(String(tp.x) + " " + String(tp.y));

      if ((tp.x >= 300 && tp.x <= 430) && (tp.y >= 790 && tp.y <= 880))
      {
        toAssignH++;
      }

      else if ((tp.x >= 680 && tp.x <= 790) && (tp.y >= 790 && tp.y <= 880) && toAssignH > 0)
      {
        toAssignH--;
      }

      else if ((tp.x >= 300 && tp.x <= 430) && (tp.y >= 630 && tp.y <= 740))
      {
        toAssignM++;
      }

      else if ((tp.x >= 680 && tp.x <= 790) && (tp.y >= 630 && tp.y <= 740) && toAssignM > 0)
      {
        toAssignM--;
      }

      else if ((tp.x >= 200 && tp.x <= 510) && (tp.y >= 220 && tp.y <= 320))
      {
        //exit
        alarmChangeDone = true;
        tft.fillScreen(BLACK);
      }

      else if ((tp.x >= 300 && tp.x <= 430) && (tp.y >= 490 && tp.y <= 600) && toAssignLoc < 21)
      {
        toAssignLoc = toAssignLoc + 3;
        memChange = true;
      }

      else if ((tp.x >= 680 && tp.x <= 790) && (tp.y >= 490 && tp.y <= 600) && toAssignLoc > 2)
      {
        toAssignLoc = toAssignLoc - 3;
        memChange = true;
      }

      else if ((tp.x >= 580 && tp.x <= 890) && (tp.y >= 220 && tp.y <= 320))
      {
        toAssignE = !(toAssignE);
        //memChange = true;
      }
    }

    if (memChange == false)
    {
      writeEEPROM(0x57, toAssignLoc, toAssignH);
      writeEEPROM(0x57, toAssignLoc + 1, toAssignM);
      writeEEPROM(0x57, toAssignLoc + 2, toAssignE);
    }

    delay(50);
  }

  for (int i = 0, j = 0; i <= 21; i += 3, j++)
  {
    alms[i] = timeCon(readEEPROM(0x57, i), readEEPROM(0x57, i + 1));
  }
}
