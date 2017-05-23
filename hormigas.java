import java.util.*;
import java.math.BigInteger;
import java.*;

public class AntWalkOnPole
{

 private static boolean isAnyOnPole(List<Ant> antList)
 {
  for(int i = 0, size = antList.size(); i < size; i++)
  {
   if(antList.get(i).isOnPole())
   {
    return true;
   }
  }
  return false;
 }
 private static void move(List<Ant> antList)
 {
  Ant ant;
  for(int i = 0, size = antList.size(); i < size; i++)
  {
   ant = antList.get(i);
   if(ant.isOnPole())
   {
    ant.move();
   }
  }
 }
 private static void initAntList(List<Ant> antList, int antsOrient, int[] positions, int antNumber, int poleLength)
 {
  Ant.setPoleLength(poleLength);
  antList.clear();

  int orient;
  for(int i = 0; i < antNumber; i++)
  {
   orient = (antsOrient >> (antNumber - i - 1)) & 1;
   Ant ant = new Ant(orient, positions[i]);
   antList.add(ant);
  }
 }
 private static void walk(int[] positions, int antNumber, int poleLength)
 {
  List<Ant> antList = new ArrayList<Ant>(antNumber);

  int time = 0;
  int min = Integer.MAX_VALUE;
  int minOrient = -1;
  int max = Integer.MIN_VALUE;
  int maxOrient = -1;

  for(int orient = 0; orient < (1 << antNumber); orient++)
  {
   initAntList(antList, orient, positions, antNumber, poleLength);
   time = 0;
   while(isAnyOnPole(antList))
   {
    move(antList);

    for(int j = 0; j < antNumber - 1; j++)
    {
     Ant ant1 = antList.get(j);
     Ant ant2 = antList.get(j + 1);

     ant1.meet(ant2);
    }
    time++;
   }
   if(time < min)
   {
    min = time;
    minOrient = orient;
   }
   if(time > max)
   {
    max = time;
    maxOrient = orient;
   }
   System.out.printf("orientation = %d, time = %d\n", orient, time);
  }
  System.out.printf("min = %d, minOrient = %d\n", min, minOrient);
  System.out.printf("max = %d, maxOrient = %d\n", max, maxOrient);
 }

 private static void testCase1()
 {
  int antNumber = 3;
  int length = 10;
  int positions[] = {2,6,7};
  walk(positions, antNumber, length);
 }
 private static void testCase2()
 {
  int antNumber = 3;
  int length = 10;
  int positions[] = {2, 6, 7};
  Arrays.sort(positions);

  walk(positions, antNumber, length);
 }
 private static void testCase3()
 {
  int antNumber = 7;
  int length = 214;
  int positions[] = {11,12,7,13,176,23,191};
  Arrays.sort(positions);

  walk(positions, antNumber, length);
 }
 /**
  * @param args
  */
 public static void main(String[] args)
 {
  testCase1();
  testCase2();
  testCase3();
 }
}

class Ant
{
 public static final int ORIENT_LEFT  = 0;
 public static final int ORIENT_RIGHT = 1;

 private static int poleLength;

 private int orientation; //0-left;1-right;
 private int pos;


 public Ant(int orient, int pos)
 {
  this.orientation = orient;
  this.pos = pos;
 }

 public boolean isOnPole()
 {
  return pos > 0 && pos < poleLength;
 }

 public void turnBack()
 {
  orientation = (orientation == ORIENT_LEFT) ? ORIENT_RIGHT : ORIENT_LEFT;
 }

 public void move()
 {
  if(!isOnPole())
  {
   return;
  }
  if(orientation == ORIENT_LEFT)
  {
   pos--;
  }
  else if(orientation == ORIENT_RIGHT)
  {
   pos++;
  }
 }
 public void meet(Ant another)
 {
  if(this.orientation == another.orientation)
  {
   return;
  }
  if(this.pos - another.pos != -1)
  {
   return;
  }
  turnBack();
  another.turnBack();
 }

 public String toString()
 {
  return "pos = " + pos + ", orient = " + orientation;
 }

 public static void setPoleLength(int length)
 {
  poleLength = length;
 }
}
