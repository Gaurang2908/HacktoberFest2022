class Solution {
    public long sumOfLargestPrimes(String s) {
        int n = s.length();
        Set<Long> set = new HashSet<>();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                try {
                    long val = Long.parseLong(s.substring(i, j));
                    if (isPrime(val)) {
                        set.add(val);
                    }
                } catch (NumberFormatException e) {
                }
            }
        }

        long first = 0, second = 0, third = 0;
        for (long num : set) {
            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second) {
                third = second;
                second = num;
            } else if (num > third) {
                third = num;
            }
        }

        return first + second + third;
    }

    public boolean isPrime(long n) {
        if (n <= 1) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;

        for (long i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }

        return true;
    }
}
