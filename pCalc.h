int pCalc (int x)
{
  if(x >= timeCon(8, 10) && timeCon(8, 45) > x)
  {
    return(0);
  }

  else if(x >= timeCon(8, 45) && timeCon(9, 20) > x)
  {
    return(1);
  }

  else if(x >= timeCon(9, 20) && timeCon(9, 35) > x)
  {
    //SNACKS
    return(2);
  }

  else if(x >= timeCon(9, 35) && timeCon(10, 10) > x)
  {
    return(3);
  }

  else if(x >= timeCon(10, 10) && timeCon(10, 45) > x)
  {
    return(4);
  }

  else if(x >= timeCon(10, 45) && timeCon(11, 20) > x)
  {
    return(5);
  }

  else if(x >= timeCon(11, 20) && timeCon(11, 55) > x)
  {
    return(6);
  }

  else if(x >= timeCon(11, 55) && timeCon(12, 30) > x)
  {
    return(7);
  }

  else if(x >= timeCon(12, 30) && timeCon(13, 5) > x)
  {
    return(8);
  }

  else if(x >= timeCon(13, 5) && timeCon(13, 35) > x)
  {
    return(9);
  }

  else if(x >= timeCon(13, 35) && timeCon(14, 10) > x)
  {
    return(10);
  }

  else if(x >= timeCon(14, 10) && timeCon(14, 45) > x)
  {
    return(11);
  }

  else
  {
    return(12);
  }
}
