using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
} 

long long solution(int w,int h) {
    return (long long)w * (long long)h - ((w+h) - gcd(w,h));
}
