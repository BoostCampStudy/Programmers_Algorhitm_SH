using namespace std;
long long get_gcd(int a, int b){
    int c;
    
    // Euclidean algorithm
    while (b != 0){
		c = a % b;
		a = b;
		b = c;
	}
    
	return a;
}


long long solution(int w,int h) {
    long long answer = 1;
    
    answer = (long)w * (long)h - (w + h) + get_gcd(w, h);
    return answer;
}