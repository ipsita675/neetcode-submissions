class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>s;
        
        for(auto e:emails){
            int n=e.size();
            int i=0;
            string final= "";

            while(e[i]!='@'){
                if(e[i]=='+'){
                    while(e[i]!='@')i++;
                    break;
                }
                if(e[i]!='.')final+=e[i];
                i++;
            }
            while(i<n){
                final+=e[i];
                i++;
            }

            s.insert(final);
        }

        return s.size();
    }
};