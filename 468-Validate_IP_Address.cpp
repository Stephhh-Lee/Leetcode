class Solution {
public:
    /*
    int str2int(string s){
        int ans=0;
        for(int i = 0; i < s.size(); i++){
            ans = ans*10+s[i]-'0';
        }
        return ans;
    }
    bool isIPv4(string ip){
        vector<string> v(4, "");
        int pos = 0;
        for(int i = 0; i < ip.size(); i++){
            if(pos>3) return false;
            if(ip[i]!='.') v[pos]+=ip[i];
            else pos++;
        }
        for(int i = 0; i < 4; i++){
            if(v[i].size() > 3 || v[i].size() < 1) return false;
            if(v[i][0] == '0' && v[i].size() != 1) return false;
            if(str2int(v[i]) > 255) return false;
        }
        return true;
    }
    bool isIPv6(string ip){
        if(ip[ip.size() - 1] == ':') ip = ip.substr(0, ip.size() - 1);
        vector<string> v(9, "");
        int pos = 0;
        for(int i = 0; i < ip.size(); i++){
            if(pos>7) return false;
            if(ip[i]!=':') v[pos]+=ip[i];
            else{
                if(i+1<ip.size() && ip[i+1]==':') return false;
                pos++;
            }
        }
        for(int i = 0; i < 8; i++){
            if(v[i].size() > 4) return false;
            //if(v[i][0] == '0' && v[i].size() != 1) return false;
            //if(str2int(v[i]) > 255) return false;
        }
        return true;
    }
    */
    bool isIPv4(string IP)
    {
        string temp="";
        int count=0;
        int count1=0;
        for(int i=0;i<=IP.length();i++)
        {
            if(IP[i]!='.'&&IP[i]!='\0')
            {
                if(IP[i]<'0'||IP[i]>'9') return false;
                temp=temp+IP[i];
                count1++;
                if(count1>=4)//exclude£º¡°11111111111111111111111111111.0.1.1¡±£¬stoi("111111111111111111111") will report wrong
                    return false;
            }
            else
            {
               if(temp!=""&&stoi(temp)<256&&stoi(temp)>=0)//temp!="" in order to exclude "1..1.1.1"
               {
                   if(temp[0]=='0'&&temp.length()>1) return false;//exclude£º¡°1.00.1.1¡±
                   count++;
                   if(count==4) return i==IP.length();
               }
               else
                   return false;
               temp="";
               count1=0;
            }
        }
        return false;
    }
    bool isIPv6(string IP)
    {
        string temp="";
        int count=0;
        int count1=0;
        for(int i=0;i<=IP.length();i++)
        {
            if((IP[i]>='0'&&IP[i]<='9')||(IP[i]>='A'&&IP[i]<='F')||(IP[i]>='a'&&IP[i]<='f'))
            {
                count1++;
                if(count1>4) return false;
            }
            else if(IP[i]==':'||IP[i]=='\0')
            {
                if(count1==0) return false;//In order to exclude"1::1:1:1:1:1:1:1
                count++;
                count1=0;
                if(count==8) return i==IP.length();
            }
            else
                return false;

        }
        return false;
    }
    string validIPAddress(string IP) {
        //string s = "2001:0db8:85a3:0:0:8A2E:0370:7334:";
        //if(strcmp(IP.c_str(), s.c_str())==0 ) return "IPv6";
        if(isIPv4(IP)) return "IPv4";
        else if(isIPv6(IP)) return "IPv6";
        else return  "Neither";
    }
};
