class Solution {
public:
    unordered_map<int,vector<int>>v;
    vector<int> countBits(int n) {
        //cout<<v.size()<<endl;
        if(v.size()) return v[n];
        v[0]={0};
        for(int i=1;i<=1000;i++){
            int cnt=0;
            for(int j=31;j>=0;j--){
                if((1<<j)&i) cnt++;
            }
            vector<int>temp=v[i-1];
            temp.push_back(cnt);
            v[i]=temp;
        }
        return v[n];
    }
};
