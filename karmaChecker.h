String queryPostString = "GET https://api.thingspeak.com/apps/thinghttp/send_request?api_key=PQS9BMGGGV323JG8 HTTP/1.0\r\n";
String queryCommentString = "GET https://api.thingspeak.com/apps/thinghttp/send_request?api_key=5GNPEOBDE2DGOI83 HTTP/1.0\r\n";

int karma()
{
  //returns karma value
  Serial.println("Querying post karma");
  esp.flush();
  esp.print("AT+CIPSTART=0,\"TCP\",\"api.thingspeak.com\",80\r\n");
  while (esp.available() == 0);
  response = esp.readString();
  //Serial.println(response);
  if (response.indexOf("OK") >= 0)
  {
    Serial.println("CIPSTART Ok!");
    delay(50);
    esp.flush();
    esp.print("AT+CIPSEND=0,110\r\n");
    while (esp.available() == 0);
    response = esp.readString();
    //Serial.println(response);
    if (response.indexOf(">") >= 0)
    {
      Serial.println("CIPSEND Ok!");
      esp.print(queryPostString);
      boolean recievedInfo = false;
      while (recievedInfo == false)
      {
        esp.print("\r\n");

        response = esp.readString();
        //Serial.println(response);
        if (response.indexOf("X-Frame") >= 0)
        {
          recievedInfo = true;
          Serial.println("response");
          Serial.println(response);
          String toParse = response;
          String karmaString = toParse.substring(toParse.indexOf("a\">") + 3, toParse.indexOf("</s"));
          Serial.println(karmaString);
          String karmaT = karmaString.substring(0, karmaString.indexOf(","));
          Serial.println("karmaT = " + karmaT);
          String karmaH = karmaString.substring(karmaString.indexOf(",") + 1);
          Serial.println("karmaH = " + karmaH);
          pKarma = (karmaH.toInt()) + ((karmaT.toInt()) * 1000);
          
        }
      }
    }

    else
    {
      Serial.println("CIPSTART failed!");
      return (-1);
      ;;

    }
  }

  else
  {
    Serial.println("CIPSEND failed!");
    return (-1);
    ;;
  }

  delay(5000);

  Serial.println("Querying post karma");
  esp.flush();
  esp.print("AT+CIPSTART=0,\"TCP\",\"api.thingspeak.com\",80\r\n");
  while (esp.available() == 0);
  response = esp.readString();
  //Serial.println(response);
  if (response.indexOf("OK") >= 0)
  {
    Serial.println("CIPSTART Ok!");
    delay(50);
    esp.flush();
    esp.print("AT+CIPSEND=0,110\r\n");
    //esp.flush();
    //esp.readString();
    while (esp.available() == 0);
    response = esp.readString();
    Serial.println(response);
    if (response.indexOf(">") >= 0)
    {
      Serial.println("CIPSEND Ok!");
      esp.print(queryCommentString);
      boolean recievedInfo = false;
      while (recievedInfo == false)
      {
        esp.print("\r\n");

        response = esp.readString();
        //Serial.println(response);
        if (response.indexOf("X-Frame") >= 0)
        {
          recievedInfo = true;
          Serial.println("response");
          Serial.println(response);
          String toParse = response;
          String karmaString = toParse.substring(toParse.indexOf("a\">") + 3, toParse.indexOf("</s"));
          Serial.println(karmaString);
          String karmaT = karmaString.substring(0, karmaString.indexOf(","));
          Serial.println("karmaT = " + karmaT);
          String karmaH = karmaString.substring(karmaString.indexOf(",") + 1);
          Serial.println("karmaH = " + karmaH);
          cKarma = (karmaH.toInt()) + ((karmaT.toInt()) * 1000);
          
        }
      }
    }

    else
    {
      Serial.println("CIPSTART failed!");
      return (-1);
      ;;

    }
  }

  else
  {
    Serial.println("CIPSEND failed!");
    return (-1);
    ;;
  }
  int totalK = pKarma + cKarma;
  Serial.println("Total karma: " + String(totalK));
  return (totalK);
}
