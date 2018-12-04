

int main(){
    int n;
    unordered_map<int> m;
    vector<int> zhishu;
    for(int i=2;i<=n;i++){
        if(zhishu.size()==0){
            zhishu.push_back(i);
            m[i]++;
            continue;
        }
        while(true){
            for(auto z:zhishu){
                if(i%z==0){
                    m[z]++;
                    i/=z;
                    break;
                }
            }
            if(i==1) break;
        }
    }
    for(int i=n+2;m.size()>0;i++){
        while(true){
            for(auto mm:m){
                if(i%mm.first==0){
                    m[mm]
                }
            }
        }
    }
}
