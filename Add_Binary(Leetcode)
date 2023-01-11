class Solution {

public:

//facebook's top 4 question:::

    string addBinary(string a, string b) {
        string res;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        while(i >= 0 || j >= 0){
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            carry = sum > 1 ? 1 : 0;
            //changing again to string for storing
            res += to_string(sum % 2);
        }
        //bilkull end me agar still koi carry aata hai to
        if(carry) res += to_string(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};

   
