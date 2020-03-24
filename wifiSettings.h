void wifiSettings()
{
  while (wifiChangeDone == false)
  {
    tft.setTextColor(tC, backB);

    tft.setTextSize(1);
    tft.drawRect(70, 30, 100, 40, tC);
    tft.setCursor(90, 45);
    tft.print("Test Module");
    tft.setTextSize(2);
    tft.drawRect(70, 90, 100, 40, tC);
    tft.setCursor(90, 100);
    tft.print("Reset");

    if (wifiWorking == true)
    {
      tft.drawRect(70, 150, 100, 40, tC);

      if (connectedEsp)
      {
        tft.setCursor(90, 165);
        tft.setTextSize(1);
        tft.print("Disconnect");
      }

      else
      {
        tft.setCursor(80, 160);
        tft.setTextSize(2);
        tft.print("Connect");
      }
      tft.setTextSize(1);
      tft.drawRect(70, 210, 100, 40, tC);
      tft.setCursor(82, 225);
      tft.print("Access Points");
    }

    tp = ts.getPoint();

    pinMode(A2, OUTPUT);
    pinMode(A1, OUTPUT);

    if (tp.z > LP && tp.z < MP)
    {
      //tft.setCursor(0, 0);
      //tft.print(String(tp.x) + " " + String(tp.y));

      if ((tp.x >= 400 && tp.x <= 700) && (tp.y >= 800 && tp.y <= 900))//TEST
      {
        tft.fillScreen(backB);
        //Test module
        esp.flush();
        delay(50);
        esp.print("AT\r\n");
        tft.setCursor(0, 5);
        tft.setTextSize(1);
        tft.println("Command sent...");
        while (esp.available() == 0);
        response = esp.readString();
        //Serial.println(response);

        if (response.indexOf("OK") >= 0 )
        {
          tft.print("ESP8266 is functional!");
          delay(2000);
          wifiWorking = true;
        }

        else
        {
          tft.setCursor(0, 0);
          tft.print("ESP8266 failed!\nWiFi capabilities disabled...");
          wifiWorking = false;
          delay(3000);
        }
        tft.fillScreen(backB);
        tft.setTextSize(2);
      }

      else if ((tp.x >= 400 && tp.x <= 700) && (tp.y >= 640 && tp.y <= 740) && wifiWorking == true)//RESET
      {
        //RESeT
        tft.fillScreen(backB);
        esp.flush();
        delay(50);
        esp.print("AT+RST\r\n");
        tft.setCursor(0, 5);
        tft.setTextSize(1);
        tft.println("Command sent...");
        while (esp.available() == 0);
        response = esp.readString();
        Serial.println(response);
        while (esp.available() == 0);
        response = esp.readString();
        Serial.println(response);

        if (response.indexOf("Ai") >= 0 )
        {
          tft.print("ESP8266 reset!");
          esp.print("ATE0\r\n");

          delay(2000);
          connectedEsp = false;
        }

        else
        {
          tft.setCursor(0, 0);
          tft.print("ESP8266 failed!\nWiFi capabilities disabled...");
          connectedEsp = false;
          delay(3000);
        }

        tft.fillScreen(backB);
        tft.setTextSize(2);
      }

      else if ((tp.x >= 400 && tp.x <= 700) && (tp.y >= 490 && tp.y <= 590) && wifiWorking == true)//Coonect/Disconnect
      {

        boolean doAdvancedSetup = false;

        if (connectedEsp == false)
        {
          //Connect
          tft.fillScreen(backB);
          response = esp.readString();
          esp.flush();
          delay(50);
          esp.print("AT+CWJAP=\"AP",\"PWD\"\r\n");
          
          tft.setCursor(0, 5);
          tft.setTextSize(1);
          tft.println("Command sent...");
          while (esp.available() == 0);
          response = esp.readString();
          Serial.println(response);

          if (response.indexOf("OK") >= 0 )
          {
            tft.println("ESP8266 is connected!");
            connectedEsp = true;
            doAdvancedSetup = true;
          }

          else
          {
            tft.setCursor(0, 0);
            tft.print("Connection failed!\nNot connected...");
            doAdvancedSetup = false;
            delay(2000);
          }

          if (doAdvancedSetup)
          {
            esp.flush();
            esp.print("AT+CIPMODE=0\r\n");
            tft.println("Assigning mode...");
            while (esp.available() == 0);
            response = esp.readString();
            Serial.println(response);
            if (response.indexOf("OK") >= 0)
            {
              tft.println("CIPMODE assigned!");
            }

            else
            {
              tft.println("CIPMODE failed!\nStopping...");
              delay(500);
              tft.fillScreen(backB);
              tft.setTextSize(2);
              break;
            }

            //CIPMUX
            esp.flush();
            esp.print("AT+CIPMUX=1\r\n");
            tft.println("Assigning CIPMUX...");
            while (esp.available() == 0);
            response = esp.readString();
            Serial.println(response);
            if (response.indexOf("OK") >= 0)
            {
              tft.println("CIPMUX assigned!");
            }

            else
            {
              tft.println("CIPMUX failed!\nStopping...");
              delay(500);
              tft.fillScreen(backB);
              tft.setTextSize(2);
              break;
            }
          }


          tft.fillScreen(backB);
          tft.setTextSize(2);
        }

        else if (connectedEsp == true)
        {
          //Disconnect
          tft.fillScreen(backB);
          response = esp.readString();
          esp.flush();
          delay(50);
          esp.print("AT+CWQAP\r\n");
          Serial.println("AT+CWQAP\r\n");
          tft.setCursor(0, 5);
          tft.setTextSize(1);
          tft.println("Command sent...");
          while (esp.available() == 0);
          response = esp.readString();
          Serial.println(response);

          if (response.indexOf("OK") >= 0 )
          {
            tft.print("ESP8266 is disconnected!");
            connectedEsp = false;
            delay(2000);
          }

          else
          {
            tft.setCursor(0, 0);
            tft.print("Disconnection failed!\nStill connected...");
            delay(3000);
          }
          tft.fillScreen(backB);
          tft.setTextSize(2);
        }
      }

      else if ((tp.x >= 400 && tp.x <= 700) && (tp.y >= 330 && tp.y <= 430) && wifiWorking == true)
      {
        //Add wifi connections
      }

      else if ((tp.x >= 200 && tp.x <= 300) && (tp.y >= 150 && tp.y <= 230))
      {
        tft.fillScreen(backB);
        wifiChangeDone = true;
      }

      delay(70);
    }
  }
}
