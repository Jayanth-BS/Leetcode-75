class Solution {
public:
    unordered_map<int, string> belowten = {{0," "},{1,"One"},{2,"Two"},{3,"Three"},{4,"Four"},{5,"Five"},{6,"Six"},{7,"Seven"},{8,"Eight"},{9,"Nine"}};
    unordered_map<int, string> belowtwenty = {{10,"Ten"},{11,"Eleven"},{12,"Twelve"},{13,"Thirteen"},{14,"Fourteen"},{15,"Fifteen"},{16,"Sixteen"},{17,"Seventeen"},{18,"Eighteen"},{19,"Nineteen"}};
    unordered_map<int, string> belowhundred = {{2,"Twenty"},{3,"Thirty"},{4,"Forty"},{5,"Fifty"},{6,"Sixty"},{7,"Seventy"},{8,"Eighty"},{9,"Ninety"}};
    string solve(int num){
        if(num == 0)
            return "Zero";
        if(num<10)
            return belowten[num];
        
        if(num<20)
            return belowtwenty[num];

        if(num<100){ //68 = 60 +8
            return belowhundred[num/10] + ((num%10 != 0)? " "+belowten[num%10]:"");
        }
        if(num < 1000){ // 668 = 600 + 60 + 8
            return belowten[num/100] + " Hundred" +((num%100 != 0)? " "+solve(num%100):""); 
        }
        if(num < 1000000) {// 12345
            return solve(num/1000) + " Thousand" + ((num%1000 != 0)? " "+solve(num%1000):""); 
        }
        if(num < 1000000000){
            return solve(num/1000000) + " Million" + ((num%1000000 != 0)? " "+solve(num%1000000):""); 
        }
        if(num < 2500000000){
            return solve(num/1000000000) + " Billion" + ((num%1000000000 != 0)? " "+solve(num%1000000000):""); 
        }
        return "";
    }
    
    string numberToWords(int num) {
        return solve(num);
    }
};