class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x=0;
        int cnt=__builtin_popcount(num2);

        for(int i=31;i>=0;i--){
            if(cnt>0 && ((num1>>i)&1)==1){
                x=x|(1<<i);
                cnt--;
            }
        }
        for(int i=0;i<=31;i++){
            int curr=((x>>i)&1);

            if(curr==0 && cnt>0){
              x=x|(1<<i);
                cnt--;
            }
        }
        return x;

    }
};