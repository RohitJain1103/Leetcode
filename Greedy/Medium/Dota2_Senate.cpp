class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        //First we will count the number of R and D from the string
        int r=0,d=0;
        for(int i=0;i<n;i++){
            if(senate[i]=='R')
                r++;
            if(senate[i]=='D')
                d++;
        }
        
        int i = 0;
        while(r!=0 && d!=0){
            if(senate[i]=='R'){
                //Finding next 'D' and killing it
                for(int k=(i+1)%senate.length();;){
                    if(senate[k]=='D'){
                        senate[k] = 'X';
                        d--;
                        break;
                    }
                k = (k+1)%senate.length();
                }
            }
            else if(senate[i]=='D'){
                //Finding next 'R' and killing it
                for(int k=(i+1)%senate.length();;){
                    if(senate[k]=='R'){
                        senate[k] = 'X';
                        r--;
                        break;
                    }
                    k = (k+1)%senate.length();
                }
            }
            i = (i+1)%senate.length();
            //cout << senate << endl;
        }
        if(r==0)
            return "Dire";
        return "Radiant";
    }
};