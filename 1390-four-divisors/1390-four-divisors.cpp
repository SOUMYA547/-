class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int answer = 0;
        for(int number: nums){
            int count = 0, sum = 0;
            for(int divisor = 1; divisor * divisor <= number; divisor++){
                if(number % divisor == 0){
                    int other = number/divisor;
                    if(divisor == other ){
                        count++;
                        sum += divisor;
                    }
                    else{
                        count += 2;
                        sum += divisor + other;
                    }
                    if(count > 4) break;
                }
            }
            if(count == 4) answer += sum;
        }
        return answer;
    }
};