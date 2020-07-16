int fact[N], invfact[N];

int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

int modinv(int k)
{
	return pow(k, MOD-2, MOD);
}

void precompute()
{
	fact[0]=fact[1]=1;
	for(int i=2;i<N;i++)
	{
		fact[i]=fact[i-1]*i;
		fact[i]%=MOD;
	}
	invfact[N-1]=modinv(fact[N-1]);
	for(int i=N-2;i>=0;i--)
	{
		invfact[i]=invfact[i+1]*(i+1);
		invfact[i]%=MOD;
	}
}

int nCr(int x, int y)
{
	if(y>x)
		return 0;
	int num=fact[x];
	num*=invfact[y];
	num%=MOD;
	num*=invfact[x-y];
	num%=MOD;
	return num;
}

------------------------------------------------------------------

ll Pa_triangle[MAX + 6][MAX + 6];

void func() {
    Pa_triangle[0][0] = 1,Pa_triangle[1][0]=1,Pa_triangle[1][1]=1;

    for(ll i = 2; i < MAX; i++) {
        Pa_triangle[i][0] = 1;
        for(ll j = 1; j <= i; j++) {
            Pa_triangle[i][j] = (Pa_triangle[i - 1][j - 1] + Pa_triangle[i - 1][j])%mod;
        }
    }
}

---------------------------------------------------------------
/* 
Fermat's little theorem: 
1) (a/b)%mod= (a*(poww(b,mod-2,mod)))%mod iff a%b==0
2) (a^b)%mod= (a^(b%(mod-1)))%mod iff mod is prime
*/