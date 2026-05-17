class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans=0;
        vector<int>b(32,0);
        for(int i=0;i<=31;i++) {
            b[i]=((1<<i)&n)?1:0;
            //cout<<b[i]<< " ";
        }
        //cout<<endl;
        
        for(int i=0;i<=31;i++) ans+=(1<<i)*b[31-i];
        return ans;
    }
};
