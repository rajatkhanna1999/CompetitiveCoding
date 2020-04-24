//Recursive
int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
//Iterative
int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
//LCM
int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}