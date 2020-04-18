int gcd(int a, int b, int & x, int & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
----------------------------------------------

class Triplet
{
public:
    int gcd;
    int x;
    int y;    
};

Triplet extendedEuclid(int a ,int b)
{
 
  if(b==0)//Base case
  {
    Triplet ans;
    ans.gcd=a;
    ans.x=1;
    ans.y=0;

   return ans;
  }

  Triplet smallAns=extendedEuclid(b,a%b);
  Triplet myAns;
  myAns.gcd=smallAns.gcd;
  myAns.x=smallAns.y;
  myAns.y=smallAns.x-(a/b)*smallAns.y;

  return myAns;

}

int multiplicativeMolduloInverse(int a , int m)
{
    Triplet ans1=extendedEuclid(a,m);
    return ans1.x;
}
