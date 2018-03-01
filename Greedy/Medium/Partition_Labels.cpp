class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> alpha1(26,0),alpha2(26,0),res;
        for(int i=0;i<S.length();i++) alpha1[S[i]-'a']++;
        for(int i=0;i<S.length();i++){
            alpha2[S[i]-'a']++;
            int counter=0;
            for(int j=0;j<26;j++){
                if(alpha2[j] == alpha1[j] || !alpha2[j])
                    counter++;
            }
            //If all of them are either not seen OR all encountered
            if(counter==26) res.push_back(i);
        }
        //This part is just for adjusting to according to answer
        for(int i=res.size()-1;i>=0;i--)
            res[i] -= res[i-1];
        res[0]++;
        return res;
    }
};