void colChange()
{
  tft.setCursor(55, 45);
  tft.print("+");

  tft.setCursor(175, 45);
  tft.print("-");

  tft.drawRect(70, 200, 100, 40, tC);
  tft.setCursor(95, 210);
  tft.print("EXIT");

  int toAssignCol = tC;
  int loc = 0;

  for (int i = 0; i < sizeof(colours); i ++)
  {
    if (colours[i] == toAssignCol)
    {
      loc = i;
      break;
    }
  }

  while (colChangeDone == false)
  {
    tft.fillRect(100, 40, 40, 40, toAssignCol);
    //tft.setCursor(0, 0);
    //tft.print(loc);

    tp = ts.getPoint();

    pinMode(A2, OUTPUT);
    pinMode(A1, OUTPUT);

    if (tp.z > LP && tp.z < MP)
    {
      //tft.setTextSize(2);
      // tft.setCursor(0, 0);
      //tft.print(String(tp.x) + " " + String(tp.y) + " ");
      if ((tp.x >= 300 && tp.x <= 430) && (tp.y >= 790 && tp.y <= 880) && loc < 12)
      {
        //loc+
        loc++;
      }

      else if ((tp.x >= 680 && tp.x <= 790) && (tp.y >= 790 && tp.y <= 880) && loc > 0)
      {
        //loc-
        loc--;
      }

      else if ((tp.x >= 400 && tp.x <= 710) && (tp.y >= 370 && tp.y <= 470))
      {
        tft.fillScreen(backB);
        //write to memory
        writeEEPROM(0x57, 40, loc);
        //reassign colour
        tC = colours[readEEPROM(0x57, 40)];
        STOCK = tC;
        colChangeDone = true;
      }

      delay(70);
    }

    toAssignCol = colours[loc];
  }

  //write to memory.
}
